// factorial calculator - recursive
#include <iostream>

using namespace std;


int factorial (int a) {
if (a > 1)
return (a * factorial (a-1));
  else
   return (1);
}

int main (void) {
int number;
cout << "Please type a number: ";
cin >> number;
cout << number << "! = " << factorial(number) << endl;
return 0;
}
