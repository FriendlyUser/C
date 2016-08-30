/*David Li
 *Uvic ID: V00818631
 *Date: 2014/09/15
 *Assignment: A2
 *File name: V00818631A2P3.c
 *Description: Illustrates the convertion of litres/100KM to gallons/miles from 4.0 to 8.0 Litres
 */

#include <stdio.h>
#include <stdlib.h>



int main(void) {

	//declare variables
	int i;
	int printstop =40;
	double L = 4.0;
	double M;

	//declare constants
	const double Lpg = 4.54609188;
	const double kmpm = 1.609344;
	const double LIncrease = 0.1;
	printf("Litres  Miles\nper     per \n100 KM   Gallon \n");

	/*for loop to convert litres to gallons*/
	for(i=0;i<=printstop;i++) {

		M = (100 *Lpg)/(kmpm * L); //convert liters/100Km to gallons/miles
		printf("%6.1f",L); //print litres
		printf("%9.1f \n",M); //print miles
		L = L + LIncrease;
	}
	return EXIT_SUCCESS;
}
