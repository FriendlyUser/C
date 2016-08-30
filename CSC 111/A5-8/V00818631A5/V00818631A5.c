
/*
*  Author:      David Li
*  UVicID:      V00818631
*  Date:        Oct 8, 2014
*  Lecture:     Assignment 5
*  File name:   V00818631A5.c
*  Description: Output a greeting card
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define FILENAME ("mycsc111art.html")

//define the constants
#define NO_SHAPES 1500

#define X_RANGE 800
#define Y_RANGE 400
#define SHAPE_RANGE 4
#define WIDTH_RANGE 80
#define HEIGHT_RANGE 40
#define RED_RANGE 256
#define GREEN_RANGE 256
#define BLUE_RANGE 256
#define OPACITY_RANGE 100

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

void circle(FILE* ofp, int x,int y,int r, int red, int green, int blue, float opacity) {
	//create circles
	fprintf(ofp,"\t\t\t<circle cx =\"%d\"  cy =\"%d\"  r =\"%d\"  style =\"fill:rgb(%d,%d,%d); fill-opacity:%f\"/>\n",x,y,r,red,green,blue,opacity);
}

void rectangle(FILE* ofp,int x, int y, int width, int height, int red, int green, int blue, float opacity) {
	//create rectangles and squares
	fprintf(ofp,"\t\t\t<rect x =\"%d\"  y =\"%d\"  width =\"%d\" height = \"%d\" style =\"fill:rgb(%d,%d,%d); fill-opacity:%f\"/>\n",x,y,width,height,red,green,blue,opacity);
}

void ellipse(FILE* ofp,int x, int y, int rx, int ry, int red, int green, int blue, float opacity) {
	//create ellipses
	fprintf(ofp,"\t\t\t<ellipse cx =\"%d\"  cy =\"%d\"  rx =\"%d\" ry = \"%d\" style =\"fill:rgb(%d,%d,%d); fill-opacity:%f\"/>\n",x,y,rx,ry,red,green,blue,opacity);
}

void frame(FILE* ofp){

	//FILE* xD = NULL;
	//xD = fopen(FILENAME, "a+");
	fprintf(ofp,"\t\t\t<rect x =\"0\" y = \"0\" width =\"500\" height =\"300\" style =\"fill: none; stroke-width: 10; stroke:rgb(255,51,153); stroke-opacity:1.0;\"/>\n");
	//fclose(xD);
}
int main(void) {

	FILE* ofp = NULL;
	printf("We are about to create a file called %s for writing into it\n", FILENAME);
	ofp = fopen(FILENAME, "w");

	if (ofp == NULL) {
		printf("Cannot open output file %s\n", FILENAME);
		exit(EXIT_FAILURE);  // exit() is defined in <stdlib.h>
	} /* if */

	//declare loop variable

	//declare variables
	int RSCE;

	//seed the generator
	unsigned int seed = (unsigned int)time(NULL);
	srand(seed);

	int k = 0;

	fprintf(ofp, "<!DOCTYPE html>\n");
	fprintf(ofp, "<html>\n");
	fprintf(ofp, "\t<head>\n");
	fprintf(ofp, "\t\t<title>A5.html</title>\n");
	fprintf(ofp, "\t</head>\n");
	fprintf(ofp, "\t<body>\n");
	fprintf(ofp, "\t\t<p>Happy Thanksgiving!</p>\n");
	fprintf(ofp, "\t\t<svg id=\"myart\"  width =\"500\" height=\"300\" xmlns=\"http://www.w3.org/2000/svg\">\n");
	fprintf(ofp, "\t\t\t<defs>\n");
	fprintf(ofp, "\t\t\t\t<clipPath id =\"clipPath\" > <rect x =\"0\" y =\"0\" width =\"790\" height =\"390\" /> </clipPath>\n");
	fprintf(ofp, "\t\t\t</defs>\n");

	//declare variables
	int x,y,width,height,red,green,blue;
	int r;
	int rx, ry;
	float opacity;


	for(k=0;  k<NO_SHAPES; k++) {
		//print the shape number

		//call getRandomNumbers to create random numbers
		RSCE = createRandNum(SHAPE_RANGE,seed);

		//create random numbers
		x = createRandNum(X_RANGE,seed);
		y = createRandNum(Y_RANGE,seed);
		width = createRandNum(WIDTH_RANGE,seed);
		height = createRandNum(HEIGHT_RANGE,seed);
		red = createRandNum(RED_RANGE,seed);
		green = createRandNum(GREEN_RANGE,seed);
		blue = createRandNum(BLUE_RANGE,seed);

		//create the random opacity
		opacity = createRandFloat(OPACITY_RANGE,seed)/100;

		switch (RSCE) {

			//create 4 kinds of shapes
			case 0:

				//circle compute the radius
				r = sqrt(width *width + height * height);
				circle(ofp,x,y,r,red,green,blue,opacity);
				break;

			case 1:

				//rectangle
				rectangle(ofp,x,y,width,height,red,blue,green,opacity);
				break;

			case 2:
				//square set width equal to height
				width = height;

				//a square is a rectangle when the width and height are equal

				rectangle(ofp,x,y,width,height,red,blue,green,opacity);
				//fprintf(ofp,"\t\t\t<rect x =\"%d\"  y =\"%d\"  width =\"%d\" height = \"%d\" style =\"fill:rgb(%d,%d,%d); fill-opacity:%f\"/>\n",x,y,width,height,red,green,blue,opacity);
				break;

			case 3:

				//find the x and y components of the radius
				rx = width;
				ry = height;
				ellipse(ofp,x,y,rx,ry,red,blue,green,opacity);
				break;
		}

	}

	frame(ofp);

	fprintf(ofp, "\t\t</svg>\n");
	fprintf(ofp, "\t</body>\n");
	fprintf(ofp, "</html>\n");

	printf("We created the file %s successfully for writing\n", FILENAME);
	printf("We wrote HTML5 code into the file %s successfully\n", FILENAME);
	fclose(ofp);
	printf("We closed the file %s successfully\n", FILENAME);
	return EXIT_SUCCESS;
} /*main*/
