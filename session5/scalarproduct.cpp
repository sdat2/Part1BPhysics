// ScalarProduct.cc
// Calculating the scalar product between vectors input by user
#include <iostream>

using namespace std;
int main() {
float vectorA[3], vectorB[3], scalar=0.0;
// Get input vectors from user.
cout << "Enter elements of first vector: " << endl;
for(int i=0;i<3;i++)
{
      cin >> vectorA[i];
   }
cout << "Enter elements of second vector: " << endl;
for(int i=0;i<3;i++)
{
      cin >> vectorB[i];
   }
// Calculate scalar product.
for(int i=0;i<3;i++)
{
scalar = scalar + (vectorA[i] * vectorB[i]); }
// Output result.
cout << "The scalar product is " << scalar << endl; return 0;
}
