//program to add two intgers typed by the user at the keyboard
#include <iostream>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{

  float X;

  cout << "Enter x" << endl;

  cin >> X;

  float total =X ;

  cout << total << endl;

  for(int f= 1; f< 40; f++){
    total = X + 1/total;
    cout << total << endl;
  }

  cout << "Hello Mac!"<< endl;
  return 0;

}
