// PlanetV2.cpp by Simon Thomas

// e.g ./example 100 1 > tmp

#define D 2 // number of dimensions
using namespace std;
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <cstdio>

struct particle {
double x[D] ; // (x,y) coordinates
double r; // an absolute position thing
double v[D] ; // velocity
double im ; // work with inverse mass instead as it is normally easier
double F[D] ; // Force vector
double p[D]; // momentum vector
double T;
double V;
double L; // angular momentum out of the plane
} ;

//functions
void showState ( particle &a ); //print function
double ruler( particle a ); //returns square of distance
void Force( particle &a ); //changes the acceleration of particle
void PosStep( particle &a, double delta); //does one step of position change
void VStep( particle &a, double delta); //does one step of velocity change
void T( particle &a); // calculates kinetic energy
void V( particle &a); // calculates potential energy
void L( particle &a );
void Euler(particle &a);
void tester( particle &a);
void LeapFrog(particle &a, double delt, int runs);


// These variables are global but they don't really need to be
double GMm = 10^2;
double dt = 1;
double t = 0;
double runcycles = 100000; //default 300 timesteps taken



//function to print position and velocity

// time   x   y   vx    vy    L   E
void showState ( particle &a ){
  cout << t << "\t" << a.x[0] << "\t" << a.x[1];
  cout << "\t" << a.v[0] << "\t" << a.v[1] << "\t";
  cout << a.L << "\t" << a.V+a.T << "\t" << endl;
 }

//for mode of program testing where only conservation important
 void ShowStateConservation (particle &a){
  cout << a.L << "\t" << a.V+a.T << "\t";
 }

//updates force in struct
void Force( particle &a ){
  //rule produces square of distance
  double Forcemag = GMm/(a.r*a.r);
  for(int i = 0; i < D; i++){
    a.F[i] = - (Forcemag * a.x[i] )/(a.r);
    // should go towards the origin
  }
}

//function which changes position by one step of velocity
void PosStep( particle &a, double delta){
  for(int i = 0; i < D; i++){ a.x[i] += a.v[i]*delta; }
  double r2 = 0; for(int i=0; i < D; i++){r2 += a.x[i]*a.x[i];}
  a.r = sqrt(r2);
}

//function which changes velocity by one step of acceleration
void VStep( particle &a,
            double delta
          ){
            for(int i = 0; i < D; i++){ a.v[i] += a.F[i]*delta*a.im;
            }}


//T = 1/2*mv^(2)
void T( particle &a){
  double squarespeed;
    for(int i = 0; i < D; i++){
      squarespeed += a.v[i]*a.v[i];
    }
  a.T = 0.5*squarespeed/a.im;
}

// V = GMm/r
void V( particle &a){ a.V = - GMm / a.r;  }

// L = m*rxV
void L( particle &a){
  // a.L = m*rxV
   if (D==2){
     a.L = (a.x[0]*a.v[1] - a.x[1]*a.v[0])/a.im;
   } //method only valid when particle moves in plane
   //would work out the
}

/*Leapfrog method
Repeat
4: Increment t by δt
{
Increment x by 1 δt × v
2 Increment t by 1δt
2
Increment v by δt × 1 f 1m
Find f = f(x,t)
Increment x by 2 δt × v Increment t by 1δt
} */
//function which implements leapfrog

void LeapFrog(particle &a,
              double delt,
              int runs)
   {
    showState( a ); // print initial conditions
  for(int i = 0; i < runs; i++){
      PosStep( a , delt/2);
      t = t + delt/2; //increment time
      Force( a ); //apply force at half time
      VStep( a , delt); //respond to force
      PosStep( a , delt/2); //increment position again
      t = t + delt/2; //increment time
      L( a );
      V( a );
      T( a );
      if(i + 1== runs){showState( a );} // print changed conditions
  }
}

//function  which implements euler for runtime
void Euler(particle &a){
 showState( a );
  for(int i = 0; i < runcycles; i++){
    PosStep( a , dt); //increment position
    Force( a ); //refresh acceleration vector of particle
    VStep( a , dt); //increment Velocity
    t = t + dt; //increment time
    showState( a ); // print current state
  }
}



int main(int argc, char* argv[]){
  particle a;
         a.v[0] = 0.4;
         a.v[1] = 0.0;
         a.x[0] = 1.5;
         a.x[1] = 2;
         a.im = 1;
         double r2 = 0; for(int i=0; i < D; i++){r2 += a.x[i]*a.x[i];}
         a.r = sqrt(r2);



    if(argc>1)   {
      sscanf( argv[1], "%lf", &runcycles ) ; // put the 1st argument in runcycles
    }
    if(argc>2) {
      sscanf( argv[2], "%lf", &GMm ) ; // put the 2nd argument in GMm
    }
    if(argc>3) {
      sscanf( argv[3], "%lf", &a.x[1] ) ; // put the 3rd argument in x[1]
    }
    if(argc>4) {
      sscanf( argv[4], "%lf", &a.v[0] ) ; // put the 4th argument in v[0]
    }
    if(argc>5) {
      sscanf( argv[5], "%lf", &a.x[0] ) ; // put the 5th argument in x[1]
    }
    if(argc>6) {
      sscanf( argv[6], "%lf", &a.v[1] ) ; // put the 6th argument in v[1]
    }

       //showState( a );
       //cout << "Distance \t"<< ruler( a ) << endl;
       LeapFrog( a , dt, runcycles);
       //Force( a );
       //tester( a );
       return 0;

}
//x(0) = (1.5, 2), v(0) = (0.4, 0)
