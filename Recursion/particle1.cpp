#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
struct coordinates{
  int particle[4][2]; //convention - label position by left hand corner
  bool grid[10][10]; //let's store the fullness information in this part
};

void placer(coordinates &b, int k);
bool valid(coordinates &c, int x , int y, int size );
void blanker(coordinates &d, int x, int y, int size);

// global variables

int H = 10; // size of grid
int T = 3; // number of small particles
int Bs = 4; // size of Big
int Ss = 2; // size of Small
int Limit = 10; //limit number of outputs
int Heaters = 1; // number of heatmaps
int Heatmap[1][10][10]; //heatmap the position of the left hand corner of big particle
//heatmap the position of the left hand corner of the small particle
//by symmetry all the small particles should have the same heatmap
//to test this hypothesis the number of heatmaps could be increased

int main(void){
  coordinates a;

  for(int i = 0; i < H; i++){
      for(int j = 0; j < H; j++){
        a.grid[i][j] = false;
       }
     }

  for(int f = 0; f < Heaters; f ++){
      for(int i =0; i <H; i++){
        for(int j = 0; j < H; j++){
          Heatmap[f][i][j] = 0;
        }
      }
    }

  //run recursive function in all its glory
  placer(a , 3);

  //print heatmap results
  for(int f = 0; f < Heaters; f ++){
    cout << endl << "HeatMap Particle" << f;
    cout << endl;
    //print a nice grid
    for(int i=0; i < H; i++){ //row is i
        for(int j = 0; j < H; j++){ // column is j
                cout << Heatmap[f][j][i] << " \t";}
        cout << endl;
    }
    cout << endl;
  }
  return 0;
}

void placer(coordinates &b, int k){ //k initially 3
  if(k == -1 ){ //all particles placed
      //lets plot where those particles went this time in the heatmap
      for(int f = 0; f < Heaters; f ++){
        Heatmap[f][b.particle[f][0]][b.particle[f][1]] += 1;
      }
   }
  else {
    int size; // the first particle is the big one

    if (T-k == 0){
      size = Bs;}
    else {
      size = Ss;} // the rest are all the same size
      //iterate through all the possible positions

    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        if(valid(b, i, j, size)){ // if the placement suggested doesn't conflict lets place it
          coordinates g = b; //there was a bug created by repeated blanking
          //on successive runs of the loop - hopefully this fixes this.
          g.particle[T-k][0] = i; //the x component put in b
          g.particle[T-k][1] = j; // the y component put in b
          blanker(g, i , j, size); // blank out those pesky squares you just took up
          placer(g , k-1); // put the structure created so far in

        }
      }
    }
  }
    return;
}

//just check if corners are valid, and then interior safe.
bool valid(coordinates &c, int x , int y, int size ){
  if(y-(size-1) > -1 && x+(size-1) < 10){ // make sure it is not too large for box
    if( not c.grid[y][x] && not c.grid[y][x+(size-1)] && //make sure it does not clash with other particles
    not c.grid[y-(size - 1)][x] && not c.grid[y-(size-1)][x+(size -1)]){
      return true;
    }
  else{return false; }
  }
  else{return false; }
} //should make no changes
// check whether this new position does not hit any blanked out squares

void blanker(coordinates &d, int x, int y, int size){
  for(int j = 0; j < size; j++){
    for (int i = 0; i < size; i++) {
      d.grid[y-i][x+j] = true; // blocks out a section of the struct
    }
  }
} // lets blank out those squares that are now taken up /s
