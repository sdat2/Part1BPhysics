
double exponent(double x);

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(void){
  double three = 3;
  cout << exponent(three) << endl;
  cout << exponent(4.0) << "/t" << exp(4) << endl <<
  cout << exponent(0) << exp(0) << endl;
  cout << exponent(1) << endl;
  cout << exponent(5) << endl;
}


double exponent(double x){
  double grandtotal = 1;
  double powertotal = x;
  double factorial = 1;
  for(int i=1; i<100; i++){
    factorial = factorial*i;
    grandtotal = grandtotal + powertotal/factorial;
    powertotal = powertotal*x;
  }
  return grandtotal;
}
