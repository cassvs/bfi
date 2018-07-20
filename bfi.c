#include <stdio.h>
#include <stdlib.h>

int isPrint(char c) {
	//Determine if a character is printable
  return ((c < 32) || (c == 127)) ? 0 : 1;
}

int strIncChar(char* str, int len, int chr) {
	//Increment the specified character of a string,
	//skipping non-printables.
	//If the character rolls over, increment the next one too.
	if (chr >= len) {
		//Trying to increment a charater off the end of the string.
		fprintf(stderr, "Off the end of string\n");
		return 0;
	}
	char prevChr = str[chr];
	for (str[chr]++; !isPrint(str[chr]); str[chr]++) {};
	if ((str[chr] <= 32) && (prevChr != 0)) {
		return strIncChar(str, len, chr + 1);
	}
	return 1;
}

int main(int argc, char** argv) {
	int stringLength = 11;
	char *testString = malloc(stringLength);
	if (testString == NULL) {
		fprintf(stderr, "Malloc failure!\n");
		exit(-1);
	}
	for (int i = 0; i < stringLength; i++) {
		testString[i] = '\0';
	}
	while (strIncChar(testString, stringLength, 0)) {
		printf("%s\n", testString);
	}
	exit(0);
}
