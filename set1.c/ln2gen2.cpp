// ln2generator.cpp
// extensively uses code from RandDemo6.cc by Dr Lester
// This version produces no graphical result and instead just outputs the
// final value of fraction_in as a best estimate of ln2
//   usage:
//     ln2generator [<N> [<seed>]]
//   example:
//     ln2generator                  (Run with default value of N and seed)
//     ln2generator 30               (Run with N=30 and default seed)
//     ln2generator 30 9237832       (Run with N=30 and seed=9237832)
//   features:
//   * uses random() to get a random integer
//   * gets parameters from command line
//   * uses ternary operator "q ? a : b"
// with N = 10^7 only accurate to 3 d.p --> really quite bad for computing time


#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define ranf() \
  ((double)random()/(1.0+(double)RAND_MAX)) // Uniform from interval [0,1) */

double exponent(double y);

int main(int argc, char* argv[])
{
  int    outcome, N=100 , seed=113902 ;

  double fraction_in, count_in=0 ;

  if(argc>1)   {
    sscanf( argv[1], "%d", &N ) ; // put the first command-line argument in N
  }
  if(argc>2) {
    sscanf( argv[2], "%d", &seed ) ; // put the 2nd argument in seed
  }
  // Write out a summary of parameters
  cout << "# " << argv[0] << " N=" << N << " seed=" << seed << endl ;

  // Initialise random number generator
  srandom(seed);

  // Perform N experiments.
  for(int n=1; n<=N; n++) {
      double x = ranf() + 1; // ranf() returns a real number in [1,2)
      count_in += 1/x;
      //Integer variables must be converted (cast) for correct division
      fraction_in = static_cast<double>(count_in)/n;
  }
   cout << "estimate of ln(2):\t" << fraction_in << endl;
  return 0;
}
/*
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
*/
