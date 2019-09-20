#ifndef HEADER_H
#define HEADER_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"
#include "time.h"

#define DELAY 10;

//Type Defs

typedef struct duration {
	int minutes;
	int seconds;
} Duration;

typedef struct record {
	char artist[100];
	char album[100];
	char title[100];
	char genre[100];
	Duration length;
	int times_played;
	int rating;
} Record;

typedef struct node {
	struct node *pNext;
	struct node *pPrev;
	Record r;
} Node;


//*Function Headers*

//Linked List Functions
//Creates a new node ant initializes node pNext and pPrev to null and song to newSong
Node *makeNode(Record newRecord);
int insertAtEnd(Node **recordLibrary, Record newRecord);

//Option Functions
//Loads in all the records from the file and puts them into a doubly linked list
int load(Node **recordLibrary, FILE *infile);
//Re writtes playlist with the linked list's contents
void store(Node **recordLibrary);
//Displays contents of list according to user's selction between all and by artist
void display(Node **recordLibrary);
//Inserts a new node for a new set of data by the user
void insert(Node **recordLibrary);
//Deletes existing record from list
void deleter(Node **recordLibrary);
//Edits the contents/details of a record according to user input
void edit(Node **recordLibrary);
//Changes the rating (1-5) of a record according to user input
void rate(Node **recordLibrary);
//Plays through the playlist till the end is reached
void play(Node **recordLibrary);

//PA 3

void sort(Node **recordLibrary);
//Sorts based on user input
void sortArtist(Node **recordLibrary);
//Sorts based on artist
void sortAlbum(Node **recordLibrary);
//Sorts based on album
void sortRating(Node **recordLibrary);
//Sorts based on rating
void sortTimes(Node **recordLibrary);
//Sorts based on times played
void shuffle(Node **recordLibrary);
//Plays through list randomly
int contain(int arr[], int random, int length);
//helper for shuffle determining what order to play, makes sure no songs are repeated
//

//Basic Functions
//Outputs selections into console, prompts user, then returns option
int display_Menu();
//Runs specific option in program based on display menu
int music_Program(int option, Node **recordLibrary, FILE *infile);
//Checks if the typed last name matches any in the list
int checkLastName(Node *iterator, char *artist, int comma);
//Function version of iterator to visit and print all in list
void printList(Node **recordLibrary);
//Returns Node count of a list
int sizeOfList(Node **recordLibrary);
//checkLastName except seaches if titles are identical to user input
int checkSong(Node *iterator, char *song);
#endif