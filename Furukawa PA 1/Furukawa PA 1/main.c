#include "header.h"

/*
Eric Furukawa
1/22/18
PA 1
DESC: Fit bit data processor which reads in and tokenizes data into an array of structs, later calculates and outputs data on input into
console and outfile
NOTES/KNOWN ISSUES/QUESTIONS:
-Yes, lots of it is in main
-Had to replace !feof()infile while loop with set in stone 1440 for loop
-Added weird if token is equal to null to try to solve blank space problem but used different solution and didn't remove
-Shifts 50 for movement, lucky guess + reliant on 100 size array?
*/

int main(void) {
	FitbitData data[1440] = { {"\0", 0, 0, 0, 0, 0} };

	FILE *infile = fopen("FitbitData.csv", "r");

	//read in
	if (infile != NULL) {

		char str[100] = " ";
		fgets(str, 100, infile);
		for (int q = 0; q < 100; ++q) {
			str[q] = '\0';
		}
		int dataNum = 0;
		//int tester = 2;
			//while (!feof(infile)) {
		for (int g = 0; g < 1440; ++g) {//switched to hard coded 1440 instead of !feof(infile) as it wasn't working
				//printf("%d\n", tester);
				//tester++;
				fgets(str, 100, infile);

				int comma = 0;
				for (int d = 0; d < 100; ++d) {
					if (str[d] == ',' && comma == 1) {
						comma = 0;
						//insert
						char temp = '\0';
						char temp2 = '\0';
						int first = 1;
						for (int e = d; e < 50; ++e) {//Shifts 50 over, another hard coded as strlen didn't work
							temp2 = temp;
							temp = str[e];
							if (first) {
								first = 0;
								str[e] = '0';
							}
							else {
								str[e] = temp2;
							}
							
						}
					}
					else if (str[d] == ',') {
						comma = 1;
					}
					else {
						comma = 0;
					}
				}

				//Read ins and parses could have been put into functions
				//Also ignore the whole if "thing" is "\0" as i found a different work around

				//minutes
				strcpy(data[dataNum].minute, strtok(str, ","));
				//calories
				char *calories = strtok(NULL, ",");
				if (calories != "\0") {
					data[dataNum].calories = atof(calories);
				}
				else {
					data[dataNum].calories = 0;
				}
				//distance
				char *distance = strtok(NULL, ",");
				if (distance != "") {
					data[dataNum].distance = atof(distance);
				}
				else {
					data[dataNum].distance = 0;
				}
				//floors
				char *floors = strtok(NULL, ",");
				if (floors != "\0") {
					data[dataNum].floors = atoi(floors);
				}
				else {
					data[dataNum].floors = 0;
				}
				//heartrate
				char *heartrate = strtok(NULL, ",");
				if (heartrate != "\0") {
					data[dataNum].heartrate = atoi(heartrate);
				}
				else {
					data[dataNum].heartrate = 0;
				}
				//steps
				char *steps = strtok(NULL, ",");
				if (steps != "\0") {
					data[dataNum].steps = atoi(steps);
				}
				else {
					data[dataNum].steps = 0;
				}
				//sleep
				char *sleepP = strtok(NULL, ",");
				if (sleepP != "\0") {
					data[dataNum].sleepLevel = atoi(sleepP);
				}
				else {
					data[dataNum].sleepLevel = 0;
				}

				++dataNum;
			}


			//printBit(data, 2);

		FILE *outfile = fopen("results.csv", "w");

		char *end = 0;
		char *start = 0;
		maxPoorSleep(data, &start, &end);

		printf("Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");
		printf("%lf, %lf, %d, %d, %lf, %d, %s - %s\n", totalCalories(data), totalDistance(data), totalFloors(data), totalSteps(data), avgHeartRate(data), maxSteps(data), start, end);


		fprintf(outfile, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");
		fprintf(outfile, "%lf, %lf, %d, %d, %lf, %d, %s - %s\n", totalCalories(data), totalDistance(data), totalFloors(data), totalSteps(data), avgHeartRate(data), maxSteps(data), start, end);
		fclose(infile);
		fclose(outfile);
	}
}