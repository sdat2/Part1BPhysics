//Bonk.cpp by Simon Thomas


using namespace std;
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <cstdio>



//one dimensional particle defined
struct particle {
  double x ; // position
  double p ; // momentum
  double im ; // inverse mass
  double v ; // velocity
  double T ; // kinetic energy
  double a ; // acceleration
  double t ; // keeps its own personal time
} ; // Note the definition of a structure ends with a semicolon

struct collision{
  double del;
  int particle[2];
};

struct particlepair{
  double v[2];
  double im[2];
};

// global variables


int N = 2; // number of particles
int collisions = 10;
int Length = 3;
double t = 0; // time
/*double Large = 1230; // arbitrary Large number
double small = 0.00000000001; //arbitrary small number
*/
//we could create a collision time matrix after every collision
//and search that matrix to find out which particles will collide next

// in order to create a system of N particles an array of N particles
// must be declared with particle[0] and particle[N] the two walls

particlepair Collide(particlepair d); //a function to Action collisions
particle LeapForward(particle nabla, double dt); // a function to deal with between collisions
// will alter particle array properties according to known laws
void ShowState(particle b[N+2]); // a function to print into gnuplot
// passed in by value
collision Iminent(particle z[N+2]); // compute collision time grid


//Default constants

int main(int argc, char* argv[]){

  if(argc>1)   {
    sscanf( argv[1], "%d", &N ) ; // put the 1st argument as the Number of particles
  }
  particle a[N+2];//create particle array

  for(int i =0; i < N + 1; i++){
    if(argc> N*i + 2)   {
      sscanf( argv[N*i+2], "%lf", &a[i].x) ; // put the 1st argument
    // in the first particle displacement
    }
  }
  for(int i =0; i < N + 1; i++){
    if(argc> N*i + 3)   {
      sscanf( argv[N*i+3], "%lf", &a[i].v) ; // put the 1st argument
    // in the first particle displacement
    }
  }
  for(int i =0; i < N + 1; i++){
    if(argc> N*i + 4)   {
      sscanf( argv[N*i+4], "%lf", &a[i].im) ; // put the 1st argument
    // in the first particle displacement
      }
    }

  // now we need to set wall particles key defining charactertistics
  a[0].x = 0; a[0].im = 0; a[0].v = 0;
  a[N+1].x = Length; a[N+1].im = 0; a[0].v = 0;

  //set particle
  a[N].x = 1.5; a[N].im = 1; a[N].v = 1;
  a[1].x = 1; a[1].im = 2; a[1].v = 2;

  for(int i = 0; i < N+2; i++){ // print out what we got in
      cout << a[i].x << "\t";
      cout << a[i].v << "\t";
      cout << a[i].im << "\t";
      cout << endl;
  }
   //ShowState( a );

   for(int k = 0; k < collisions; k++){
   collision h = Iminent( a );
   cout << h.del << "\t" << h.particle[0]<< "\t" << h.particle[1];
   cout << endl;

   cout << "Going to Collision Point" << endl;
   double split = 4;
   for(double l = 0; l < split; l++){
     double f = (h.del/split);
    for(int j = 0; j < N+2; j++){
      // pass each particle in
      a[j] = LeapForward( a[j], f);
    }
    ShowState(a);
  }
  //got to collision point
    int a = h.particle[0];
    int b = h.particle[1];

    //this is quite a silly way to do it; would be much better to pass whole
    // stack of particles to the function by reference but this produced bugs
    particlepair col;
    col.v[0] = a[a].v;
    col.v[1] = a[b].v;
    col.im[0] = a[a].im;
    col.im[1] = a[b].im;
    col = Collide(col);
    a[a].v = col.v[0];
    a[b].v = col.v[1];
    a[a].im = col.im[0];
    a[b].im = col.im[1];
    ShowState(a);


  }
    //t += dt;
  cout << "Bonk!" << endl;
  return 0;
}

particlepair Collide(particlepair d){ //a function to Action collisions
  double tmp;
  double u0 = (d.v[0]*d.im[1] + d.v[1]*d.im[0])*(d.im[1]+d.im[0]);
  //velocity of ZM frame
  d.v[0] = 2*u0 - d.v[0];
  d.v[1] = 2*u0 - d.v[1];

  return d;
}

particle LeapForward(particle nabla, double dt){
    nabla.x += nabla.v*dt;
    return nabla;
}

 // a function to deal with between collisions
void ShowState(particle b[N+2]){ // a function to print into gnuplot
  cout << t;
 for(int i = 0; i < N+2; i++){
   cout << b[i].x << "\t";
 }
 for(int i = 0; i < N+2; i++){
   cout << b[i].v << "\t";
 }
  double T = 0;
    for(int i = 0; i < N+2; i++){ if( b[i].im != 0){ T += 0.5*(b[i].v)*(b[i].v)/(b[i].im); }}
 cout << "\t" << T << endl;
}


collision Iminent(particle z[N+2]){
  collision temp; // the collision parameters that get finally returned
  temp.del = Large; // make the initial time estimate very large and non zero
  double delta; // a temporary value holder for time

  for(int i = 0; i< N+2; i++){
    for(int j = 0; j < N+2; j++){
      if (j>i){
        // do something only with this part of the array
        // the rest is symetrical and unnecessary

       if( (z[i].v == 0) && (z[j].v == 0)){ //REMOVE DIVBY0 ERRORS
         // do nothing if they are both 0
       }
       else{
       double delta = -(z[i].x -z[j].x)/(z[i].v-z[j].v);
       //cout << delta << endl;
        if(delta > 0 && temp.del > delta){
         temp.del = delta; // store how long it took, for next iteration
         temp.particle[0] = i;
         temp.particle[1] = j;// which particles are colliding?
         cout << temp.del << "\t" << temp.particle[0]<< "\t" << temp.particle[1];
         cout << endl;
         //
       }
      }
      }
    }
  }
  cout << "Collision Calculated." << endl;
  return temp;
  // give back the iminent collision specs
} // compute which object pair about to collide next
