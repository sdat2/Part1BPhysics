#include <stdio.h>

#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>
using namespace std;

double distance(double x[3]);
double force(double chi[3]);

struct planet{
  double X[3];
  double V[3];
  double A[3];
  double mass;
};

struct planet earth;
earth.X[0] = 1; earth.X[1] = 1; earth.X[2] = 1;
earth.V[0] = 1; earth.V[1] = 1; earth.V[2] = 1;
earth.mass = 1;

double bigmass = 10000;
double G = 1;

int main(void){
  double F[3];
  F = force(earth.X);
}

double distance(double x[3]){
  double dist = sqrt((x[0])*x[0]) + (x[1]*x[1]) + (x[2])*x[2]));
  return dist;
}

double force(double chi[3]){
  double f[3];
  double magf = (G*bigmass*earth.mass)/((distance(chi))^2);
  cout << magf << endl;
  f[0] = -magf*earth.X[0]/(distance(chi));
  f[1] = -magf*earth.X[1]/(distance(chi));
  f[2] = -magf*earth.X[2]/(distance(chi));
  return f;
}
