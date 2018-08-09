// Two factor calculator - recursive
#include <iostream>
#include <math.h>
using namespace std;



int twos(int b){
  if(fmod(b,2) == 0){
    return 1 + twos(b/2); }
  else{
    return 0; }
}

  int main (void) {
  int number;
  cout << "Please type a number: ";
  cin >> number;
  cout << number << " has " << twos(number) <<  " factor(s) of two " << endl;
  return 0;

}
