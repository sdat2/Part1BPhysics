//program to add two intgers typed by the user at the keyboard
#include <iostream>
#include <stdio.h>
#include <iostream>

using namespace std;

double squareroot(double c);
double f(double x, double c);

int main(void)
{

  cout << "sqrt(3): " << squareroot(3) << endl;
  cout << "sqrt(2): " << squareroot(2) << endl;
  cout << "sqrt(5): " << squareroot(5) << endl;
  cout << "sqrt(8): " << squareroot(8) <<endl;
  for(int i = 0; i<10; i++){
    cout << "sqrt(" << (i+1) << "): " << squareroot((i+1)) << endl;
  }
}


// f(x)= c - x^2 , find x such that f(x) = 0
// given a value of c
double squareroot(double c){
  double p;
  double a=0;
  double b = (c + 1.1);
  while ( (b-a) > (0.000001)){
    //for( int i = 0; i < 10; i++){
    if(f(a,c)*f(b,c)<0 && a<b){
      //a < x < b
      p = (a + b)/2;

      if (f(p,c)*f(a,c)<0){
          b = p;
        }
      else if (f(p,c)*f(b,c)<0){
        a = p;
      }
      else if(f(p,c)==0)
        a = p,b = p;

      }
      //cout << p << "\t"<< a << "\t"<< b << endl;
    //}
    }
  return p;


}

double f(double x, double c){
  return (c - x*x);
}
