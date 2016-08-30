/*
 *  Author:      Hausi A. Muller
 *  UVicID:      V00123456
 *  Date:        Oct 13, 2014
 *  Lecture:     Assignment 7
 *  File name:   A7_2014_P3_Template.c
 *  Description: Reading, writing, and encoding files
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define INPUTFILENAME    ("A7_2014_P3_TestingSherlock.txt")
#define OUTPUTFILENAME   ("A7_2014_P3_SherlockEncoded.txt")

void processFile(FILE* ifp, FILE* ofp) {
	printf("Begin process file\n");
    // your code goes here
	printf("End process file\n");
} /* ProcessFile */

int main(void) {
	printf("Welcome to Sherlock Holmes\n\n");
	unsigned int seed = (unsigned int)time(NULL);
	srand(seed);
	FILE *ifp;
	FILE *ofp;
	ifp = fopen(INPUTFILENAME, "r");
	if (ifp == NULL) {
		printf("Cannot open input file %s\n", INPUTFILENAME);
		exit(EXIT_FAILURE);
	} /*if*/
	ofp = fopen(OUTPUTFILENAME, "w");
	if (ofp == NULL) {
		printf("Cannot create output file %s\n", OUTPUTFILENAME);
		exit(EXIT_FAILURE);
	} /*if*/
	processFile(ifp, ofp);
	fclose(ofp);
	fclose(ifp);
	printf("\nWe encoded Sherlock Holmes\n");
	return EXIT_SUCCESS;
} /*main*/
