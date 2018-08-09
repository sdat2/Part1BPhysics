// PrintWithCommas.cpp
// Enumerate all ternary strings by recursion
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int l = 0; //number to be used in recursive program
int f = 0; //ditto
int j; //initial integer from cin

//lace string N characters long
// if N != 0
// ELSE if Nmod3 characters != 0
// print first Nmod3 characters
// then print comma, contract string by 3
// ELSE if Nmod3 characters!= 0
// print first three characters, contract string by 3

// ELSE if N = 0
// print endl


void PrintWithCommas( char *remnant , int remainingLength ) {
  //cout << " R " <<  remainingLength << " R ";
  if (remainingLength == 0)
    cout << endl ;
  else {
          int b;
           if( 0 == fmod(remainingLength,3)){
             b = 3; } // Extend prefix by one character.
           else{
             b = fmod(remainingLength,3); }

           char *newremnant; //new bit made to store stuff
           newremnant = new char[remainingLength - b];

           for(int i = 0; i < remainingLength; i++){
                if( i < b){
                  cout << remnant[i];
                }
                else if(i == b){
                  cout << ",";
                  newremnant[0] = remnant[i];
                }
                else {newremnant[i - b] = remnant[i];} //get everything that hasn't been printed
           }

          PrintWithCommas( newremnant , remainingLength - b );

          }
          //return;
    }

void IntChar(char *lace, int length, int jnew, int f){
  if(f!=length){
    lace[length - f-1] = '0' + (char)(fmod(jnew,10)); // puts the correct character from the number into lace
    IntChar( lace, length, (jnew - fmod(jnew,10))/10 , f+1 ); // calls it again to do it with the next number
  }
}


int HowLongInt(int jnew, int l){
  if(jnew != 0){
    l ++; // there's digits left - increment l
    jnew = (jnew - fmod(jnew,10))/10; //take one digit away
    l = HowLongInt( jnew, l); // lets go again
  }
  return l; //finally each recursion returns l
}



int main () {

printf ("Enter a number: ");
cin >> j;
int length = HowLongInt( j , l ); //measure base 10 integer using recursion.
char *lace; //make pointer for character array
lace = new char[length] ; // make char* right length to hold number
IntChar(lace, length, j, f); // Use recursive function to put j into lace
//cout << j << "\t" << lace << "\t" << length << endl;
//char *prefix;
//word = new char[length];

cout << "The number with commas is: ";
PrintWithCommas( lace , length ) ;
//use recursive fucntion to put commas in betwen bits of lace
delete [] lace; //get rid of lace at the end of the program
return 0;
}
