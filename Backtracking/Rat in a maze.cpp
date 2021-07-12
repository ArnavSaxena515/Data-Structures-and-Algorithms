#include<bits/stdc++.h>
using namespace std;
int maze[20][20];
int path[400];
int pathsize = 1;
void printpath(int n)
{
    for(int i = 0; i < n*n; i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
bool checkValid(int row,int column,int n)
{
    if(maze[row][column] == 0)
    {
        return false;
    }
    if(row < 0 || column < 0 || row >= n || column >= n)
    {
        return false;
    }
    return true;
}

int pathindex(int row, int column, int n)
{
    int index;
    index = (row*n) + column;
    return index;
}

void mousehelper(int row,int column,int n)
{

    if(row == n-1 && column == n-1) // mouse is at destination
    {
        int index = pathindex(row,column,n);
        path[index] = 1;
        pathsize++;
        printpath(n);
        return;
    }

    // move down
    if(checkValid(row+1,column,n))
    {
        int index = pathindex(row+1,column,n);
        path[index] =1;
        pathsize++;
        maze[row][column] = 0;
        mousehelper(row+1,column,n);
        pathsize--;
        path[index] = 0;
        maze[row][column] = 1;
    }

    // move right
    if(checkValid(row,column+1,n))
    {
        int index = pathindex(row,column+1,n);
        path[index] =1;
        pathsize++;
        maze[row][column] = 0;
        mousehelper(row,column+1,n);
        pathsize--;
        path[index] = 0;
        maze[row][column] = 1;
    }
    // move left
    if(checkValid(row,column-1,n))
    {
        int index = pathindex(row,column-1,n);
        path[index] =1;
        pathsize++;
        maze[row][column] = 0;
        mousehelper(row,column-1,n);
        pathsize--;
        path[index] = 0;
        maze[row][column] = 1;
    }

    // move up
    if(checkValid(row-1,column,n))
    {
        int index = pathindex(row-1,column,n);
        path[index] =1;
        pathsize++;
        maze[row][column] = 0;
        mousehelper(row-1,column,n);
        pathsize--;
        path[index] = 0;
        maze[row][column] = 1;
    }
}
void moveMouse(int n)
{
    mousehelper(0,0,n);
}
main()
{
    int n;
    cin>>n;
    memset(maze,0,20*20*sizeof(int));
    memset(path,0,400);
    path[0]=1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>maze[i][j];
        }
    }
    cout<<endl;
    moveMouse(n);

}
/*
1 0 1
1 1 1
1 1 1
*/
