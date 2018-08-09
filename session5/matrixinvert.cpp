
#include <iostream>
#include <cmath>
using namespace std;

double m[3][3];
double det;
void matrixprint(double matrix[3][3]);
void matrixenter(double matrix[3][3]);
void determinant(double matrix[3][3], double determinant);
void transposer(double matrix[3][3])
//Find M T , the transpose of the matrix.
// Find the determinant of each of the 2x2 minor matrices.
//Represent these as a matrix of cofactors as shown, and multiply each term
//by the sign indicated. The result of these steps is the adjugate matrix
//(sometimes also called the adjoint), notated Adj(M).
// Find the inverse by dividing the adjugate found in the
//previous step by the determinate from the first step.
int main(void){
 matrixenter(m);
 matrixprint(m);
 determinant(m, det);


}


void matrixprint(double matrix[3][3]){
    cout << endl;
    //print a nice grid
    for(int i=0; i < 3; i++){
        cout << "|";
        for(int j = 0;j < 3; j++){
                cout << m[i][j] << " |";
        }

        cout << endl;
    }
}

void matrixenter(double matrix[3][3]){
cout << "Enter elements of first column: " << endl;
for(int i=0;i<3;i++)
{
      cin >> m[i][0];
   }
cout << "Enter elements of second column: " << endl;
for(int i=0;i<3;i++)
{
      cin >> m[i][1];
   }
   cout << "Enter elements of third column: " << endl;
   for(int i=0;i<3;i++)
   {
         cin >> m[i][2];
      }
    }
//fmod is not an integer????? why not? how to convert

void determinant(double matrix[3][3], double determinant){
  // find determinant of standard 3 by 3 matrix
  determinant = 0;

  for(int i = 0; i < 3; i ++){
    determinant += matrix[0][i]*(matrix[1][fmod(i+1,3)]*matrix[2][fmod(i+2,3)]
    - matrix[1][fmod(i+2,3)]*matrix[2][fmod(i+1,3)]);
  }
  cout << "The determinant is:" << determinant << endl;
}
