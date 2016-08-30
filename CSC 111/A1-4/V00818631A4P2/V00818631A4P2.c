
/*
*  Author:      David Li
*  UVicID:      V00818631
*  Date:        Oct 8, 2014
*  Lecture:     Assignment 4
*  File name:   V00818631A4P2.c
*  Description: Generates random numbers
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILENAME ("myrandom.txt")

//define the constants
#define NO_SHAPES 10

#define X_RANGE 800
#define Y_RANGE 400
#define SHAPE_RANGE 4
#define WIDTH_RANGE 80
#define HEIGHT_RANGE 40
#define RED_RANGE 256
#define GREEN_RANGE 256
#define BLUE_RANGE 256
#define OPACITY_RANGE 100

//do the random thing
int createRandNum(num,seed) {
	int rn = 0;
	rn = rand() % num;
	return rn;
}

float createRandFloat(fnum,seed){
	float rn = 0;
	rn = rand()% fnum;
	return rn;
}

int main(void) {

	FILE* ofp = NULL;
	printf("We are about to create a file called %s for writing into it\n", FILENAME);
	ofp = fopen(FILENAME, "w");

	if (ofp == NULL) {
		printf("Cannot open output file %s\n", FILENAME);
		exit(EXIT_FAILURE);  // exit() is defined in <stdlib.h>
	} /* if */

	fprintf(ofp,"Table of random number for drawing geometric shapes in different colours, sizes and opacities\n");
	fprintf(ofp,"%10s %8s %5s %5s %9s %10s %7s %9s %8s %12s\n","shape#","RSCE","x","y","width","height","red","green","blue","opacity");

	//declare loop variable

	//declare variables
	int RSCE,x,y,width,height,red,green,blue;

	//seed the generator
	unsigned int seed = (unsigned int)time(NULL);
	srand(seed);

	int k = 5;
	float opacity;
	for(k=0;  k<NO_SHAPES; k++) {
		//print the shape number
		fprintf(ofp,"%10d",k);

		//call createRandNum to create random numbers
		RSCE = createRandNum(SHAPE_RANGE,seed);
		x = createRandNum(X_RANGE,seed);
		y = createRandNum(Y_RANGE,seed);
		width = createRandNum(WIDTH_RANGE,seed);
		height = createRandNum(HEIGHT_RANGE,seed);
		red = createRandNum(RED_RANGE,seed);
		green = createRandNum(GREEN_RANGE,seed);
		blue = createRandNum(BLUE_RANGE,seed);
		opacity = createRandFloat(OPACITY_RANGE,seed)/100;
		//print the values in table format
		fprintf(ofp,"%9d %6d %5d %7d %9d %10d %7d %9d %10.2f\n",RSCE,x,y,width,height,red,green,blue,opacity);

	}

	printf("We created the file %s successfully for writing\n", FILENAME);
	printf("We wrote HTML5 code into the file %s successfully\n", FILENAME);
	fclose(ofp);
	printf("We closed the file %s successfully\n", FILENAME);
	return EXIT_SUCCESS;
} /*main*/
