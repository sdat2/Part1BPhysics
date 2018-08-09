// RotationMatrix.cc
// Program to calculate coordinates after rotation
#include <iostream>
#include <cmath>
using namespace std;


// two different functions to do the job
void ComputeMatrix(float matrix[2][2], float angle);
// this one
void RotateCoordinates(float rot[2][2], float old[2], float transformed[2]);

int main(void){
//declare variables as floats
float angle, point[2], transformedPoint[2];
float rotation[2][2];
// Get angle of rotation and initial position from input.
cout << "Enter magnitude of rotation in xy plane in degrees: " ; cin >> angle;
cout << "Input x and y coordinates: " << endl;
cin >> point[0] >> point[1];
// Calculate coefficients of rotation matrix and transform point. //
//The value of pi is declared in math as M_PI.
// so the angle is made into radians before it is passed
//rotation matrix passed to Compute Matrix to fiddle with
ComputeMatrix(rotation, (M_PI*angle/180.0));
//rotation matrix, point and transformed point passed to RotateCoordinates
RotateCoordinates(rotation, point, transformedPoint);
// Both functions now have fiddled with matrices declared
//Output result.
cout << "The (x,y) coordinates in the rotated system are ";
cout << transformedPoint[0] << " and " << transformedPoint[1] << endl;
return 0;
}

// creates the  c s -s c matrix using the angle it is given
// why does it need to be pased the matrix? Can that not be a global variable
// probably a much better structurre than what I was doing previously
void ComputeMatrix(float matrix[2][2], float angle) {
    matrix[0][0] = cos(angle);
    matrix[0][1] = sin(angle);
    matrix[1][0] = -sin(angle);
    matrix[1][1] = cos(angle);
}

//this function does not seem to be called at all
void RotateCoordinates(float rot[2][2], float old[2], float transformed[2]) {
  //impliments matrix multiplication with a vector
transformed[0] = (rot[0][0] * old[0]) + (rot[0][1] * old[1]);
transformed[1] = (rot[1][0] * old[0]) + (rot[1][1] * old[1]);
}
