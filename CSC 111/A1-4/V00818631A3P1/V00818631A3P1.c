/*David Li
 * V00818631
 * 2014/09/25
 * A3
 * V00818631A3P1.c
 * This program computes the areas and volumes of basic shapes
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

float areaCirc(float r){
// Computes area of a circle with radius r
	return M_PI*r*r; // constant M_PI is defined in <math.h>
}/*areaCirc*/

float periCirc(float r){
// Computes perimeter of a circle with radius r
	return M_PI*(r+r); // constant M_PI is defined in <math.h>
}/*periCirc*/

float volSph(float r) { //computes volume of sphere

    //formula for a sphere is 4/3 x pi x r^3

	return M_PI*(r*r*r)*4/3; //returns the volume of a sphere
}/* volSph */

float areaSph(float r) { //computes area of a sphere

	//formula for the area of a sphere is 4 x pi x r^2
	return M_PI * 4 * r * r;
}/* area Sph */

float volCyl(float r, float h){

	// Computes volume of a cylinder with base radius r and height h
	float areaCi = areaCirc(r);
	float volCy = h*areaCi;
	return volCy;

} /*volCyl*/

float areaCyl(float r, float h,float aC, float pC) {

	//computes volume of a cylinder using r and h
	//compute value
	return (pC *h + 2*aC);

}/*areaCyl*/

float volCone(float r,float h,float aC) {
	return(aC*h/3);

} /* volCone */

float areaCone(float r,float h, float aC) {

	float sRoot = sqrt((h*h)+(r*r));
	return(aC+ M_PI*r*sRoot);
}
int main(void){

	float radius = 6.2;
	float height = 8.1;

	float areaC = areaCirc(radius);
	float periC = periCirc(radius);
	float areaS = areaSph(radius);
	float volC = volCyl(radius, height);
	float volS = volSph(radius);
	float areaCy = areaCyl(radius,height,areaC,periC);
	float volCo = volCone(radius,height,areaC);
	float areaCo = areaCone(radius,height,areaC);

	float sumV = volC + volS + volCo;
	float sumA = areaC + areaS + areaCy + areaCo;

	printf("Circle:   Radius = %1.1f                                  Area = %3.1f\n", radius, areaC);
	printf("Sphere:   Radius = %1.1f                 Volume = %1.1f   Area = %3.1f\n",radius, volS,areaS);
	printf("Cylinder: Radius = %1.1f   Height = %1.1f  Volume = %1.1f   Area = %3.1f\n", radius, height,volC,areaCy);
	printf("Cone:     Radius = %1.1f   Height = %1.1f  Volume = %1.1f   Area = %3.1f\n",radius,height,volCo, areaCo);
	printf("Sum:                                   Volumes = %1.1f Area = %3.1f\n",sumV,sumA);
	return EXIT_SUCCESS;
} /*main*/
