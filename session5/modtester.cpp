#include <math.h>
#include <iostream>
using namespace std;


int main(void){
  int a = 1, b = 2;
  cout << a << b << fmod(b,a) << fmod(a,b) << endl;
  a = 2;
  b = 5;
  cout << a << b << fmod(b,a) << fmod(a,b) << endl;
  a = 1;
  b = 6;
  cout << a << b << fmod(b,a) << fmod(a,b) << endl;

}
