#include "header.h"


//Function Declarations


//Linked List Functions
Node *makeNode(Record newRecord) {
	Node *pMem = NULL;
	pMem = (Node *)malloc(sizeof(Node));
	if (pMem != NULL) {
		pMem->pNext = NULL;
		pMem->pPrev = NULL;
		pMem->r = newRecord;
	}
	return pMem;
}

int insertAtEnd(Node **recordLibrary, Record newRecord) {//This is actually insertAtFront
	if (*recordLibrary == NULL) {
		Node *newNode = NULL;
		newNode = makeNode(newRecord);
		*recordLibrary = newNode;
		return 1;
	}
	else {
		Node *newNode = NULL;
		newNode = makeNode(newRecord);
		if (newNode != NULL) {
			newNode->pNext = *recordLibrary;
			(*recordLibrary)->pPrev = newNode;
			*recordLibrary = newNode;
			return 1;
		}
	}
	return 0;
}


//Option Functions
int load(Node **recordLibrary, FILE *infile) {
	while (!feof(infile)) {
		Record newRecord = { "\0", "\0", "\0", "\0", {0, 0 }, 0, 0};
		char lineRecord[200] = " ";
		fgets(lineRecord, 200, infile);
		if (strcmp(lineRecord, " ") != 0) {
			//artist
			if (lineRecord[0] != 34) {
				strcpy(newRecord.artist, strtok(lineRecord, ","));
			}
			else {
				char artistComma[50] = "";
				strcpy(artistComma, strtok(lineRecord, ","));
				strcat(artistComma, ",");
				strcat(artistComma, strtok(NULL, ","));
				strcpy(newRecord.artist, artistComma);
			}
			//album
			strcpy(newRecord.album, strtok(NULL, ","));
			//title
			strcpy(newRecord.title, strtok(NULL, ","));
			//genre
			strcpy(newRecord.genre, strtok(NULL, ","));
			//minutes
			newRecord.length.minutes = atoi(strtok(NULL, ":"));
			//seconds
			newRecord.length.seconds = atoi(strtok(NULL, ","));
			//times played
			newRecord.times_played = atoi(strtok(NULL, ","));
			//rating
			newRecord.rating = atoi(strtok(NULL, ","));

			
			insertAtEnd(recordLibrary, newRecord);
		}
	}
}

void store(Node **recordLibrary) {
	FILE *outfile = fopen("musicPlayList.csv", "w");
	Node *iterator = *recordLibrary;
	while (iterator->pNext != NULL) {
		//fprintf(outfile, "%s,%s,%s,%s,%d:%d,%d,%d\n", iterator->r.artist, iterator->r.album, iterator->r.title, iterator->r.genre, iterator->r.length.minutes, iterator->r.length.seconds, iterator->r.times_played, iterator->r.rating);
		iterator = iterator->pNext;
	}
	while (iterator != NULL) {
		fprintf(outfile, "%s,%s,%s,%s,%d:%d,%d,%d\n", iterator->r.artist, iterator->r.album, iterator->r.title, iterator->r.genre, iterator->r.length.minutes, iterator->r.length.seconds, iterator->r.times_played, iterator->r.rating);
		iterator = iterator->pPrev;
	}
	fclose(outfile);
}

void display(Node **recordLibrary) {
	int option = 0;
	do {
		printf("Would you like to:\n(1)Display all\n(2)Display all by one artist\n");
		scanf("%d", &option);
		system("cls");
	} while (option != 1 && option != 2);

	if (option == 1) {
		//Display all
		printList(recordLibrary);
	}
	else {
		//Display all of one artist
		char artist[50] = " ";
		printf("Please type the exact name of artist (LastName only if it is a double name, Name if it is a single name\n(Case sensitive))\n");
		scanf("%s", &artist);
		Node *iterator = *recordLibrary;
		int found = 0;
		while (iterator->pNext != NULL) {
			iterator = iterator->pNext;
		}
		while (iterator != NULL) {
			if (checkLastName(iterator, artist, 0)  || checkLastName(iterator, artist, 1)) {//could use string compare for no auto fill/smart search on single name
				found = 1;
				printf("%s,%s,%s,%s,%d:%d,%d,%d\n", iterator->r.artist, iterator->r.album, iterator->r.title, iterator->r.genre, iterator->r.length.minutes, iterator->r.length.seconds, iterator->r.times_played, iterator->r.rating);
			}
			iterator = iterator->pPrev;
		}
		if (found == 0) {
			printf("No results found\n");
		}
	}
}

void insert(Node **recordLibrary) {
	Record newRecord = { "\0", "\0", "\0", "\0",{ 0, 0 }, 0, 0 };
	printf("Please enter a new Artist (See TEMP for Formating): ");
	scanf("%s", &newRecord.artist);
	printf("Please enter a new Album: ");
	scanf("%s", &newRecord.album);
	printf("Please enter a new Title: ");
	scanf("%s", &newRecord.title);
	printf("Please enter a new Genre: ");
	scanf("%s", &newRecord.genre);
	printf("Please enter a new Minute duration: ");
	scanf("%d", &newRecord.length.minutes);
	printf("Please enter a new Second duration: ");
	scanf("%d", &newRecord.length.seconds);
	printf("Please enter a new Initial Times played: ");
	scanf("%d", &newRecord.times_played);
	int rating = 0;
	do {
		printf("Please enter a new Rating(1-5): ");
		scanf("%d", &rating);
	} while (rating < 1 || rating > 5);
	newRecord.rating = rating;

	insertAtEnd(recordLibrary, newRecord);
}

void deleter(Node **recordLibrary) {
	printList(recordLibrary);
	int deletePos = 0;
	do {
		printf("Which would you like to delete(number)?: ");
		scanf("%d", &deletePos);
	} while (deletePos < 1 || deletePos > sizeOfList(recordLibrary));
	Node *iterator = *recordLibrary;
	while (iterator->pNext != NULL) {
		iterator = iterator->pNext;
	}
	for (int c = 0; c < deletePos - 1; ++c) {
		iterator = iterator->pPrev;
	}

	//*Delete*

	//gen case (need delete front and delete end and delete only one)
	if (sizeOfList(recordLibrary) == 1) {
		(*recordLibrary) = NULL;
		free(iterator);
	}
	else if (deletePos == 1) {
		iterator->pPrev->pNext = NULL;
		free(iterator);
	}
	else if(sizeOfList(recordLibrary) == deletePos) {
		*recordLibrary = iterator->pNext;
		//printf("%s",iterator->r.title);
		//printf("%s",iterator->pNext->r.title);
		iterator->pNext->pPrev = NULL;
		free(iterator);
	}
	else {
		iterator->pNext->pPrev = iterator->pPrev;
		iterator->pPrev->pNext = iterator->pNext;
		free(iterator);
	}
}

void edit(Node **recordLibrary) {
	char artist[50] = " ";
	printList(recordLibrary);
	printf("Please type the exact name of artist (LastName only if it is a double name, Name if it is a single name\n(Case sensitive))\n");
	scanf("%s", &artist);
	system("cls");
	Node *iterator = *recordLibrary;
	while (iterator->pNext != NULL) {
		iterator = iterator->pNext;
	}
	int count = 0;
	int found = 0;
	while (iterator != NULL) {
		++count;
		if (checkLastName(iterator, artist, 0) || checkLastName(iterator, artist, 1)) {//could use string compare for no auto fill/smart search on single name
			found = 1;
			printf("(%d)", count);
			printf("%s,%s,%s,%s,%d:%d,%d,%d\n", iterator->r.artist, iterator->r.album, iterator->r.title, iterator->r.genre, iterator->r.length.minutes, iterator->r.length.seconds, iterator->r.times_played, iterator->r.rating);
		}
		iterator = iterator->pPrev;
	}
	if (found == 1) {
		int editPos = 0;
		do {
			printf("Which would you like to edit(number)?: ");
			scanf("%d", &editPos);
		} while (editPos < 1 || editPos > sizeOfList(recordLibrary));
		iterator = *recordLibrary;
		while (iterator->pNext != NULL) {
			iterator = iterator->pNext;
		}
		for (int c = 0; c < editPos - 1; ++c) {
			iterator = iterator->pPrev;
		}
		char artistIn[50] = " ";
		gets(artistIn);//cheap flush?
		printf("Please enter a new Artist (See TEMP for Formating): ");
		fgets(artistIn, 50, stdin);
		//int c = 0;
		/*
		while(artistIn[c] != '\0') {
			printf("a");
			if (artistIn[c] == 12) {
				artistIn[c] == '\0';
			}
			++c;
		}
		*/
		artistIn[strlen(artistIn) - 1] = '\0';
		strcpy(iterator->r.artist, artistIn);

		char albumIn[50] = " ";
		printf("Please enter a new Album: ");
		fgets(albumIn, 50, stdin);
		albumIn[strlen(albumIn) - 1] = '\0';
		strcpy(iterator->r.album, albumIn);

		char titleIn[50] = " ";
		printf("Please enter a new Title: ");
		fgets(titleIn, 50, stdin);
		titleIn[strlen(titleIn) - 1] = '\0';
		strcpy(iterator->r.title, titleIn);

		char genreIn[50] = " ";
		printf("Please enter a new Genre: ");
		fgets(genreIn, 50, stdin);
		genreIn[strlen(genreIn) - 1] = '\0';
		strcpy(iterator->r.genre, genreIn);

		printf("Please enter a new Minute duration: ");
		scanf("%d", &iterator->r.length.minutes);

		printf("Please enter a new Second duration: ");
		scanf("%d", &iterator->r.length.seconds);

		printf("Please enter a new Initial Times played: ");
		scanf("%d", &iterator->r.times_played);

		int rating = 0;
		do {
			printf("Please enter a new Rating(1-5): ");
			scanf("%d", &rating);
		} while (rating < 1 || rating > 5);
		iterator->r.rating = rating;
	}
	else {
		printf("No results found\n");
	}
}

void rate(Node **recordLibrary) {
	char artist[50] = " ";
	printList(recordLibrary);
	printf("Please type the exact name of artist (LastName only if it is a double name, Name if it is a single name\n(Case sensitive))\n");
	scanf("%s", &artist);
	system("cls");
	Node *iterator = *recordLibrary;
	while (iterator->pNext != NULL) {
		iterator = iterator->pNext;
	}
	int count = 0;
	int found = 0;
	while (iterator != NULL) {
		++count;
		if (checkLastName(iterator, artist, 0) || checkLastName(iterator, artist, 1)) {//could use string compare for no auto fill/smart search on single name
			found = 1;
			printf("(%d)", count);
			printf("%s,%s,%s,%s,%d:%d,%d,%d\n", iterator->r.artist, iterator->r.album, iterator->r.title, iterator->r.genre, iterator->r.length.minutes, iterator->r.length.seconds, iterator->r.times_played, iterator->r.rating);
		}
		iterator = iterator->pPrev;
	}
	if (found == 1) {
		int editPos = 0;
		do {
			printf("Which would you like to rate(number)?: ");
			scanf("%d", &editPos);
		} while (editPos < 1 || editPos > sizeOfList(recordLibrary));
		iterator = *recordLibrary;
		while (iterator->pNext != NULL) {
			iterator = iterator->pNext;
		}
		for (int c = 0; c < editPos - 1; ++c) {
			iterator = iterator->pPrev;
		}

		int rating = 0;
		do {
			printf("Please enter a new Rating(1-5): ");
			scanf("%d", &rating);
		} while (rating < 1 || rating > 5);
		iterator->r.rating = rating;
	}
	else {
		printf("No results found\n");
	}
}

void play(Node **recordLibrary) {
	char song[50] = " ";
	printList(recordLibrary);
	printf("Please type the exact name of Song (Case and Space sensitive)\n");
	fgets(song, 50, stdin);
	fgets(song, 50, stdin);
	song[strlen(song) - 1] = '\0';
	system("cls");
	Node *iterator = *recordLibrary;
	int found = 0;
	int count = 0;
	while (iterator->pNext != NULL) {
		iterator = iterator->pNext;
	}
	while (iterator != NULL) {
		++count;
		if (checkSong(iterator, song)) {
			printf("(%d)", count);
			found = 1;
			printf("%s,%s,%s,%s,%d:%d,%d,%d\n", iterator->r.artist, iterator->r.album, iterator->r.title, iterator->r.genre, iterator->r.length.minutes, iterator->r.length.seconds, iterator->r.times_played, iterator->r.rating);
		}
		iterator = iterator->pPrev;
	}
	if (found == 1) {

		int startPos = 0;
		do {
			printf("Which would you like to start on(number)?: ");
			scanf("%d", &startPos);
		} while (startPos < 1 || startPos > sizeOfList(recordLibrary));
		Node *iterator = *recordLibrary;
		while (iterator->pNext != NULL) {
			iterator = iterator->pNext;
		}
		for (int c = 0; c < startPos - 1; ++c) {
			iterator = iterator->pPrev;
		}
		system("cls");
		while (iterator != NULL) {
			iterator->r.times_played += 1;
			printf("Artist: %s\nAlbum: %s\nTitle: %s\nGenre: %s\nDuration: %d:%d\nTimes Played: %d\nRating: %d\n", iterator->r.artist, iterator->r.album, iterator->r.title, iterator->r.genre, iterator->r.length.minutes, iterator->r.length.seconds, iterator->r.times_played, iterator->r.rating);
			iterator = iterator->pPrev;
			Sleep(3000);
			system("cls");
		}
	}
	else {
		printf("No results found\n");
	}
}

//Basic Functions
int display_Menu(void) {
	int option = 0;
	do {
		printf("Welcome to the Music Program\n\n(1) Load\n(2) Store\n(3) Display\n");
		printf("(4) Insert\n(5) Delete\n(6) Edit\n(7) Sort\n(8) Rate\n(9) Play\n(10) Shuffle\n(11) Exit\n");
		printf("Your Numeric Selection: ");
		printf("Your Numeric Selection: ");
		scanf("%d", &option);
		system("cls");
	} while (option < 1 || option > 11);
	return option;
}

int music_Program(int option, Node **recordLibrary, FILE *infile) {
	int delay = DELAY;
	switch (option) {
	case 1:
		printf("Loader Initialized\n");
		Sleep(delay);
		load(recordLibrary, infile);
		break;
	case 2:
		printf("Storer Initialized\n");
		Sleep(delay);
		if (*recordLibrary != NULL) {
			store(recordLibrary);
		}
		else {
			printf("List is empty! Please Load First\n");
		}
		break;
	case 3:
		printf("Displayer Initialized\n");
		Sleep(delay);
		if (*recordLibrary != NULL) {
			display(recordLibrary);
		}
		else {
			printf("List is empty! Please Load First\n");
		}
		break;
	case 4:
		printf("Inserter Initialized\n");//no protection so it can insert with empty list
		Sleep(delay);
		insert(recordLibrary);
		printf("List is empty! Please Load First\n");
		break;
	case 5:
		printf("Deleter Initialized\n");
		Sleep(delay);
		if (*recordLibrary != NULL) {
			deleter(recordLibrary);
		}
		else {
			printf("List is empty! Please Load First\n");
		}
		break;
	case 6:
		printf("Editor Initialized\n");
		Sleep(delay);
		if (*recordLibrary != NULL) {
			edit(recordLibrary);
		}
		else {
			printf("List is empty! Please Load First\n");
		}
		break;
	case 7:
		printf("Sorter Initialized\n");
		Sleep(delay);
		if (*recordLibrary != NULL) {
			sort(recordLibrary);
		}
		else {
			printf("List is empty! Please Load First\n");
		}
		break;
	case 8:
		printf("Rater Initialized\n");
		Sleep(delay);
		if (*recordLibrary != NULL) {
			rate(recordLibrary);
		}
		else {
			printf("List is empty! Please Load First\n");
		}
		break;
	case 9:
		printf("Player Initialized\n");
		Sleep(delay);
		if (*recordLibrary != NULL) {
			play(recordLibrary);
		}
		else {
			printf("List is empty! Please Load First\n");
		}
		break;
	case 10:
		printf("Shuffler Initialized\n");
		Sleep(delay);
		if (*recordLibrary != NULL) {
			shuffle(recordLibrary);
		}
		else {
			printf("List is empty! Please Load First\n");
		}
		break;
	case 11:
		store(recordLibrary);
		return 1;
		break;
	}
	return 0;
}

int checkLastName(Node *iterator, char *artist, int comma) {
	int length = strlen(artist);
	int match = 1;
	for (int c = 0; c < length; ++c) {
		if (artist[c] != iterator->r.artist[c + comma]) {
			match = 0;
			break;
		}
	}
	return match;
}

void printList(Node **recordLibrary) {
	Node *iterator = *recordLibrary;
	while (iterator->pNext != NULL) {
		iterator = iterator->pNext;
	}
	int count = 1;
	while (iterator != NULL) {
		printf("(%d)", count);
		printf("%s,%s,%s,%s,%d:%d,%d,%d\n", iterator->r.artist, iterator->r.album, iterator->r.title, iterator->r.genre, iterator->r.length.minutes, iterator->r.length.seconds, iterator->r.times_played, iterator->r.rating);
		iterator = iterator->pPrev;
		++count;
	}
}

int sizeOfList(Node **recordLibrary) {
	int size = 0;
	Node *iterator = *recordLibrary;
	while (iterator != NULL) {
		iterator = iterator->pNext;
		++size;
	}
	return size;
}

int checkSong(Node *iterator, char *song) {
	//printf("%s", iterator->r.title);
	int length = strlen(song);
	int match = 1;
	for (int c = 0; c < length; ++c) {
		if (song[c] != iterator->r.title[c]) {
			match = 0;
			break;
		}
	}
	return match;
}




//PA 3
void sort(Node **recordLibrary) {
	int option = 0;
	do {
		printf("Which way would you like to sort by?\n(1) Artist\n(2) Album\n(3) Rating\n(4) Times Played\n\nSelection:");
		scanf("%d", &option);
	} while(option > 4 || option < 1);
	switch (option) {
	case 1:
		sortArtist(recordLibrary);
		break;
	case 2:
		sortAlbum(recordLibrary);
		break;
	case 3:
		sortRating(recordLibrary);
		break;
	case 4:
		sortTimes(recordLibrary);
		break;
	}
}

void sortArtist(Node **recordLibrary) {
	Node *iterator1 = *recordLibrary;
	Node *iterator2 = *recordLibrary;
	Record temp;
	int length = sizeOfList(recordLibrary);
	for (int i = 0; i < length; ++i) {
		//iterator2 = iterator1;
		while (iterator2->pNext != NULL) {
			char art1[100] = "";
			char art2[100] = "";
			char *tempArtist = (char *) malloc(100);
			char *tempArtist2 = (char *) malloc(100);
			strcpy(art1, iterator2->r.artist);
			strcpy(art2, iterator2->pNext->r.artist);
			strcpy(tempArtist, art1);
			strcpy(tempArtist2, art2);
			if (iterator2->r.artist[0] == '\"') {
				tempArtist = strtok(art1, "\"");
				//strcpy(tempArtist, strtok(NULL, "\""));
			}
			if (iterator2->pNext->r.artist[0] == '\"') {
				tempArtist2 = strtok(art2, "\"");
			}
			if (strcmp(tempArtist, tempArtist2) <= 0) {
				//swap
				temp = iterator2->r;
				iterator2->r = iterator2->pNext->r;
				iterator2->pNext->r = temp;
			}
			iterator2 = iterator2->pNext;
		}
		iterator2 = iterator1;
	}
}

void sortAlbum(Node **recordLibrary) {
	Node *iterator1 = *recordLibrary;
	Node *iterator2 = *recordLibrary;
	Record temp;
	int length = sizeOfList(recordLibrary);
	for (int i = 0; i < length; ++i) {
		//iterator2 = iterator1;
		while (iterator2->pNext != NULL) {
			if (strcmp(iterator2->r.album, iterator2->pNext->r.album) <= 0) {
				//swap
				temp = iterator2->r;
				iterator2->r = iterator2->pNext->r;
				iterator2->pNext->r = temp;
			}
			iterator2 = iterator2->pNext;
		}
		iterator2 = iterator1;
	}
}

void sortRating(Node **recordLibrary) {
	Node *iterator1 = *recordLibrary;
	Node *iterator2 = *recordLibrary;
	Record temp;
	int length = sizeOfList(recordLibrary);
	for (int i = 0; i < length; ++i) {
		//iterator2 = iterator1;
		while (iterator2->pNext != NULL) {
			if (iterator2->r.rating >= iterator2->pNext->r.rating) {
				//swap
				temp = iterator2->r;
				iterator2->r = iterator2->pNext->r;
				iterator2->pNext->r = temp;
			}
			iterator2 = iterator2->pNext;
		}
		iterator2 = iterator1;
	}
}

void sortTimes(Node **recordLibrary) {
	Node *iterator1 = *recordLibrary;
	Node *iterator2 = *recordLibrary;
	Record temp;
	int length = sizeOfList(recordLibrary);
	for (int i = 0; i < length; ++i) {
		//iterator2 = iterator1;
		while (iterator2->pNext != NULL) {
			if (iterator2->r.times_played >= iterator2->pNext->r.times_played) {
				//swap
				temp = iterator2->r;
				iterator2->r = iterator2->pNext->r;
				iterator2->pNext->r = temp;
			}
			iterator2 = iterator2->pNext;
		}
		iterator2 = iterator1;
	}
}

void shuffle(Node **recordLibrary) {
	int length = sizeOfList(recordLibrary);
	int arr[100] = {0};
	for (int q = 0; q < 100; ++q) {
		arr[q] = -1;
	}
	time_t t;

	srand((unsigned)time(&t));
	int random = 0;

	for (int c = 0; c < length; ++c) {
		while (contain(arr, random, length)) {
			random = rand() % length;
		}
		arr[c] = random;
	}

	//Shuffle play
	Node *iterator = *recordLibrary;
	int curPos = 0;
	for (int d = 0; d < length; ++d) {
		int pos = arr[d];
		while (curPos != pos) {
			if (curPos < pos) {
				iterator = iterator->pNext;
				++curPos;
			}
			else {
				iterator = iterator->pPrev;
				--curPos;
			}
		}
		printf("Artist: %s\nAlbum: %s\nTitle: %s\nGenre: %s\nDuration: %d:%d\nTimes Played: %d\nRating: %d\n", iterator->r.artist, iterator->r.album, iterator->r.title, iterator->r.genre, iterator->r.length.minutes, iterator->r.length.seconds, iterator->r.times_played, iterator->r.rating);
		Sleep(2500);
		system("cls");
	}
}

int contain(int arr[], int random, int length) {
	for (int c = 0; c < length; ++c) {
		if (arr[c] == random) {
			return 1;
		}
	}
	return 0;
}