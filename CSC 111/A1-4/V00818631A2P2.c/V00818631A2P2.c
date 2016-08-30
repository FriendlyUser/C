/* Name: David Li
 * Uvic ID: V00818631
 * Date: 2014/09/17
 * Assignment: A2P2
 * File name: V00818631A2P2.c
 * Description: Calculates and displays negatives powers of 3. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

int main(void) {

	int xBig,n,i;
	int answerBig =1;
	double answerSmall =1.0;
	double xSmall = 0.333333333;
	xBig = 3;
	i=0;
	n = 10;
	printf("%2d %d %1.1f.\n",answerBig, i, answerSmall);
	for (i = 1; i < n; i++) {
		answerSmall = answerSmall * xSmall;
		answerBig = answerBig *xBig;
		printf("%2d %d %2.9f.\n", answerBig, i, answerSmall);
	}/*for */

	return EXIT_SUCCESS;
}/*main*/
