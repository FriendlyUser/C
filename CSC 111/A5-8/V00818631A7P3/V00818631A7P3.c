/*
 *  Author:      David Li
 *  UVicID:      V00818631
 *  Date:        Oct 69, 2014
 *  Lecture:     Assignment 7
 *  File name:   V00818631A7P3.c
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
#define MAXSWAP (4)



void processFile(FILE* ifp, FILE* ofp, int seed) {
	char line[25];
	char word[25];
	printf("Begin process file\n");
    // your code goes here
	int rn1,rn2;
	int j;
	char tmp;

	while(!feof(ifp)) {

		fscanf(ifp,"%s",line);
		strcpy(word,line);

		if(strlen(line) > 3) {
			for(j=0; j<MAXSWAP; j++) {
				rn1 = rand() % (strlen(line) -2);
				rn2 = rand() % (strlen(line) -2);
				tmp = line[rn1 + 1];
				line[rn1 + 1] = line[rn2 + 1];
				line[rn2 + 1] = tmp;
			}
			if(strcmp(word,line) == 0) {
				tmp = line[1];
				line[1] = line[2];
				line[2] = tmp;
			}
		}

		if(!feof(ifp))
			fprintf(ofp,"%s ",line);

	}
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
	processFile(ifp, ofp,seed);
	fclose(ofp);
	fclose(ifp);
	printf("\nWe encoded Sherlock Holmes\n");
	return EXIT_SUCCESS;
} /*main*/
