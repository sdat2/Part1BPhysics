// allStrings.cc
// Enumerate all ternary strings by recursion
#include <iostream>
using namespace std;

void appendAllStrings( char *prefix , int remainingLength ) {
  if (remainingLength == 0)
    cout << prefix << endl ;
    else {
      int lp = strlen(prefix) ;
      for ( int i = 0 ; i <= 2 ; i ++ ) { // Extend prefix by one character.
            prefix[lp] = i+'0' ; // By adding i to the character ’0’
              // we get the characters ’0’, ’1’, ’2’
            appendAllStrings( prefix , remainingLength-1 );
          }             // Remove what was added
      prefix[lp] = '\0' ;   // [ ’\0’ is the null character ]
    }
    return;
}

int main () {
int length;
cout << "Please type a length: ";
cin >> length;
char *prefix ;
prefix = new char[length] ;
appendAllStrings( prefix , length ) ;
delete [] prefix ;
return 0;
}
