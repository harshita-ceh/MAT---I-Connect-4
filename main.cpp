#include <iostream>
#include <unistd.h>
using namespace std;
int grid[6][7];
int choice,player;
bool end=false ;
int a=0;

void check(int x ){
  if(grid[x-1][a] !=0 && a<6){
    a++;
    check(x);
  }
  else if(player == 1 && a<6){
     grid[x-1][a] = 1;
     a = 0;
  }
  else if(player == 2 && a<6){
     grid[x-1][a] = 2;
     a=0;
  }
  else{
    cout<<"WRONG!"<<endl;
    a=0;
    player++;
  }
}
void draw(){
  system("clear");
  for(int i = 0; i<9; i++)
    {
        if(i<2)
        {
        cout<<"-";
        } else if(i>7)
        {
        cout<<i-1<<"--"<<endl;
        } else {
        cout<<i-1<<"----";
        }
    }
    for(int i = 0; i<6; i++)
    {
        for(int j = 0; j<7; j++)
        {
            if(grid[j][i]!=0)
            {
                if(grid[j][i]==1)
                {
                cout<<"| R |";
                }else cout<<"| B |";
            }
            else cout<<"|   |";
        } cout<<endl;
    }
    for(int i = 0; i<35; i++)
    {
        cout<<"=";
    } cout<<endl;
}

void win(){
for(int i = 0; i<6; i++)
    {
        for(int j = 0; j<7; j++)
        {
        if(grid[j][i]==1 && grid[j+1][i+1]==1 && grid[j+2][i+2]==1 && grid[j+3][i+3]==1)
            {
            bool end = true;
            cout << "\nPLAYER 1 WIN!" << endl;
            }
        if(grid[j][i]==1 && grid[j+1][i-1]==1 && grid[j+2][i-2]==1 && grid[j+3][i-3]==1)
            {
            cout << "\nPLAYER 1 WIN!" << endl;
           bool end = true;
            }
        if(grid[j][i]==2 && grid[j+1][i-1]==2 && grid[j+2][i-2]==2 && grid[j+3][i-3]==2)
            {
            cout << "\nPLAYER 2 WIN !" << endl;
            bool end=true;
            }
        else if(grid[j][i]==2 && grid[j-1][i-1]==2 && grid[j-2][i-2]==2 && grid[j-3][i-3]==2)
            {
           bool end = true;
            cout << "\nPLAYER 2 WIN!" << endl;
            }
        else if(grid[j][i]==1 && grid[j][i-1]==1 && grid[j][i-2]==1 && grid[j][i-3]==1)
            {
            cout << "\nPLAYER 1 WIN!" <<endl;
            bool end = true;
            }
        else if(grid[j][i]==1 && grid[j-1][i]==1 && grid[j-2][i]==1 && grid[j-3][i]==1)
            {
            cout << "\nPLAYER 1 WIN!" << endl;
            bool end = true;
            }
        else if(grid[j][i]==2 && grid[j][i-1]==2 && grid[j][i-2]==2 && grid[j][i-3]==2)
            {
            cout << "\nPLAYER 2 WIN!" <<endl;
            bool end = true;
            }
        else if(grid[j][i]==2 && grid[j-1][i]==2 && grid[j-2][i]==2 && grid[j-3][i]==2)
            {
            cout << "\nPLAYER 2 WIN!" <<endl;
           bool end = true;
            }
        }
    }
}


void p_choice()
{
   player = 1;
    bool end;
    while( end != true)
    {
    cout << "PLAYER " << player << ": ";
    cin >> choice;
        if (choice>0 && choice<8)
        {
            check(choice);
            draw();
            if (player == 1)
            {
                player++;
            }
            else
            {
                player--;
            }
        }
    else
        {
    cout << "WRONG CHOICE!" << endl;
        }
    win();
    }
}
int main() 
{
    system("clear");
    cout<<"WELCOME IN CONNECT 4"<<endl;
    sleep(1);
    draw();
    p_choice();
    cout<<"GAME ENDS!"<<endl;
    cout<<"-------------------------"<<endl;
    return 0;
}