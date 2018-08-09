#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;


// define some nice enum
enum gp {nought, cross, empty};
enum status {noughtwin, crosswin, nowin, draw};

// define neccessary global variables
bool ct = true;
bool valid;
gp grid[3][3];
status winstatus = nowin;
int size = 3;
int turn;


// declare function prototypes

void gridprint(gp grid[3][3]);
void blankgrid(void);
void newturn(void);
void newgame(void);
void move(void);
status check(gp grid[3][3]);
status comp(gp a, gp b, gp c);
void printstate(status winstatus);
void tester(void);
void gridinput(gp x1,gp x2,gp x3,gp x4,gp x5,gp x6,gp x7,gp x8,gp x9);


int main(void)
{
    winstatus = nowin;
    tester();
    newgame();
    return 0;
}

void blankgrid(void){
  for(int i=0; i < size ; i++)
      for(int j = 0;j < size; j++)
          grid[i][j] = empty;
}

// just in case I want to make the program cyclic
void newgame(void){
    winstatus = nowin;
    turn = 1;
       //interate through the array and make everything empty
    blankgrid();
    cout << endl << "Welcome to 2-d noughts and crosses!"  << endl
    << "Take note coordinates of grid go from row 0-2, then columns 0-2"<< endl
    << "Example input -- '1 2' -- which is a move to the right middle"  << endl;
     grid[1][2] = cross;
    gridprint(grid);
    cout << endl << endl;

    blankgrid();

    do{
        newturn();
        ct = not ct; //swaps turn
    }while(winstatus==nowin && turn<9);

    if(winstatus==nowin)
        winstatus = draw;
    //apparently someone won, let's print that

    gridprint(grid);
    printstate(winstatus);
}

// to make the program nice and cyclic
void newturn(void){

    if(ct)
        cout << "Crosses turn!";
    else
        cout << "Noughts turn!";
    move();
    //gridprint(grid);
    winstatus = check(grid);
}

void move(void){
        gridprint(grid);

        int a,b;
        valid = false;
        cout << "what is your move?"<< endl;
     do{
        cin >> a >> b;
        cout << endl;

        if(a>-1 && a<=2 && b<=2 && b>-1){
            if(grid[a][b]==empty && ct){
                valid = true; grid[a][b]=cross;
              }
            else if((grid[a][b]==empty) && not ct){
                valid = true; grid[a][b]=nought;
              }
            }

    }while(not valid);

}

void gridprint(gp grid[3][3]){
    cout << endl;
    //print a nice grid
    for(int i=0; i < 3; i++){

        cout << "|";

        for(int j = 0;j < size; j++){
            if (grid[i][j]==empty)
                cout << " -" << " |";
            else if(grid[i][j]==cross)
                cout << " X" << " |";
            else if(grid[i][j]==nought)
                cout << " O" << " |";
        }

        cout << endl;
    }
}




status check(gp grid[3][3]){
    status locwin = nowin;
    for(int i = 0; i < 3; i++){
        gp a = grid[i][0]; gp b = grid[i][1];gp c = grid[i][2];
        if(comp(a,b,c)!=nowin){
            locwin = comp(a,b,c);}
    }
    for(int i = 0; i < 3; i++){
        gp a = grid[0][i]; gp b = grid[1][i];gp c = grid[2][i];
        if(comp(a,b,c)!=nowin){
            locwin = comp(a,b,c);}
    }
    gp a = grid[0][0]; gp b = grid[1][1]; gp c = grid[2][2];
        if(comp(a,b,c)!=nowin){
            locwin = comp(a,b,c);}
    a = grid[2][0]; b = grid[1][1]; c = grid[0][2];
        if(comp(a,b,c)!=nowin){
            locwin = comp(a,b,c);}
    return locwin;

    //iterate over grid to check all possible win states
}

//actually check if those three array elements constitute a win
status comp(gp a, gp b, gp c){
    if( (a==b && b==c) && (a!=empty) && (b!= empty) && (c!=empty)){
        if(b == cross){
            return crosswin;}
        else if(b == nought){
            return noughtwin;}
        else{
            cout << "break in code";
            return nowin;}
    }
    else{
        return nowin;}

}

void printstate(status winstatus){
    if(winstatus==crosswin)
        cout << "Crosses Win!";
    else if(winstatus==noughtwin)
        cout << "Noughts Win!";
    else if(winstatus==nowin)
        cout << "error!";
    else if(winstatus==draw)
        cout << "Draw!";
    cout << endl;
}

//inputs lots of grids to check whether other functions work



void tester(void){

    blankgrid();
    gridprint(grid);
    winstatus = check(grid);
    printstate(winstatus);

    gridinput(nought,nought,nought,empty,cross,empty,empty,cross,empty);
    gridprint(grid);
    winstatus = check(grid);
    printstate(winstatus);

    gridinput(nought,cross,nought,empty,cross,empty,empty,cross,empty);
    gridprint(grid);
    winstatus = check(grid);
    printstate(winstatus);

    gridinput(nought,cross,nought,empty,cross,empty,nought,nought,nought);
    gridprint(grid);
    winstatus = check(grid);
    printstate(winstatus);

    blankgrid();
    gridprint(grid);
    winstatus = check(grid);
    printstate(winstatus);

    gridinput(cross,nought,cross,empty,cross,empty,empty,cross,empty);
    gridprint(grid);
    winstatus = check(grid);
    printstate(winstatus);

    gridinput(nought,cross,nought,empty,nought,empty,empty,cross,nought);
    gridprint(grid);
    winstatus = check(grid);
    printstate(winstatus);

    blankgrid();
    grid[0][0] = cross; grid[1][1] = cross;
    gridprint(grid);
    winstatus = check(grid);
    printstate(winstatus);

}

void gridinput(gp x1,gp x2,gp x3,gp x4,gp x5,gp x6,gp x7,gp x8,gp x9){
  grid[0][0] = x1;
  grid[0][1] = x2;
  grid[0][2] = x3;
  grid[1][0] = x4;
  grid[1][1] = x5;
  grid[1][2] = x6;
  grid[2][0] = x7;
  grid[2][1] = x8;
  grid[2][2] = x9;
}
