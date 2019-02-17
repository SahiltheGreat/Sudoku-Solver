#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define N 9
#define UNASSIGNED 0
bool FindUnassLoc(int grid[N][N],int& row,int& col);
bool isSafe(int grid[N][N],int row,int col,int num);
bool Solve(int grid[N][N]);
void printGrid(int grid[N][N]);
int main()
{
    int i,j,arr[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    cout<<"The output of the entered values is: "<<endl;
    if(Solve(arr)==true)
    printGrid(arr);
    
    else
    {
        cout<<"No Solution exists!"<<endl;
    }
    return 0;
}
bool Solve(int grid[N][N])
{
    int row,col;
    if(!FindUnassLoc(grid,row,col))
    return true;
    for(int num=1;num<=9;num++)
    {
        if(isSafe(grid,row,col,num))
        {
            grid[row][col]=num;
            if(Solve(grid))
            return true;
            grid[row][col]=UNASSIGNED;
        }
    }
    return false;
}
bool FindUnassLoc(int grid[N][N],int &row,int &col)
{
    for(row=0;row<N;row++)
        for(col=0;col<N;col++)
            if(grid[row][col]==UNASSIGNED)
            return true;
            return false;

}
bool UsedinRow(int grid[N][N],int row,int num)
{
    for(int col=0;col<N;col++)
        if(grid[row][col]==num)
            return true;
        return false;
}
bool UsedinCol(int grid[N][N],int col,int num)
{
    for(int row=0;row<N;row++)
    if(grid[row][col]==num)
        return true;
    return false;
}
bool UsedinBox(int grid[N][N],int boxStartRow,int boxStartCol,int num)
{
    for(int row=0;row<3;row++)
        for(int col=0;col<3;col++)
            if(grid[row+boxStartRow][col+boxStartCol]==num)
                return true;
            return false;
}
bool isSafe(int grid[N][N],int row,int col,int num)
{
    return !UsedinRow(grid,row,num)&& !UsedinCol(grid,col,num)&&!UsedinBox(grid,row-row%3,col-col%3,num)&&grid[row][col]==UNASSIGNED;
}
void printGrid(int grid[N][N])
{
    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        cout<<grid[row][col]<<" ";
        cout<<endl;
    }
}
