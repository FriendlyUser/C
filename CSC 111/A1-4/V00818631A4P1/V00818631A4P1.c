
/*
*  Author:      David Li
*  UVicID:      V00818631
*  Date:        Oct 8, 2014
*  Assignment 4
*  File name:   V00818631A4P1.c
*  Description: Generates a simple HTML5 file
*/

#include <stdio.h>
#include <stdlib.h>
#define FILENAME   ("A4P1.html")

int main(void) {

	FILE* ofp = NULL;
	printf("We are about to create a file called %s for writing into it\n", FILENAME);
	ofp = fopen(FILENAME, "w");

	if (ofp == NULL) {
		printf("Cannot open output file %s\n", FILENAME);
		exit(EXIT_FAILURE);  // exit() is defined in <stdlib.h>
	} /* if */

	printf("We created the file %s successfully for writing\n", FILENAME);

	fprintf(ofp, "<!DOCTYPE html>\n");
	fprintf(ofp, "<html>\n");
	fprintf(ofp, "\t<head>\n");
	fprintf(ofp, "\t\t<title>A4P1.html</title>\n");
	fprintf(ofp, "\t</head>\n");
	fprintf(ofp, "\t<body>\n");
	fprintf(ofp, "\t\t<p>Happy Thanksgiving!</p>\n");
	fprintf(ofp, "\t\t<svg id=\"myart\"  width =\"500\" height=\"300\" xmlns=\"http://www.w3.org/2000/svg\">\n");
	fprintf(ofp, "\t\t\t<def>\n");
	fprintf(ofp, "\t\t\t\t<clipPath id =\"myframe\" > <rect x =\"0\" y =\"0\" width =\"400\" height =\"250\" /> </clipPath>\n");
	fprintf(ofp, "\t\t\t</def>\n");
	fprintf(ofp, "\t\t\t<circle cx =\"350\"  cy =\"100\"  r =\"100\"  style =\"fill:rgb(240,100,214); fill-opacity:1.0\"/>\n");
	fprintf(ofp, "\t\t\t<rect x =\"375\" y =\"175\" width =\"100\" height =\"100\" style =\"fill:rgb(0,20,255); fill-opacity:0.5\"/>\n");
	fprintf(ofp, "\t\t\t<ellipse cx =\"190\" cy =\"190\" rx =\"175\" ry =\"75\" style =\"fill:rgb(255,0,255); fill-opacity:0.75\"/>\n");
	fprintf(ofp, "\t\t\t<rect x =\"0\" y =\"0\" width =\"500\" height =\"75\" style =\"fill:rgb(255,0,0); fill-opacity:1.0;\"/>\n");
	fprintf(ofp, "\t\t\t<rect x =\"0\" y = \"0\" width =\"500\" height =\"300\" style =\"fill: none; stroke-width: 5; stroke:rgb(255,51,153); stroke-opacity:1.0;\"/>\n");
	fprintf(ofp, "\t\t\t</svg>\n");
	fprintf(ofp, "\t</body>\n");
	fprintf(ofp, "</html>\n");

	printf("We wrote HTML5 code into the file %s successfully\n", FILENAME);
	fclose(ofp);
	printf("We closed the file %s successfully\n", FILENAME);
	return EXIT_SUCCESS;
} /*main*/

