/*
 *  Authors:     David Li
 *  Date:        Oct 20, 2014
 *  Assignment:  Assignment 6 Part 1
 *  File name:   V00818631A6P1.c
 *  Description: Vector linear algebra functions
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

//Define the maximum size of a vector and create the Vector type.
#define VSIZE     (4)
typedef Item Vector[VSIZE];

/* ========================================================================= */
/*                       Library Function  Declarations                      */
/*            These functions are defined at the end of the file.            */
/*      The functions are mostly used by the testing code in main(), but     */
/*           you may also find them useful for debugging purposes.           */
/*      (Do not modify these declarations or the corresponding functions)    */
/* ========================================================================= */

/* setVector4
   Set the elements of vector V to be (x, y, z, h).
*/
void setVector4(Vector V, Item x, Item y, Item z, Item h);

/* printVector
   Print the first n elements of the vector V to the console.
*/
void printVector(Vector V, Index n);

/* printVectorHightPrecision
   Print the first n elements of the vector V to the console to seven
   decimal places.
*/
void printVectorHighPrecision(Vector V, Index n);

/* equalVectors
   If elements 0, 1, ..., (size-1) of vectors V1 and V2 are equal (to within
   the provided error value eps), return true. Otherwise, return false.
*/
bool equalVectors(Vector V1, Vector V2, Index size, Item eps);

/* equalVectors4
   If vector V1 is equal to (x, y, z, h) (to within the provided error
   value eps), return true. Otherwise, return false.
*/
bool equalVectors4(Vector V1, Item x, Item y, Item z, Item h, Item eps);


/* ========================================================================= */
/*                           Functions to Implement                          */
/*        Using the types and functions declared above, as well as the       */
/*              Standard Library, implement the functions below.             */
/*              There are a total of 10 functions to implement.              */
/* ========================================================================= */


/* initIndexVector
   Set elements 0, 1, 2, ..., (size - 1) of the vector V to be equal
   to their index (i.e. V[0] = 0, V[1] = 1, ..., V[size-1] = size - 1).
*/
void initIndexVector(Vector V, Index size) {
	/*  V[0]=0, V[1]=1, V[2]=2, ..., V[size-1]=size-1) */
	Index k;
	for (k = 0; k < size; k++)
		V[k] = (Item)k;
} /* initIndexVector */

/* initVectorWithValue
   Set elements 0, 1, 2, ..., (size - 1) of the vector V to the
   value val.
*/
void initVectorWithValue(Vector V, Index size, Item val) {

	/* ... Your code here ... */
	Index k;
	for(k= 0; k < size; k++) {
		V[k] = val;
	}

} /* initVectorWithValue */

/* allOnesVector
   Set elements 0, 1, 2, ..., (size - 1) of the vector V to 1.
*/
void allOnesVector(Vector V, Index size) {

	/* ... Your code here ... */
	initVectorWithValue(V,size,1);
	//Hint: Call initVectorWithValue() to implement this function

} /* allOnesVector */

/* addScalarToVector
   Add the scalar s to elements 0, 1, 2, ..., (size-1) of the vector V.
   (i.e. V[0] = V[0] + s, V[1] = V[1] + s, ..., V[size-1] = V[size-1] + s)
*/
void addScalarToVector(Vector V, Index size, Item s) {

	/* ... Your code here ... */
	Index k;
	for(k =0; k<size; k++) {
		V[k] = V[k] + s;
	}

} /* addScalarToVector */

/* addScalarToVector
   Multiply elements 0, 1, 2, ..., (size-1) of the vector V by the scalar s.
   (i.e. V[0] = V[0]*s, V[1] = V[1]*s, ..., V[size-1] = V[size-1]*s)
*/
void mulVectorByScalar(Vector V, Index size, Item s) {

	/* ... Your code here ... */
	Index k;
	for(k =0; k<size; k++){

		V[k] = V[k] * s;
	}


} /* mulVectorByScalar */

/* addVectors
   Perform the operation V3 = V1 + V2
   Set the first (size) elements of Vector V3 to be the sum of the corresponding
   elements of V1 and V2.
   (i.e. V3[0] = V1[0] + V2[0], V3[1] = V1[1] + V2[1], ..., V3[size-1] = V1[size-1] + V2[size-1])
*/
void addVectors(Vector V1, Vector V2, Vector V3, Index size) {

	/* ... Your code here ... */
	Index k;

	for(k =0; k < size; k++) {
		V3[k] = V1[k] + V2[k];
	}

} /* addVectors */

/* mulVectors
   Set the first (size) elements of Vector V3 to be the product of the corresponding
   elements of V1 and V2.
   (i.e. V3[0] = V1[0] * V2[0], V3[1] = V1[1] * V2[1], ..., V3[size-1] = V1[size-1] * V2[size-1])
*/
void mulVectors(Vector V1, Vector V2, Vector V3, Index size) {

	/* ... Your code here ... */
	Index k;

	for(k =0; k < size; k++) {
		V3[k] = V1[k] * V2[k];
	}


} /* mulVectors */

/* sumItems
   Return the sum of elements 0, 1, 2, ..., (size - 1) of the vector V.
*/
Item sumItems(Vector V, Index size) {

	/* ... Your code here ... */
	Index k;
	Item sum;
	k = 0;
	sum = 0;

	for(k =0; k < size; k++) {
		sum = sum + V[k];
	}

	return sum;

} /* sumItems */

/* dotProduct
   Compute and return the dot product of the first (size) elements of V1 and V2.
   (i.e. V1[0]*V2[0] + V1[1]*V2[1] + ... + V1[size-1]*V2[size-1])
*/
Item dotProduct(Vector V1, Vector V2, Index size) {

	/* ... Your code here ... */
	Index k;
	Item dot = 0;

	for (k = 0; k < size; k++) {
		dot = dot + V1[k] * V2[k];
	}

	return dot;

} /* dotProduct */

/* vectorLength
   (also known as the L2 norm)
   Compute and return |V| = sqrt(V[0]*V[0] + V[1]*V[1] + ... + V[size-1]*V[size-1]

*/
Item vectorLength(Vector V, Index size) {
	/* The implementation of this function requires sqrt() from <math.h> */
	Item bigNumber;
	Item length = 0;

	//Take the Dot product of V and V
	bigNumber = dotProduct(V,V,size);

	length = sqrt(bigNumber);
	/* ... Your code here ... */
	//printf(">>> vectorLength not implemented\n");
	//Hint: This function may call the dotProduct function.
	return length;

} /* vectorLength */


/* ========================================================================= */
/*                               Main Program                                */
/* Contains code to test the 10 functions above. You should add extra tests  */
/*  to ensure that your implemented functions work correctly in all cases.   */
/* ========================================================================= */

/* vectorTest
   A helper function used by main for testing vector-valued functions.
*/
void vectorTest(char testname[], Vector ResultVector, Item w, Item x, Item y, Item z){
	printf("   Test %s\n",testname);
	printf("   ==> Expected    %.1f  %.1f  %.1f  %.1f\n",w,x,y,z);
	printf("   ==> Computed ");
	printVector(ResultVector, VSIZE);
	if (equalVectors4(ResultVector, w,x,y,z, BIG_EPSILON))
		printf("   ==> Test PASSED\n");
	else
		printf("ERROR: Test FAILED\n");
}
/* scalarTest
   A helper function used by main for testing scalar-valued functions.
*/
void scalarTest(char testname[], Item resultScalar, Item expectedResult, char quantityname[]){
	printf("   Test %s\n",testname);
	printf("   ==> Expected    %s = %.3f\n", quantityname, expectedResult);
	printf("   ==> Computed    %s = %.3f\n", quantityname, resultScalar);
	if (fabs(resultScalar - expectedResult) <= BIG_EPSILON)
		printf("   ==> Test PASSED\n");
	else
		printf("ERROR: Test FAILED\n");
}

int main(void) {
	Vector Vec1, Vec2, Vec3;
	Item sum;
	Item dot;
	Item length;

	printf("Testing vector linear algebra functions\n");

	/* Tests for initIndexVector */
	setVector4(Vec1, 0.0, 0.0, 0.0, 0.0);
	initIndexVector(Vec1, 4);
	vectorTest("initIndexVector (size = 4)",Vec1, 0.0, 1.0, 2.0, 3.0);

	setVector4(Vec1, 0.0, 0.0, 0.0, 0.0);
	initIndexVector(Vec1, 2);
	vectorTest("initIndexVector (size = 2)",Vec1, 0.0, 1.0, 0.0, 0.0);

	/* Tests for initVectorWithValue */
	setVector4(Vec1, 0.0, 0.0, 0.0, 0.0);
	initVectorWithValue(Vec1, 4, 3.0);
	vectorTest("initVectorWithValue (size = 4)",Vec1, 3.0, 3.0, 3.0, 3.0);

	setVector4(Vec1, 0.0, 0.0, 0.0, 0.0);
	initVectorWithValue(Vec1, 3, 4.0);
	vectorTest("initVectorWithValue (size = 3)",Vec1, 4.0, 4.0, 4.0, 0.0);

	/* Tests for allOnesVector */
	setVector4(Vec1, 0.0, 0.0, 0.0, 0.0);
	allOnesVector(Vec1, 4);
	vectorTest("allOnesVector (size = 4)",Vec1, 1.0, 1.0, 1.0, 1.0);

	setVector4(Vec1, 0.0, 0.0, 0.0, 0.0);
	allOnesVector(Vec1, 1);
	vectorTest("allOnesVector (size = 1)",Vec1, 1.0, 0.0, 0.0, 0.0);

	/* Tests for addScalarToVector */
	setVector4(Vec1, 0.0, 1.0, 2.0, 3.0);
	addScalarToVector(Vec1, VSIZE, 3.0);
	vectorTest("addScalarToVector (test 1)",Vec1, 3.0, 4.0, 5.0, 6.0);

	setVector4(Vec1, 4.0, 5.0, 2.0, 3.0);
	addScalarToVector(Vec1, VSIZE, -1.5);
	vectorTest("addScalarToVector (test 2)",Vec1, 2.5, 3.5, 0.5, 1.5);


	/* Tests for mulVectorByScalar */
	setVector4(Vec1, 3.0, 4.0, 5.0, 6.0);
	mulVectorByScalar(Vec1, VSIZE, 3.0);
	vectorTest("mulVectorByScalar (test 1)",Vec1, 9.0, 12.0, 15.0, 18.0);

	setVector4(Vec1, 5.0, 4.0, 3.0, 2.0);
	mulVectorByScalar(Vec1, VSIZE, -1.0);
	vectorTest("mulVectorByScalar (test 2)",Vec1, -5.0, -4.0, -3.0, -2.0);

	setVector4(Vec1, 3.0, 6.0, 9.0, -3.0);
	mulVectorByScalar(Vec1, VSIZE, -0.5);
	vectorTest("mulVectorByScalar (test 3)",Vec1, -1.5, -3.0, -4.5, 1.5);

	/* Tests for addVectors */
	setVector4(Vec1, 1.0, 2.0, 3.0, 4.0);
	setVector4(Vec2, 1.0, 4.0, 6.0, 8.0);
	addVectors(Vec1, Vec2, Vec3, 4);
	vectorTest("addVectors (size = 4)",Vec3, 2.0, 6.0, 9.0, 12.0);

	setVector4(Vec3, 0.0, 0.0, 0.0, 0.0);
	setVector4(Vec1, 1.0, 2.0, 3.0, 4.0);
	setVector4(Vec2, 1.0, 4.0, 6.0, 8.0);
	addVectors(Vec1, Vec2, Vec3, 3);
	vectorTest("addVectors (size = 3)",Vec3, 2.0, 6.0, 9.0, 0.0);

	setVector4(Vec3, 0.0, 0.0, 0.0, 0.0);
	setVector4(Vec1, 1.4, 1.1, 3.0, 4.0);
	setVector4(Vec2, 1.3, 4.0, 6.0, 8.0);
	addVectors(Vec1, Vec2, Vec3, 2);
	vectorTest("addVectors (size = 2)",Vec3, 2.7, 5.1, 0.0, 0.0);

	/* Tests for mulVectors */
	setVector4(Vec1, 1.0, 2.0, 3.0, 4.0);
	setVector4(Vec2, 1.0, 4.0, 6.0, 8.0);
	mulVectors(Vec1, Vec2, Vec3, 4);
	vectorTest("mulVectors (size = 4)",Vec3, 1.0, 8.0, 18.0, 32.0);

	setVector4(Vec3, 0.0, 0.0, 0.0, 0.0);
	setVector4(Vec1, 9.0, 2.0, 3.0, 4.0);
	setVector4(Vec2, 2.0, 4.0, 6.0, 8.0);
	mulVectors(Vec1, Vec2, Vec3, 1);
	vectorTest("mulVectors (size = 1)",Vec3, 18.0, 0.0, 0.0, 0.0);

	/* Tests for sumItems */
	initIndexVector(Vec1, VSIZE);
	sum = sumItems(Vec1, 4);
	scalarTest("sumItems (size = 4)", sum, 6.0, "sum");

	setVector4(Vec1, 9.0, 2.0, 3.0, 4.0);
	sum = sumItems(Vec1, 3);
	scalarTest("sumItems (size = 3)", sum, 14.0, "sum");

	setVector4(Vec1, 9.75, 2.5, 3.0, 4.0);
	sum = sumItems(Vec1, 2);
	scalarTest("sumItems (size = 2)", sum, 12.25, "sum");

	/* Tests for dotProduct */
	setVector4(Vec1, 1.0, 2.0, 3.0, 4.0);
	setVector4(Vec2, 1.0, 4.0, 6.0, 8.0);
	dot = dotProduct(Vec1, Vec2, 4);
	scalarTest("dotProduct (size = 4)", dot, 59.0, "dot product");

	setVector4(Vec1, 0.7074, 1.4142, 3.0, 4.0);
	setVector4(Vec2, 0.7074, 1.4142, 6.0, 8.0);
	dot = dotProduct(Vec1, Vec2, 2);
	scalarTest("dotProduct (size = 2)", dot, 2.5, "dot product");


	/* Tests for vectorLength */
	setVector4(Vec1, 1.0, 2.0, 3.0, 4.0);
	length = vectorLength(Vec1, 4);
	scalarTest("vectorLength (size = 4)", length, 5.477, "length");

	setVector4(Vec1, 1.41421,1.41421,1.41421, 7.0);
	length = vectorLength(Vec1, 3);
	scalarTest("vectorLength (size = 3)", length, 2.449, "length");

	return EXIT_SUCCESS;
} /* main */


/* ========================================================================= */
/*                           Library Functions                               */
/*         These are declared above, and are used for testing the            */
/*        linear algebra functions. Do not modify these functions.           */
/* ========================================================================= */

/* setVector4
   Set the elements of vector V to be (x, y, z, h).
*/
void setVector4(Vector V, Item x, Item y, Item z, Item h) {
	/* V = {x, y, z} */
	V[0] = x; V[1] = y; V[2] = z; V[3] = h;
} /* setVector4 */

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

/* equalVectors4
   If vector V1 is equal to (x, y, z, h) (to within the provided error
   value eps), return true. Otherwise, return false.
*/
bool equalVectors4(Vector V1, Item x, Item y, Item z, Item h, Item eps) {
	/* return true if V1 == {x, y, z, h}; false otherwise */
	Index k;
	Vector V2 = {x, y, z, h};
	for (k=0; k<4; k++) {
		if (fabs(V1[k]-V2[k]) > eps) {
			return false;
		} /* if */
	} /* for */
	return true;
} /* equalVectors4 */
