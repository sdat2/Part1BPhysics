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
} ; // Note the definition of a structure ends with a semicolon

//this is maybe a slightly unnecessary structure
struct collision{
  double del;
  int particle[2];
};
// global variables


int N = 1; // number of particles
int Length = 3;
double t = 0; // time
double Large = 1230; // arbitrary Large number
double Small = 0.00000000001; //arbitrary small number

// in order to create a system of N particles an array of N particles
// must be declared with particle[0] and particle[N] the two walls

//void Collide(paticle &delta[N+2]); //a function to Action collisions
void LeapForward(particle &nabla[N+2], double dt); // a function to deal with between collisions
// will alter particle array properties according to known laws
void ShowState(particle beta[N+2]); // a function to print into gnuplot
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


  for(int i = 0; i < N+2; i++){ // print out what we got in
    cout << a[i].x << "\t";
    cout << a[i].v << "\t";
    cout << a[i].im << "\t";
    cout << endl;
    }
   //ShowState( a );
   collision happy = Iminent( a );
   cout << happy.del << "\t" << happy.particle[0]<< "\t" << happy.particle[1];
   cout << endl;

   cout << "Going to Collision Point";
   double split = 4;
   for(double i = 0; i < split; i++){
     double f = (happy.del/split)*i;
    LeapForward( *a , f );
  }
  cout << "Bonk!" << endl;
  return 0;



}

//void Collide(); //a function to Action collisions

void LeapForward(particle &nabla[N+2], double dt){
  t += dt;
  for(int i = 0; i < N; i ++){
    nabla[i+1].x += nabla[i+1].v*dt;
  }
  cout << ShowState(nabla)
}

 // a function to deal with between collisions
void ShowState(particle beta[N+2]){ // a function to print into gnuplot
  cout << t;
 for(int i = 0; i < N+2; i++){
   cout << beta[i].x << "\t";
 }
 cout << endl;
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

         //testing
         cout << temp.del << "\t" << temp.particle[0]<< "\t" << temp.particle[1];
         cout << endl;
         //
       }
      }
      }
    }
  }
  cout << "Collision Calculated." << endl; return temp;
  // give back the iminent collision specs
} // compute which object pair about to collide next
