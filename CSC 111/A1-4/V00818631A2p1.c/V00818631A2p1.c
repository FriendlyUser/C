/* Name: David Li
 * Uvic ID: V00818631
 * Date: 2014/09/15
 * Assignment: A2
 * File name: V00818631A2P1.c
 * Description: prints a variety of sequences */

#include <stdlib.h>
#include <stdio.h>

int ASequence1(t1,countstart,countend) { //calculate the first set of values


	printf(" Arithmetic Sequence:  ");

	while (countstart <= countend) {
		printf("%d ",t1);
		countstart++;
		t1 = t1 +11;
	} /* end while */
	return 0;
}  /*ASequence1 */

int ASequence2(t1,countstart,countend) { //calculate the second set of values
	printf(" Arithmetic Sequence:  ");
	while (countstart <= countend) {
		printf("%d ",t1);
		countstart++;
		t1 = t1 -7;
	} /* end while */
	return 0;
} /* ASequence2 */

int HSequence(countstart,countend) {
	//introduce variable that can hold a decimal
	double t1 = 1.00;
	double t2 = t1;
	printf(" Harmonic Sequences ");
	for(countstart =1; countstart<=countend; countstart++) {
		printf("%1.2f ",t2);
		t2 = 1/(t1 + countstart);
	}/*for*/
	//return 0;
}/*HSequence*/


int LSequences(t1,countstart,countend) {
	printf(" Leonardo Sequences: ");
	int tlast =3;
	int tcurrent =5;
	while(countstart <= countend) {
		t1 = tcurrent + tlast + 1;
		tlast = tcurrent;
		tcurrent = t1;
		countstart++;
		if(t1 >= 9) {
			printf(" %d ", t1);
		} /*if*/
	} /*while */
} /* Lsequences */

int PrintNLines(void) {
	printf("\n");
	return 0;
}
int main(void) {

	//set variables for ASequence 1
	int t1 = 8;
	int countstart = 0;
	int countend = 10;

	ASequence1(t1,countstart,countend);

	//reset variables for ASequence 2
	//make a newline
	PrintNLines();
	t1 = 35;
	ASequence2(t1,countstart,countend);

	//make a newline
	PrintNLines();

	HSequence(countstart,countend);

	PrintNLines();
	//reset variables for LSequences
	countstart =1;
	countend = 12;
	LSequences(t1,countstart,countend);
	return EXIT_SUCCESS;
} /* main */
