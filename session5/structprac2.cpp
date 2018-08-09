#include <stdio.h>

#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>
using namespace std;

struct StudentType{
   char  name[100];
   int   age;
   int   entryYear;
   float marks[5];
   char  college[20];
};

const int Mon=0, Tue=1, Wed=2, Thu=3, Fri=4, Sat=5, Sun=6;

/*
struct Name{
  char firstname[17];
  char secondname[17];
};
*/

int main(void){

  StudentType person;
  StudentType firstYear[400];

  person.age = 19;
  firstYear[205].entryYear = 1999;

  firstYear[24] = person;

  for(int i=0; i< 400; i++) {
firstYear[i].entryYear = 1999; }

cout << firstYear[24].age << endl;

int day = Tue;
cout << day << endl;

 /*
  Name one;
  one.firstname = "Simon";
  one.secondname = "Thomas";
  */
}
