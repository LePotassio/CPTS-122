#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void swap(char a[], int count);
char *mystrtok(char *b, char delimeter);
char *merge1(char *arr1, char *arr2);

int main(void) {
	/*
	char a[] = "hello";
	swap(a, 0);
	printf("%s\n", a);
	///////////////////////////////
	char b[] = "hey,world";
	char *address;
	address = mystrtok(b, ',');
	printf("%s\n%s\n", b, address);

	address = mystrtok(NULL, ',');
	printf("%s\n%s\n", b, address);
	*/
	char *c = "A string";
	char *d = "A sentence";
	char *result = merge1(c, d);
	printf("%s\n", result);
}


void swap(char a[], int count) {
	int len = strlen(a) - 1;
	if (count < (len/ 2)) {
		char temp = a[count];
		a[count] = a[len - count];
		a[len - count] = temp;
		swap(a, count + 1);
	}
}

char *mystrtok(char *b, char delimeter) {
	static int count = 0;
	int start = count;
	int success = 0;
	static char *str;
	if (b != NULL) {
		str = b;
		count = 0;
	}
	while (str[count] != '\0') {
		if (str[count] == delimeter) {
			str[count] = '\0';
			count++;
			success = 1;
			break;
		}
		count++;
	}
	if (success || str[count] == '\0') {
		return str + start;
	}
	return NULL;
}

char *merge1(char *arr1, char *arr2) {
	char *result = " ";

	strcpy(result, arr1);
	strcat(result, arr2);

	for (int c = 0; c < strlen(result) - 1; c++) {
		for (int d = c; d < strlen(result) - 1; d++) {
			if (result[d] > result[d + 1]) {
				char temp = result[d];
				result[d] = result[d + 1];
				result[d + 1] = temp;
			}
		}
	}
	return result;
}