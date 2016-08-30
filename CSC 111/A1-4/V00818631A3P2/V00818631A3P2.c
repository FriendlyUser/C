/*David Li
 * V00818631
 * 2014/09/25
 * A3
 * V00818631A3P2.c
 * This program does stuff
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

float areaCirc(float r){
	// Computes area of a circle with radius r
	return (M_PI*r*r); // constant M_PI is defined in <math.h>
}/*areaCirc*/


float findRadius(float h,float vol) {

	float r = sqrt(3*vol/h/M_PI);
	return r;
} /*findRadius*/

float findHeight(float r,float vol) {

	float hei = 3*(vol)/(M_PI*r*r);
	return hei;
} /*findHeight */

float volCone(float r,float h) {
	float c = areaCirc(r);
	return((c*h)/3);

} /* volCone */

int main(void){

	float height = 17.61;
	float volCo = 176144.0;
	float radius;
	radius = findRadius(height,volCo);

	printf("A cone with height %2.1f and volume %6.1f has radius %2.1f \n",height, volCo,radius);

	radius = 97.73271;
	height = 17.61;
	volCo = volCone(radius,height);

	printf("A cone with radius %2.1f and height %2.1f has volume %6.1f\n",radius,height,volCo);

	radius = 97.73271;
	volCo = 176144.0;
	height = findHeight(radius,volCo);

	printf("A cone with radius %2.1f and volume %6.1f has height %2.1f\n",radius,volCo,height);

	return EXIT_SUCCESS;
} /*main*/
