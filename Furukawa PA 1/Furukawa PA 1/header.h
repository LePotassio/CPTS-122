#ifndef HEADER_H
#define HEADER_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//#include "windows.h" //includes a sleep function
#include "time.h"

//Structs and Enums

typedef enum sleep {
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit {
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartrate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

//Function Headers

//prints out the full data of a select bi at specified line
void printBit(FitbitData data[], int num);
//Adds calories of all data and returns as double
double totalCalories(FitbitData data[]);
//Adds distance of all data and returns as double
double totalDistance(FitbitData data[]);
//adds floors of all data and returns as an int
int totalFloors(FitbitData data[]);
//adds all steps of data and returns as int
int totalSteps(FitbitData data[]);
//calculates average heartrate by totalinging all hr and dividing by 1440
double avgHeartRate(FitbitData data[]);
//finds the value of highest steps within the data
int maxSteps(FitbitData data[]);
//returns the total of the max range of poor sleep (1<) and uses output parameters to return the starting and ending minute
int maxPoorSleep(FitbitData data[], char **start, char **end);
#endif