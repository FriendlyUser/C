/*
 *  Authors:     Hausi A. Muller and B. Bird
 *  Date:        Oct 19, 2014
 *  Assignment:  Assignment 6 Part 2
 *  File name:   a6p2template.c
 *  Description: Matrix linear algebra functions
 *  Reference:   http://reference.wolfram.com/mathematica/tutorial/VectorsAndMatrices.html
 *  Reference:   http://reference.wolfram.com/mathematica/tutorial/VectorOperations.html
 *  Reference:   http://reference.wolfram.com/mathematica/guide/OperationsOnVectors.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* function sqrt() is defined in <math.h> */
#include <stdbool.h>
#include <float.h>
#define BIG_EPSILON  (0.001)


/* ========================================================================= */
/*                              Type Definitions                             */
/*          Do not alter the provided definitions (they will be used         */
/*            for marking). You may add new definitions as needed.           */
/* ========================================================================= */

//Create the Index type
typedef int Index;
//Create the Item type
typedef float Item;

//Define the maximum size of matrix row or column
#define MSIZE     (3)
//Define a Vector type
typedef Item Vector[MSIZE];
//Define a Matrix type
typedef Item Matrix[MSIZE][MSIZE];

/* ========================================================================= */
/*                       Library Function  Declarations                      */
/*            These functions are defined at the end of the file.            */
/*      The functions are mostly used by the testing code in main(), but     */
/*           you may also find them useful for debugging purposes.           */
/*      (Do not modify these declarations or the corresponding functions)    */
/* ========================================================================= */

/* setVector2
   Set the first two elements of the vector V to the provided values (x,y), and set all
   remaining elements to 0.
*/
void setVector2(Vector V, Item x, Item y);

/* setVector3
   Set the first three elements of the vector V to the provided values (x, y, z), and set
   the fourth element to 0.
*/
void setVector3(Vector V, Item x, Item y, Item z);

/* printVector
   Print the first n elements of the vector V to the console.
*/
void printVector(Vector V, Index n);

/* printVectorHightPrecision
   Print the first n elements of the vector V to the console to seven
   decimal places.
*/
void printVectorHighPrecision(Vector V, Index n);

/* matPrint
   Print the provided matrix A to the console.
*/
void matPrint(Matrix A, Index rows, Index cols);

/* equalVectors
   If elements 0, 1, ..., (size-1) of vectors V1 and V2 are equal (to within
   the provided error value eps), return true. Otherwise, return false.
*/
bool equalVectors(Vector V1, Vector V2, Index size, Item eps);

/* equalVectors2
   If the first two elements of V1 are equal to (x, y) (to within
   the provided error value eps), return true. Otherwise, return false.
*/
bool equalVectors2(Vector V1, Item x, Item y, Item eps);

/* equalVectors3
   If the first three elements of V1 are equal to (x, y, z) (to within
   the provided error value eps), return true. Otherwise, return false.
*/
bool equalVectors3(Vector V1, Item x, Item y, Item z, Item eps);

/* equalMatrix3x3
   If the 3x3 matrix M1 is equal to the matrix described by the nine
   provided values (to within the provided error value eps), return
   true. Otherwise, return false.
*/
bool equalMatrix3x3(Matrix M1, Item m00, Item m01, Item m02, Item m10, Item m11, Item m12, Item m20, Item m21, Item m22, Item eps);

/* matSet2x2
   Set the provided matrix 2x2 matrix A to the values provided.
*/
void matSet2x2(Matrix A, Item a00, Item a01, Item a10, Item a11);

/* matSet3x3
   Set the provided matrix 3x3 matrix A to the values provided.
*/
void matSet3x3(Matrix A, Item a00, Item a01, Item a02, Item a10, Item a11, Item a12, Item a20, Item a21, Item a22);

/* ========================================================================= */
/*                           Functions to Implement                          */
/*        Using the types and functions declared above, as well as the       */
/*              Standard Library, implement the functions below.             */
/*              There are a total of 9 functions to implement.               */
/* ========================================================================= */

/* matInitIdentity
   Set the matrix A to an identity matrix of size (rows x cols).
   An identity matrix contains 1 in every diagonal entry (e.g. A[0][0], A[1][1], etc.)
   and 0 everywhere else.
*/
void matInitIdentity(Matrix A, Index rows, Index cols) {
	Index k, j;
	for (j=0;  j<rows;  j++){
		for (k=0;  k<cols;  k++){
			if (j == k)
				A[j][k] = 1.0; 
			else
				A[j][k] = 0.0;
		}
	}
} /* matInitIdentity */

/* matInitSymmetric
   Set the matrix A to a symmetric matrix where
     A[j][k] = j + k
   for all entries of A within the provided range of rows and columns.
*/
void  matInitSymmetric(Matrix A, Index rows, Index cols) {
	
	/* ... Your code here ... */
	Index j;
		Index k;

		for(j = 0; j < rows; j++ ) {
			for(k = 0; k < cols; k++) {
				A[j][k] = j + k;
			}
		}
	
} /* matInitSymmetric */

/* matCopy
   Copy each element of the (rows x cols) matrix SourceMatrix into the provided
   matrix DestMatrix.
*/
void matCopy(Matrix SourceMatrix, Matrix DestMatrix, Index rows, Index cols) {
		
	/* ... Your code here ... */
	printf(">>> matCopy not implemented\n");
	
} /* matCopy */

/* matTranspose
   Set the provided matrix B to be the transpose of the (rows x cols) matrix
   A. That is, set B[k][j] = A[j][k] for all indices j & k in range.
*/
void matTranspose(Matrix A, Matrix B, Index rows, Index cols) {
		
	/* ... Your code here ... */
	printf(">>> matTranspose not implemented\n");
	
} /* matTranspose */

/* matAddScalar
   Add the scalar value s to every entry of the provided (rows x cols) 
   matrix A.
*/
void matAddScalar(Matrix A, Index rows, Index cols, Item s) {
	
	/* ... Your code here ... */
	printf(">>> matAddScalar not implemented\n");
	
} /* matAddScalar */

/* matMulScalar
   Multiply each entry of the (rows x cols) matrix A by the scalar s.
*/
void matMulScalar(Matrix A, Index rows, Index cols, Item s) {
		
	/* ... Your code here ... */
	printf(">>> matMulScalar not implemented\n");
	
} /* matMulScalar */

/* matAdd
   Compute the matrix sum C = A + B.
   (i.e. C[k][j] = A[k][j] + B[k][j] for all indices k & j in the provided range)
*/
void matAdd(Matrix A, Matrix B, Matrix C, Index rows, Index cols) {
		
	/* ... Your code here ... */
	printf(">>> matAdd not implemented\n");
	
} /* matAdd */

/* matMul
   Compute the product C = A*B using matrix multiplication.
   
   ARows and ACols contain the number of rows and columns of the matrix A.
   BCols contains the number of columns in B (the number of rows in B is the same
   as the number of columns in A).
*/
   
void matMul(Matrix A, Matrix B, int ARows, int ACols, int BCols, Matrix C){

	/* ... Your code here ... */
	printf(">>> matMul not implemented\n");
	
} /* matMul */

/* matTimesVector
   Compute the matrix/vector product A*b and store the result in resultVector.
   The matrix A has dimensions (rows x cols). The vector b has length (cols) and
   the vector resultVector has length (rows).
*/
void matTimesVector(Matrix A, Index rows, Index cols, Vector b, Vector resultVector) {
	
	/* ... Your code here ... */
	printf(">>> matTimesVector not implemented\n");
	
} /* matTimesVector */


/* ========================================================================= */
/*                               Main Program                                */
/* Contains code to test the 10 functions above. You should add extra tests  */
/*  to ensure that your implemented functions work correctly in all cases.   */
/* ========================================================================= */


/* matrixTest
   A helper function used by main for testing matrix-valued functions.
*/
void matrixTest(char testname[], Matrix Result, Item m00, Item m01, Item m02, Item m10, Item m11, Item m12, Item m20, Item m21, Item m22){
	printf("   Test %s\n",testname);
	printf("   ==> Expected    %4.1f  %4.1f  %4.1f\n",m00, m01, m02);
	printf("                   %4.1f  %4.1f  %4.1f\n",m10, m11, m12);
	printf("                   %4.1f  %4.1f  %4.1f\n",m20, m21, m22);
	printf("\n");
	printf("   ==> Computed    %4.1f  %4.1f  %4.1f\n",Result[0][0], Result[0][1], Result[0][2]);
	printf("                   %4.1f  %4.1f  %4.1f\n",Result[1][0], Result[1][1], Result[1][2]);
	printf("                   %4.1f  %4.1f  %4.1f\n",Result[2][0], Result[2][1], Result[2][2]);
	if (equalMatrix3x3(Result, m00, m01, m02, m10, m11, m12, m20, m21, m22, BIG_EPSILON)) 
		printf("   ==> Test PASSED\n");
	else
		printf("ERROR: Test FAILED\n");
}

/* matrixTest_operator
   A helper function used by main for testing matrix-valued functions.
*/
void matrixTest_operator(char testname[], char operator[], Matrix Operand1, Matrix Operand2, Matrix Result, Item m00, Item m01, Item m02, Item m10, Item m11, Item m12, Item m20, Item m21, Item m22){
	printf("   Test %s\n",testname);
	printf("   ==> Computing   %4.1f  %4.1f  %4.1f     %4.1f  %4.1f  %4.1f\n",Operand1[0][0], Operand1[0][1], Operand1[0][2],Operand2[0][0], Operand2[0][1], Operand2[0][2]);
	printf("                   %4.1f  %4.1f  %4.1f  %s  %4.1f  %4.1f  %4.1f\n",Operand1[0][0], Operand1[0][1], Operand1[0][2],operator,Operand2[1][0], Operand2[1][1], Operand2[1][2]);
	printf("                   %4.1f  %4.1f  %4.1f     %4.1f  %4.1f  %4.1f\n",Operand1[0][0], Operand1[0][1], Operand1[0][2],Operand2[2][0], Operand2[1][1], Operand2[2][2]);
	printf("\n");
	printf("   ==> Expected    %4.1f  %4.1f  %4.1f\n",m00, m01, m02);
	printf("                   %4.1f  %4.1f  %4.1f\n",m10, m11, m12);
	printf("                   %4.1f  %4.1f  %4.1f\n",m20, m21, m22);
	printf("\n");
	printf("   ==> Computed    %4.1f  %4.1f  %4.1f\n",Result[0][0], Result[0][1], Result[0][2]);
	printf("                   %4.1f  %4.1f  %4.1f\n",Result[1][0], Result[1][1], Result[1][2]);
	printf("                   %4.1f  %4.1f  %4.1f\n",Result[2][0], Result[2][1], Result[2][2]);
	if (equalMatrix3x3(Result, m00, m01, m02, m10, m11, m12, m20, m21, m22, BIG_EPSILON)) 
		printf("   ==> Test PASSED\n");
	else
		printf("ERROR: Test FAILED\n");
}

/* matrixVectorTest
   A helper function used by main for testing vector-valued functions.
*/
void matrixVectorTest(char testname[], char operator[], Matrix Operand1, Vector Operand2, Vector ResultVector, Item x, Item y, Item z){
	printf("   Test %s\n",testname);
	printf("   ==> Computing   %4.1f  %4.1f  %4.1f     %4.1f\n",Operand1[0][0], Operand1[0][1], Operand1[0][2],Operand2[0]);
	printf("                   %4.1f  %4.1f  %4.1f  %s  %4.1f\n",Operand1[0][0], Operand1[0][1], Operand1[0][2],operator,Operand2[1]);
	printf("                   %4.1f  %4.1f  %4.1f     %4.1f\n",Operand1[0][0], Operand1[0][1], Operand1[0][2],Operand2[2]);
	printf("\n");
	printf("   ==> Expected    %4.1f\n",x);
	printf("                   %4.1f\n",y);
	printf("                   %4.1f\n",z);
	printf("\n");
	printf("   ==> Computed    %4.1f \n",ResultVector[0]);
	printf("                   %4.1f\n",ResultVector[1]);
	printf("                   %4.1f\n",ResultVector[2]);
	if (equalVectors3(ResultVector, x,y,z, BIG_EPSILON)) 
		printf("   ==> Test PASSED\n");
	else
		printf("ERROR: Test FAILED\n");
}

int main(void) {
	Matrix M1, M2, M3;
	Matrix Op1, Op2;
	Vector b, x;

	printf("Testing vector linear algebra functions\n");
	
	/* Tests for matInitIdentity */
	matSet3x3(M1, 0,0,0,0,0,0,0,0,0);	
	matInitIdentity(M1, MSIZE, MSIZE);
	matrixTest("matInitIdentity",M1, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
	
	/* Tests for matInitSymmetric */
	matSet3x3(M1, 0,0,0,0,0,0,0,0,0);	
	matInitSymmetric(M1, 3, 3);
	matrixTest("matInitSymmetric (3x3)",M1, 0.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);
	
	matSet3x3(M1, 0,0,0,0,0,0,0,0,0);	
	matInitSymmetric(M1, 2, 2);
	matrixTest("matInitSymmetric (2x2)",M1, 0.0, 1.0, 0.0, 1.0, 2.0, 0.0, 0.0, 0.0, 0.0);
	

	/* Tests for matCopy */
	matSet3x3(M1, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matSet3x3(M2, 0,0,0,0,0,0,0,0,0);	
	matCopy(M1, M2, 3, 3);
	matrixTest("matCopy (3x3)",M2, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	
	matSet3x3(M1, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matSet3x3(M2, 0,0,0,0,0,0,0,0,0);	
	matCopy(M1, M2, 2, 2);
	matrixTest("matCopy (3x3)",M2, 0.0, 1.0, 0.0, 3.0, 4.0, 0.0, 0.0, 0.0, 0.0);
	
	/* Tests for matTranspose */
	matSet3x3(M1, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matSet3x3(M2, 0,0,0,0,0,0,0,0,0);	
	matTranspose(M1, M2, MSIZE, MSIZE);
	matrixTest("matTranspose",M2, 0.0, 3.0, 6.0, 1.0, 4.0, 7.0, 2.0, 5.0, 8.0);

	
	/* Tests for matAddScalar */
	matSet3x3(M1, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
	matAddScalar(M1, 3, 3, 0.2);
	matrixTest("matAddScalar (3x3)",M1, 1.2, 0.2, 0.2, 0.2, 1.2, 0.2, 0.2, 0.2, 1.2);

	matSet3x3(M1, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
	matAddScalar(M1, 2, 2, 0.2);
	matrixTest("matAddScalar (2x2)",M1, 1.2, 0.2, 0.0, 0.2, 1.2, 0.0, 0.0, 0.0, 1.0);

	/* Tests for matMulScalar */
	matSet3x3(M1, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matMulScalar(M1, 3, 3, 2.0);
	matrixTest("matMulScalar (3x3)",M1, 0.0, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0);

	matSet3x3(M1, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matMulScalar(M1, 2, 3, 2.0);
	matrixTest("matMulScalar (2x3)",M1, 0.0, 2.0, 4.0, 6.0, 8.0, 10.0, 6.0, 7.0, 8.0);

	/* Tests for matAdd */
	matSet3x3(M1,  0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matSet3x3(Op1, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matSet3x3(M2,  0.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);
	matSet3x3(Op2,  0.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);
	matAdd(M1, M2, M3, MSIZE, MSIZE);
	matrixTest_operator("matAdd","+",Op1, Op2, M3, 0.0, 2.0, 4.0, 4.0, 6.0, 8.0, 8.0, 10.0, 12.0);

	/* Tests for matMul */
	matSet3x3(M1,  0.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);
	matSet3x3(Op1, 0.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);
	matSet3x3(M2,  0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matSet3x3(Op2, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matMul(M1,M2, MSIZE, MSIZE,MSIZE, M3);
	matrixTest_operator("matMul","*",Op1, Op2, M3, 15.0, 18.0, 21.0, 24.0, 30.0, 36.0, 33.0, 42.0, 51.0);

	/* Tests for matTimesVector */
	matSet3x3(M1,  5.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);
	matSet3x3(Op1, 5.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);
	setVector3(b, 1,2,3);
	matTimesVector(M1, 3, 3, b, x);	
	setVector3(b, 1,2,3);
	matrixVectorTest("matTimesVector", "*", Op1, b, x, 13, 14, 20);


	return EXIT_SUCCESS;
} /* main */


/* ========================================================================= */
/*                           Library Functions                               */
/*         These are declared above, and are used for testing the            */
/*        linear algebra functions. Do not modify these functions.           */
/* ========================================================================= */

/* setVector2
   Set the first two elements of the vector V to the provided values (x,y), and set all
   remaining elements to 0.
*/
void setVector2(Vector V, Item x, Item y) {
	/* V = {x, y} */
	V[0] = x; V[1] = y;	V[2] = 0.0; V[3] = 0.0;
} /* setVector2 */

/* setVector3
   Set the first three elements of the vector V to the provided values (x, y, z), and set
   the fourth element to 0.
*/
void setVector3(Vector V, Item x, Item y, Item z) {
	/* V = {x, y, z} */
	V[0] = x; V[1] = y; V[2] = z; V[3] = 0.0;
} /* setVector3 */

/* printVector
   Print the first n elements of the vector V to the console.
*/
void printVector(Vector V, Index n){
	/* output V[0], V[1], V[2], ..., V[n-1] */
	Index k;
	printf("   ");
	for (k=0; k < n; k++)
		printf("%.1f  ", V[k]);
	printf("\n");
} /* printVector */

/* printVectorHightPrecision
   Print the first n elements of the vector V to the console to seven
   decimal places.
*/
void printVectorHighPrecision(Vector V, Index n) {
	/* output V[0], V[1], V[2], ..., V[n-1] */
	Index k;
	printf("   ");
	for (k=0; k < n; k++)
		printf("%.7f  ", V[k]);
	printf("\n");
} /* printVectorHighPrecision */

/* matPrint
   Print the provided matrix A to the console.
*/
void matPrint(Matrix A, Index rows, Index cols) {
	/* output V[0][0], V[0][1], V[0][2], ..., V[0][cols-1] */
	/* output V[1][0], V[1][1], V[1][2], ..., V[1][cols-1] */
	/* ... */
	/* output V[rows-1][0], V[rows-1][1], V[rows-1][2], ..., V[rows-1][cols-1] */
	Index k, j;
	for (j=0;  j<rows;  j++) {
		for (k=0;  k<cols;  k++)
			printf("   %.1f", A[j][k]);
		printf("   \n");
	} /* for */
	printf("\n");
} /* matPrint */


/* equalVectors
   If elements 0, 1, ..., (size-1) of vectors V1 and V2 are equal (to within
   the provided error value eps), return true. Otherwise, return false.
*/
bool equalVectors(Vector V1, Vector V2, Index size, Item eps) {
	/* return true if V1 == V2; false otherwise */
	Index k;
	for (k=0; k<size; k++) {
		if (fabs(V1[k]-V2[k]) > eps) {
			// Vectors are not equal
			return false;
		} /* if */
	} /* for */
	return true;
} /* equalVectors */

/* equalVectors2
   If the first two elements of V1 are equal to (x, y) (to within
   the provided error value eps), return true. Otherwise, return false.
*/
bool equalVectors2(Vector V1, Item x, Item y, Item eps) {
	/* return true if V1 == {x, y}; false otherwise */
	Index k;
	Vector V2 = {x, y};
	for (k=0; k<2; k++) {
		if (fabs(V1[k]-V2[k]) > eps) {
			return false;
		} /* if */
	} /* for */
	return true;
} /* equalVectors2 */

/* equalVectors3
   If the first three elements of V1 are equal to (x, y, z) (to within
   the provided error value eps), return true. Otherwise, return false.
*/
bool equalVectors3(Vector V1, Item x, Item y, Item z, Item eps) {
	/* return true if V1 == {x, y, z}; false otherwise */
	Index k;
	Vector V2 = {x, y, z};
	for (k=0; k<3; k++) {
		if (fabs(V1[k]-V2[k]) > eps) {
			return false;
		} /* if */
	} /* for */
	return true;
} /* equalVectors3 */

/* equalMatrix3x3
   If the 3x3 matrix M1 is equal to the matrix described by the nine
   provided values (to within the provided error value eps), return
   true. Otherwise, return false.
*/
bool equalMatrix3x3(Matrix M1, Item m00, Item m01, Item m02, Item m10, Item m11, Item m12, Item m20, Item m21, Item m22, Item eps) {
	Matrix M2 = {{m00, m01, m02}, {m10, m11, m12}, {m20, m21, m22}};
	Index k, j;
	for (j=0;  j<3;  j++) {
		for (k=0;  k<3;  k++)
		if (fabs(M1[j][k]-M2[j][k]) > eps) {
			return false;
		} /* if */
	} /* for */
	return true;
} /* equalMatrix3x3 */

/* matSet2x2
   Set the provided matrix 2x2 matrix A to the values provided.
*/
void matSet2x2(Matrix A, Item a00, Item a01, Item a10, Item a11) {
	/* init 2x2 matrix */
	A[0][0] = a00;  A[0][1] = a01;
	A[1][0] = a10;  A[1][1] = a11;
} /* matSet2x2 */

/* matSet3x3
   Set the provided matrix 3x3 matrix A to the values provided.
*/
void matSet3x3(Matrix A, Item a00, Item a01, Item a02, Item a10, Item a11, Item a12, Item a20, Item a21, Item a22) {
	/* init 3x3 matrix */
	A[0][0] = a00;  A[0][1] = a01;  A[0][2] = a02;
	A[1][0] = a10;  A[1][1] = a11;  A[1][2] = a12;
	A[2][0] = a20;  A[2][1] = a21;  A[2][2] = a22;
} /* matSet3x3 */
