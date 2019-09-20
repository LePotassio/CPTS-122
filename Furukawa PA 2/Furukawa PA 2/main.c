#include "header.h"

/*
Eric Furukawa
PA 03
Section 3
Desc : Music library simulator to show our uses of doubly linked lists and their manipulation. Also uses in and outfile manipulation fromm the last PA.

Known Issues:
None?

Known Issues (OLD):
-had to psuedo flush in egit for fgets to work
-case sensitivity
-actual list is backwards, prints backwards to counter this
-autofill sorta dealio for seaching by artist
-foward and back iteration sort of unnessicary for some
-search by artist still asks for which even if no search results are found
-\n cut offs for fgets

-Sort and Shuffle to be added next PA
*/

int main(void) {
	Node *record_Library = NULL;
	FILE *infile = fopen("musicPlayList.csv", "r");
	//FILE *outfile = NULL;//fopen("musicPlayList.csv", "w");
	/*
	char lineRecord[100] = " ";
	fgets(lineRecord, 100, infile);
	printf("line %s\n", lineRecord);
	*/
	int quit = 0;
	do {
		quit = music_Program(display_Menu(), &record_Library, infile);
	} while (quit == 0);
	fclose(infile);
}