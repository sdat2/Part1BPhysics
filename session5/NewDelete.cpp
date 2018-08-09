// NewDelete.cc
#include <iostream>
using namespace std;
void show( double *a , int N ){
  for( int n=0; n<N; n++ )
    cout << "a["<<n<<"]=\t" << a[n] << endl ;
}
int main() {
double *a ;
// This creates a pointer but doesn’t allocate any memory for the array
int N = 20 ;
a = new double[N] ; // allocates memory for a[0]..a[N-1]
for( int n=0; n<N; n++ )
a[n] = n*n ;
show( a , N ) ;
delete [] a ; // frees the memory
}
