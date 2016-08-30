/*
 *  Author:      David Li
 *  Date:        Nov. 7, 2014
 *  Assignment:  Assignment 7 Part 1
 *  File name:   V00818631A7P1.c
 *  Description: Generate HTML5 and SVG code to display a wire frame model.
 *               The wire frame model is specified in an input text file identified by WIREFRAME_INPUT_FILENAME.
 *               The HTML5/SVG code is output into a text file identified by HTML5_SVG_OUTPUT_FILENAME.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//The name of the input file
#define WIREFRAME_INPUT_FILENAME ("A7_2014_teapot.txt")
// The name of the output file
#define HTML5_SVG_OUTPUT_FILENAME ("A7P1_2014_teapot.html")


/* ========================================================================= */
/*                              Type Definitions                             */
/*          Do not alter the provided definitions (they will be used         */
/*            for marking). You may add new definitions as needed.           */
/* ========================================================================= */

/* A line segment in 2d space */
typedef struct{
	float x1, y1;
	float x2, y2;
} LineSegment2d;

/* A line segment in 3d space */
typedef struct{
	float x1, y1, z1;
	float x2, y2, z2;
} LineSegment3d;


//Define the maximum size of matrix row or column
#define MATRIX_MAX (4)
//Define a Matrix type
typedef float Matrix[MATRIX_MAX][MATRIX_MAX];


/* Size of the HTML5 canvas - Do not change */
#define CANVAS_SIZE_X 800
#define CANVAS_SIZE_Y 800



/* ========================================================================= */
/*                       Library Function Declarations                       */
/*            These functions are defined at the end of the file.            */
/*      (Do not modify these declarations or the corresponding functions)    */
/* ========================================================================= */


/* writePrologue
   This function writes the initial part of the HTML file (which sets up the
   graphics interface). This must be called before any graphical data is written
   to the file.
*/
void writePrologue(FILE *f);

/* writeEpilogue
   This function writes the final part of the HTML file. This must be called
   after all data has been written, but before the file is closed.
   (The caller is responsible for closing the file afterwards).
*/
void writeEpilogue(FILE *f);

/* read_3d_segment
   Attempts to read six floating point values in the form
		x1 y1 z1 x2 y2 z2
   from the file pointer inputFile.
   If all six values are read successfully, the line segment is stored
   in the provided LineSegment3d struct and the function returns true.
   If all six values could not be read for any reason, the function returns
   false
*/
bool read_3d_segment(FILE* inputFile, LineSegment3d *segment);

/* write_2d_segment
   If the provided file pointer outputFile is valid, writes an SVG line
   segment to outputFile with the colour provided and coordinates taken
   from the provided LineSegment2d struct.

   If the provided file pointer outputFile is not valid, the function will print an error
   message and terminate the program with EXIT_FAILURE.
*/

void write_2d_segment(FILE* outputFile, LineSegment2d segment, char colour[]);

/* matMul
   Compute the product C = A*B using matrix multiplication.

   ARows and ACols contain the number of rows and columns of the matrix A.
   BCols contains the number of columns in B (the number of rows in B is the same
   as the number of columns in A).
*/
void matMul(Matrix A, Matrix B, int ARows, int ACols, int BCols, Matrix C);


/* matInitIdentity
   Set the matrix A to an identity matrix of size (rows x cols).
   An identity matrix contains 1 in every diagonal entry (e.g. A[0][0], A[1][1], etc.)
   and 0 everywhere else.
*/
void matInitIdentity(Matrix A, int rows, int cols);

/* projectionMatrix
   Sets the provided matrix outMatrix to a 2 x 4 projection matrix.
*/
void projectionMatrix(Matrix outMatrix);

/* translationMatrix
   Sets the provided matrix outMatrix to a 4 x 4 translation matrix
   with translation (xt, yt, zt).
*/
void translationMatrix(Matrix outMatrix, float xt, float yt, float zt);

/* scaleMatrix
   Sets the provided matrix outMatrix to a 4 x 4 scaling matrix
   with scale factors (xs, ys, zs).
*/
void scaleMatrix(Matrix outMatrix, float xs, float ys, float zs);

/* rotationMatrixX
   Sets the provided matrix outMatrix to a 4 x 4 rotation matrix
   which rotates by the provided angle around the X axis.

   Note that angle must be specified in radians.
*/
void rotationMatrixX(Matrix outMatrix, float angle);

/* rotationMatrixY
   Sets the provided matrix outMatrix to a 4 x 4 rotation matrix
   which rotates by the provided angle around the Y axis.

   Note that angle must be specified in radians.
*/
void rotationMatrixY(Matrix outMatrix, float angle);

/* rotationMatrixZ
   Sets the provided matrix outMatrix to a 4 x 4 rotation matrix
   which rotates by the provided angle around the Z axis.

   Note that angle must be specified in radians.
*/
void rotationMatrixZ(Matrix outMatrix, float angle);

/* ========================================================================= */
/*                               Main Program                                */
/*        Using the types and functions declared above, as well as the       */
/*              Standard Library, implement the functions below.             */
/*       There are a total of 3 functions to implement (including main).     */
/* ========================================================================= */

void matCopy(Matrix sourceMat, Matrix destMat, int rows, int cols);

/* convert_line_segment_3d_to_2d
   Converts the provided 3d line segment inputSegment to a 2d line segment
   and stores the result in outputSegment.

   The TransformMatrix is a 2 x 4 matrix describing the conversion transformation.

   In A7, the conversion is performed by creating a 4 x 2 matrix A of the form
        x1 x2
        y1 y2
        z1 z2
         1  1
   and taking the product B = TransformMatrix*A. B will be a 2 x 2 matrix of the form
        X1 X2
        Y1 Y2
   containing the coordinates of the 2d line segment's endpoints. The elements of B
   should be stored in the respective elements of the outputSegment struct.
*/
void convert_line_segment_3d_to_2d(LineSegment3d inputSegment, LineSegment2d *outputSegment, Matrix TransformMatrix){

	Matrix A, B;

	A[0][0] = inputSegment.x1;
	A[0][1] = inputSegment.x2;
	A[1][0] = inputSegment.y1;
	A[1][1] = inputSegment.y2;
	A[2][0] = inputSegment.z1;
	A[2][1] = inputSegment.z2;
	A[3][0] = 1;
	A[3][1] = 1;
	/* Construct A from the inputSegment */

	matMul(TransformMatrix, A,2,4,2,B);
	/* Use the matMul function to compute TransformMatrix*A and store
	   the product in B */
	outputSegment->x1 = B[0][0];
	outputSegment->x2 = B[0][1];
	outputSegment->y1 = B[1][0];
	outputSegment->y2 = B[1][1];
	/* Set the endpoints of outputSegment to be the columns of B */

} /* convert_line_segment_3d_to_2d */


/* process_wireframe_model
   Given a pointer (inputFile) to an open file containing 3d line segments,
   read each line segment, convert it to a 2d line segment with the
   convert_line_segment_3d_to_2d function, and write it to the output file
   referenced by the pointer outputFile.

   Before reading any line segments, the function should construct a transform
   matrix M (which will then be provided to convert_line_segment_3d_to_2d).
   The matrix M should be constructed by the product
        M = P * T * S * R_X * R_Z
   where
        - P is a projection matrix (use the projectionMatrix function)
        - T is a translation matrix with translation (400, 400, 400)
        - S is a scale matrix with scale factors (700, 700, 700)
        - R_X is a rotation by 20 degrees about the X axis
        - R_Z is a rotation by 330 degrees about the Z axis

   The matrix P is 2 x 4. All other matrices are 4 x 4.

   For A7P1, most of the function is complete. The only missing functionality is the
   construction of the matrix M. Note that for rotation matrices, the rotation angle
   must be converted to radians before the corresponding rotationMatrix function is
   called.
*/
void process_wireframe_model(FILE* inputFile, FILE* outputFile){

	LineSegment3d segment3d;
	LineSegment2d segment2d;
	Matrix M;
	Matrix P, T, S, R_X, R_Z;
	Matrix storage;
	float angleX = 20 * M_PI/180;
	float angleZ = 330 *M_PI/180;

	projectionMatrix(P);
	translationMatrix(T,400,400,400);
	scaleMatrix(S,700,700,700);
	rotationMatrixX(R_X,angleX);
	rotationMatrixZ(R_Z,angleZ);

	matMul(R_X,R_Z,4,4,4,M);
	matCopy(M, storage,4,4);

	matMul(S,storage,4,4,4,M);
	matCopy(M,storage,4,4);

	matMul(T,storage,4,4,4,M);
	matCopy(M,storage,4,4);

	matMul(P,storage,2,4,4,M);
	//set M to be the fully transformed matrix
	/* Construct M here */
	/* (you may need to declare several other matrices for temporary storage) */


	while(read_3d_segment(inputFile,&segment3d)){
		convert_line_segment_3d_to_2d(segment3d,&segment2d, M);
		write_2d_segment(outputFile,segment2d,"black");
	}

} /* process_wireframe_model */


/* main

   This function is already complete.
   Do not modify the contents of main() in your submission, or you may lose marks.

   The main program does the following:
	- Open the input file WIREFRAME_INPUT_FILENAME (defined at the top of this file),
	  which contains the data for a wireframe model.

	- Open the output file HTML5_SVG_OUTPUT_FILENAME (also defined at the top of this
	  file), which will contain the output HTML code.

	- Call the writePrologue function to write the HTML prologue to the output file.

	- Call the process_wireframe_model function to process the line segments in the file.

	- Call the writeEpilogue function to write the HTML epilogue to the output file.

	- Close the input and output files.
*/
int main(){

	//Open the input file
	FILE* inputFile = fopen(WIREFRAME_INPUT_FILENAME,"r");
	if (inputFile == NULL){
		printf("ERROR: Unable to open input file \"%s\". Exiting...\n",WIREFRAME_INPUT_FILENAME);
		return EXIT_FAILURE;
	}

	//Open the output file
	FILE* outputFile = fopen(HTML5_SVG_OUTPUT_FILENAME,"w");
	if (outputFile == NULL){
		printf("ERROR: Unable to open output file \"%s\". Exiting...\n",HTML5_SVG_OUTPUT_FILENAME);
		return EXIT_FAILURE;
	}

	//Write the prologue to the output file
	writePrologue(outputFile);

	process_wireframe_model(inputFile,outputFile);

	//Write the epilogue to the output file
	writeEpilogue(outputFile);
	fclose(outputFile);
	fclose(inputFile);
	return EXIT_SUCCESS;
} /* main */

void matCopy(Matrix SourceMatrix, Matrix DestMatrix, int rows, int cols) {


	int j;
	int k;

	for(j = 0; j < rows; j++) {
		for(k =0; k < cols; k++) {
			DestMatrix[j][k] = SourceMatrix[j][k];
		}
	}

} /* matCopy */

/* ========================================================================= */
/*                           Library Functions                               */
/*        These are declared above, and will be useful to generate           */
/*            the output file. Do not modify these functions.                */
/* ========================================================================= */


/* writePrologue
   This function writes the initial part of the HTML file (which sets up the
   graphics interface). This must be called before any graphical data is written
   to the file.
*/
void writePrologue(FILE *f){
	if (!f){
		printf("writePrologue error: output file == NULL\n");
		exit(1);
	}
	fputs("<!DOCTYPE html>\n",f);
	fputs("<html>\n",f);
	fputs("<head>\n",f);
	fputs("<title>CSC 111 Fall 2014 -  Assignment 7 Part 1</title>\n",f);
	fputs("</head>\n",f);
	fputs("<body>\n",f);
	fprintf(f,"<svg width=\"%dpx\" height=\"%dpx\">\n",CANVAS_SIZE_X,CANVAS_SIZE_Y);
	fprintf(f,"<g transform=\"translate(0 %d)\">\n",CANVAS_SIZE_Y);
	fputs("<g transform=\"scale(1 -1)\">\n",f);
} /* writePrologue */

/* writeEpilogue
   This function writes the final part of the HTML file. This must be called
   after all data has been written, but before the file is closed.
   (The caller is responsible for closing the file afterwards).
*/
void writeEpilogue(FILE *f){
	if (!f){
		printf("writeEpilogue error: output file == NULL\n");
		exit(1);
	}
	fputs("</g></g>\n",f);
	fputs("</svg>\n",f);
	fputs("</body>\n",f);
	fputs("</html>\n",f);
} /* writeEpilogue */

/* read_3d_segment
   Attempts to read six floating point values in the form
		x1 y1 z1 x2 y2 z2
   from the file pointer inputFile.
   If all six values are read successfully, the line segment is stored
   in the provided LineSegment3d struct and the function returns true.
   If all six values could not be read for any reason, the function returns
   false
*/
bool read_3d_segment(FILE* inputFile, LineSegment3d *segment){
	if (inputFile == NULL)
		return false;
	int numRead = fscanf(inputFile,"%f %f %f %f %f %f",
		&segment->x1, &segment->y1, &segment->z1, &segment->x2, &segment->y2, &segment->z2);
	if (numRead < 6)
		return false;
	else
		return true;
} /* read_3d_segment */

/* write_2d_segment
   If the provided file pointer outputFile is valid, writes an SVG line
   segment to outputFile with the colour provided and coordinates taken
   from the provided LineSegment2d struct.

   If the provided file pointer outputFile is not valid, the function will print an error
   message and terminate the program with EXIT_FAILURE.
*/

void write_2d_segment(FILE* outputFile, LineSegment2d segment, char colour[]){
	if (outputFile == NULL){
		printf("ERROR: Output file invalid.\n");
		exit(EXIT_FAILURE);
	}
	fprintf(outputFile,"<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke: %s;\" />\n",
			segment.x1, segment.y1, segment.x2, segment.y2, colour);
} /* write_2d_segment */


/* matMul
   Compute the product C = A*B using matrix multiplication.

   ARows and ACols contain the number of rows and columns of the matrix A.
   BCols contains the number of columns in B (the number of rows in B is the same
   as the number of columns in A).
*/
void matMul(Matrix A, Matrix B, int ARows, int ACols, int BCols, Matrix C){

	int i, j, k;

	for (i = 0; i < ARows; i++){
		for (j = 0; j < BCols; j++){
			C[i][j] = 0;
			for (k = 0; k < ACols; k++)
				C[i][j] += A[i][k]*B[k][j];
		}
	}

} /* matMul */


/* matInitIdentity
   Set the matrix A to an identity matrix of size (rows x cols).
   An identity matrix contains 1 in every diagonal entry (e.g. A[0][0], A[1][1], etc.)
   and 0 everywhere else.
*/
void matInitIdentity(Matrix A, int rows, int cols) {
	int k, j;
	for (j=0;  j<rows;  j++){
		for (k=0;  k<cols;  k++){
			if (j == k)
				A[j][k] = 1.0;
			else
				A[j][k] = 0.0;
		}
	}
} /* matInitIdentity */



/* projectionMatrix
   Sets the provided matrix outMatrix to a 2 x 4 projection matrix.
*/
void projectionMatrix(Matrix outMatrix){
	outMatrix[0][0] = 1; outMatrix[0][1] = 0; outMatrix[0][2] = 0; outMatrix[0][3] = 0;
	outMatrix[1][0] = 0; outMatrix[1][1] = 0; outMatrix[1][2] = 1; outMatrix[1][3] = 0;
} /* projectionMatrix */

/* translationMatrix
   Sets the provided matrix outMatrix to a 4 x 4 translation matrix
   with translation (xt, yt, zt).
*/
void translationMatrix(Matrix outMatrix, float xt, float yt, float zt){
	outMatrix[0][0] = 1; outMatrix[0][1] = 0; outMatrix[0][2] = 0; outMatrix[0][3] = xt;
	outMatrix[1][0] = 0; outMatrix[1][1] = 1; outMatrix[1][2] = 0; outMatrix[1][3] = yt;
	outMatrix[2][0] = 0; outMatrix[2][1] = 0; outMatrix[2][2] = 1; outMatrix[2][3] = zt;
	outMatrix[3][0] = 0; outMatrix[3][1] = 0; outMatrix[3][2] = 0; outMatrix[3][3] = 1;
} /* translationMatrix */

/* scaleMatrix
   Sets the provided matrix outMatrix to a 4 x 4 scaling matrix
   with scale factors (xs, ys, zs).
*/
void scaleMatrix(Matrix outMatrix, float xs, float ys, float zs){
	outMatrix[0][0] = xs; outMatrix[0][1] = 0;  outMatrix[0][2] = 0;  outMatrix[0][3] = 0;
	outMatrix[1][0] = 0;  outMatrix[1][1] = ys; outMatrix[1][2] = 0;  outMatrix[1][3] = 0;
	outMatrix[2][0] = 0;  outMatrix[2][1] = 0;  outMatrix[2][2] = zs; outMatrix[2][3] = 0;
	outMatrix[3][0] = 0;  outMatrix[3][1] = 0;  outMatrix[3][2] = 0;  outMatrix[3][3] = 1;
} /* scaleMatrix */

/* rotationMatrixX
   Sets the provided matrix outMatrix to a 4 x 4 rotation matrix
   which rotates by the provided angle around the X axis.

   Note that angle must be specified in radians.
*/
void rotationMatrixX(Matrix outMatrix, float angle){
	outMatrix[0][0] = 1; outMatrix[0][1] = 0;           outMatrix[0][2] = 0;           outMatrix[0][3] = 0;
	outMatrix[1][0] = 0; outMatrix[1][1] = cos(angle);  outMatrix[1][2] = -sin(angle); outMatrix[1][3] = 0;
	outMatrix[2][0] = 0; outMatrix[2][1] = sin(angle);  outMatrix[2][2] = cos(angle);  outMatrix[2][3] = 0;
	outMatrix[3][0] = 0; outMatrix[3][1] = 0;           outMatrix[3][2] = 0;           outMatrix[3][3] = 1;
} /* rotationMatrixX */

/* rotationMatrixY
   Sets the provided matrix outMatrix to a 4 x 4 rotation matrix
   which rotates by the provided angle around the Y axis.

   Note that angle must be specified in radians.
*/
void rotationMatrixY(Matrix outMatrix, float angle){
	outMatrix[0][0] = cos(angle);  outMatrix[0][1] = 0; outMatrix[0][2] = -sin(angle); outMatrix[0][3] = 0;
	outMatrix[1][0] = 0;           outMatrix[1][1] = 1; outMatrix[1][2] = 0;           outMatrix[1][3] = 0;
	outMatrix[2][0] = sin(angle);  outMatrix[2][1] = 0; outMatrix[2][2] = cos(angle);  outMatrix[2][3] = 0;
	outMatrix[3][0] = 0;           outMatrix[3][1] = 0; outMatrix[3][2] = 0;           outMatrix[3][3] = 1;
} /* rotationMatrixY */

/* rotationMatrixZ
   Sets the provided matrix outMatrix to a 4 x 4 rotation matrix
   which rotates by the provided angle around the Z axis.

   Note that angle must be specified in radians.
*/
void rotationMatrixZ(Matrix outMatrix, float angle){
	outMatrix[0][0] = cos(angle); outMatrix[0][1] = -sin(angle); outMatrix[0][2] = 0; outMatrix[0][3] = 0;
	outMatrix[1][0] = sin(angle); outMatrix[1][1] = cos(angle);  outMatrix[1][2] = 0; outMatrix[1][3] = 0;
	outMatrix[2][0] = 0;          outMatrix[2][1] = 0;           outMatrix[2][2] = 1; outMatrix[2][3] = 0;
	outMatrix[3][0] = 0;          outMatrix[3][1] = 0;           outMatrix[3][2] = 0; outMatrix[3][3] = 1;
} /* rotationMatrixZ */
