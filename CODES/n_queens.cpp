#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[16][16];//Creating an array which is representing chess-board(max size is 15*15).
int row_num[16]={0};//For storing the solution,the row number in corresponding column is stored in a sequence.
//isSafe()function tells whether the particular cell is safe wrt previous queens placed.
bool isSafe(int row,int col)
{
    for(int i=0;i<col;i++)//Traversing along the previous columns till where queens are placed already.
    {
        for(int j=0;j<n;j++)//finding the location of queen in the columns before col.(Traversing all rows)
        {
            if(arr[j][i]==1)//Wherever we get a 1,it means a queen is placed here.(So we found a queen)
            {
                if(j==row||j+i==row+col||j-i==row-col)//If the new cell is safe wrt the previous queens or not.
                    return false;                     //Three conditions:1.Same row as that of queen
                                                      //2.New cell comes in line of left diagonal of queen. 
                                                      //3.New cell comes in line of right diagonal of queen. 
                    
            }
        }
    }
    return true;//If it is not returning false above,it means that the provided cell isSafe.
}

void f(int col)//Starting from the 0th column we're trying to place the queen in every column if all the queens are safe,otherwise backtrack
{
    for(int row=0;row<n;row++)//trying for the first row in the column that is safe.
    {
        if(isSafe(row,col))//if the cell is safe to place the new queen,returns true.
        {
            arr[row][col]=1;//Place the queen on the chess-board.
            row_num[col+1]=row+1;//Appending row values in corressponding column for the output.
            if(col==n-1)//if we are in the last column.
            {
                cout<<"[";
                for(int i=1;i<=n;i++)
                {
                    cout<<row_num[i]<<" ";//Outputting the safe solution for queens.
                }
                cout<<"] ";
                arr[row][col]=0;//To look for more than one solutions,backtrack.
                row_num[col+1]=0;//Set the output values to zero.
                continue;//Continue for the next row in the column to find more solutions.
            }
                
            f(col+1);//Calling the same function again for the next column.
            arr[row][col]=0;//After returning from the function,backtrack and reset the cell to 0 again(no queen is placed in that cell now)
            row_num[col+1]=0;//Set the output values to zero.
        }   
    } 
    
}


int main() 
{
    int t;
    cin>>t;//Take input the number of testcases.
    while(t--)
    {
        cin>>n;//Take the size of row/column of the board
        memset(arr,0,sizeof(arr));//Setting the board values as 0.
        f(0);//Calling the function with col=0.
        cout<<endl;//Setting lines between the testcases.
    }
    
    return 0;
    
}
