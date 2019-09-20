#include "header.h"

//Function Definitions

void printBit(FitbitData data[], int num) {
	num -= 2;
	printf("Minutes: %s\nCalories: %lf\nDistance: %lf\nFloors: %d\nHeartrate: %d\nSteps: %d\nSleepLevel: %d\n", data[num].minute, data[num].calories, data[num].distance, data[num].floors, data[num].heartrate, data[num].steps, data[num].sleepLevel);
}

double totalCalories(FitbitData data[]) {
	double total = 0;
	for (int c = 0; c < 1440; ++c) {
		total += data[c].calories;
	}
	return total;
}

double totalDistance(FitbitData data[]) {
	double total = 0;
	for (int c = 0; c < 1440; ++c) {
		total += data[c].distance;
	}
	return total;
}

int totalFloors(FitbitData data[]) {
	int total = 0;
	for (int c = 0; c < 1440; ++c) {
		total += data[c].floors;
	}
	return total;
}

int totalSteps(FitbitData data[]) {
	int total = 0;
	for (int c = 0; c < 1440; ++c) {
		total += data[c].steps;
	}
	return total;
}

double avgHeartRate(FitbitData data[]) {
	double total = 0;
	for (int c = 0; c < 1440; ++c) {
		total += data[c].heartrate;
	}
	return total / 1440;
}

int maxSteps(FitbitData data[]) {
	int max = data[0].steps;
	for (int c = 1; c < 1440; ++c) {
		if (data[c].steps >= max) {
			max = data[c].steps;
		}
	}
	return max;
}

int maxPoorSleep(FitbitData data[], char **start, char **end) {
	int maxTotal = 0;
	int currentTotal = 0;
	int length = 0;

	for (int c = 0; c < 1440; ++c) {
		if (data[c].sleepLevel <= 1) {
			currentTotal = 0;
			length = 0;
		}
		else {
			currentTotal += data[c].sleepLevel;
			++length;
		}
		if (currentTotal > maxTotal) {
			maxTotal = currentTotal;
			*end = data[c].minute;
			//printf("%d - %d\n", c, length);
			*start = data[c + 1 - length].minute;
		}
	}
	return maxTotal;
}