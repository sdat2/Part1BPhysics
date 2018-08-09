//program that solves a range of quadratics by bisection;

#include <iostream>
#include <stdio.h>
#include <iostream>

using namespace std;

//f(x) = p1*x^2 + p2*x + p3
// find x such that f(x) = 0

double p[3]; //quadratic coefficients
double l[2]; //limits
int steps; // interesting efficiency information

double Rootfinder(double p[3], double l[2]);
double f(double p[3], double x);
void outputprinter(void);

int main(int argc, char* argv[])
{
  //tests a variety of possible functions

  p[0]=-1;p[1]=0;p[2]=5;
  l[0]=0;l[1]=5;
  outputprinter();

  p[0]=-1;p[1]=0;p[2]=2;
  l[0]=0;l[1]=2;
  outputprinter();

  p[0]=1; p[1]=0; p[2]=-5;
  l[0]=0;l[1]=5;
  outputprinter();

  p[0]=2; p[1]=0; p[2]=-5;
  l[0]=0;l[1]=5;
  outputprinter();

  p[0]=2; p[1]=1; p[2]=-4;
  l[0]=0;l[1]=5;
  outputprinter();

  p[0]=10; p[1]=-2; p[2]=-4;
  l[0]=0;l[1]=1000;
  outputprinter();

  p[0]=0; p[1]=-2; p[2]=-4;
  l[0]=-100;l[1]=100;
  outputprinter();

  p[0]=1000; p[1]=-500; p[2]=-100;
  l[0]=0;l[1]=5000;
  outputprinter();


  return 0;
}

void outputprinter(void){
  cout << endl << "Function:   " << p[0] << "x^2 + " << p[1] << "x +  "
  << p[2] << "" << endl << "Between "<< l[0] << " and " << l[1] << endl;
  cout << "Root  x  = " << Rootfinder(p,l) << endl <<
  "Was completed in "<< steps << " Steps" <<endl << endl;

}


double Rootfinder(double p[3], double l[2]){
  double est; // local variable for root approx
  steps = 0;
  //l[0]=0;
  //l[1] = (p[3] + 1.1);
  while ( (l[1]-l[0]) > (0.000001)){
    //for( int i = 0; i < 10; i++){
    if(f(p, l[0])*f(p, l[1])<0 && l[0]<l[1]){ //checks if root in range
      //a < x < b
      est = (l[0] + l[1])/2;// find bisector

      if (f(p,est)*f(p,l[0])<0){ // if true there must be root must be between lim and est
          l[0] = l[0]; l[1] = est;}
      else if (f(p,est)*f(p,l[1])<0){ // if true in upper range
        l[0] = est; l[1] = l[1];}
      else if(f(p,est)==0){ // if true root found
        l[0] = est; l[1] = est;}
      }
    else{
      cout << "error!" << endl;} // if no sign change between limits
      // or if limits put wrong way round
      //cout << p << "\t"<< a << "\t"<< b << endl;
    //}
    steps++;
    }
  return est;
}

double f(double p[3], double x){
  return (p[0]*x*x + p[1]*x + p[2]); //calculates quadratic
}
