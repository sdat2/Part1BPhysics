#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

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

struct coordinates{
  int particle[4][2]; //convention - label position by left hand corner
  bool grid[10][10]; //let's store the fullness information in this part
};

void placer(coordinates &b, int k);
bool valid(coordinates &c, int x , int y, int size );
void blanker(coordinates &d, int x, int y, int size);
void blankgrid(coordinates &a);
void printgrid(coordinates &a);
void HeatPrinter(int Bloop[10][10]);

int main(void){
  coordinates a;
  /* blankgrid( a );
  printgrid( a );
  placer( a, T+1);
  if(valid( a , 0 , 3, 2 )){
    cout << 1 << endl;
    blanker(a, 0, 3, 2);
    printgrid( a );
  }
  if(valid( a , 1 , 0, 2 )){
    cout << 1 << endl;
    blanker(a, 1, 0, 2);
  }*/
  for(int f = 0; f < Heaters; f ++){
    for(int i =0; i <H; i++){
      for(int j = 0; i < H; j++){
        Heatmap[f][i][j] = 0;
      }
    }
  }
  blankgrid( a );
  //printgrid( a );
  placer(a , 3); //
  for(int f = 0; f < Heaters; f ++){
    cout << endl << "HeatMap Particle" << f;
    HeatPrinter( Heatmap[f] );
  }
}

//place the  big particle somewhere valid
  //place the first small particle somewhere valid
    //place the second small particle somewhere valid
      //place the third small particle somewhere valid
//so now we have the total number of possible placements
// given the placement of the first one
// I mean I guess we could print the coordinates to a tmp file
// format Particle Big, Particle 2, Particle 3, Particle 4
//xx,yy\t xx,yy\t xx,yy\t xx,yy\t
// so 6*(T+1) characters needed to describe final state print out
// actually why not use a struct?
//recursive calling of a valid particle placer would wor
/*every time this function calls itself
I want it to pass a copy of the current structure
and pass it on itself  or print the results*/

void placer(coordinates &b, int k){ //k initially 3
  if(k == -1 ){ //all particles placed
    for(int i=0; i < T + 1 ;i++){
      cout << "|" << b.particle[i][0] // x coordinates
      << "," << b.particle[i][1]  // y coordinates
      << "|"; }
      //prints the coordinates of particles in order
      cout << endl;// //
      //lets plot where those particles went this time in the heatmap
      for(int f = 0; f < Heaters; f ++){
        Heatmap[0][b.particle[0][0]][b.particle[0][1]]++;
      }
      //increment the Heatmap position corresponding to the first particle;
     //printgrid( b );
   }
  else {
    int size; // the first particle is the big one
    if(T-k == 0){
      size = Bs;}
    else{
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
        else{
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
// check whether this new position does not hit any blanked
                // out squares

void blanker(coordinates &d, int x, int y, int size){
  for(int j = 0; j < size; j++){
    for (int i = 0; i < size; i++) {
      d.grid[y-i][x+j] = true;
      /* code?? */
    }
  }
} // lets blank out those squares that are now taken up /s

void blankgrid(coordinates &a){
 for(int i = 0; i < H; i++){
   for(int j = 0; j < H; j++){
     a.grid[i][j] = false;
      }
    }
  return;
} //this function definitely blanks out grid

void printgrid(coordinates &a){
  cout << endl;
  //print a nice grid
  for(int i=0; i < H; i++){
      cout << "|";
      for(int j = 0; j < H; j++){
          if (a.grid[i][j]==false)
              cout << " -" << " |";
          else if(a.grid[i][j]==true)
              cout << " X" << " |";}

      cout << endl;
  }
  cout << endl;
}

void HeatPrinter(int Bloop[10][10]){
  cout << endl;
  //print a nice grid
  for(int i=0; i < H; i++){ //row is i
      for(int j = 0; j < H; j++) // column is j
              cout << Bloop[j][i] << " \t";

      cout << endl;
  }
  cout << endl;
}
