#include<bits/stdc++.h>
using namespace std;
int board[11][11];
bool checkValid(int n,int row,int column)
{
    // check same column attack;
    for(int i =0; i<row; i++)
    {
        if(board[i][column] == 1)
        {
            return false;
        }
    }

    //upper left;
    int r = row-1;
    int c = column-1;
    while(r >=0 && c>=0)
    {
        if(board[r][c] == 1)
        {
            return false;
        }
        r--;
        c--;
    }
    r = row-1;
    c = column+1;
    while(r >=0 && c < n)
    {
        if(board[r][c] == 1)
        {
            return false;
        }
        r--;
        c++;
    }

    return true;
}

void queenhelper(int n, int row)
{
    if(row == n)
    {
        for(int i =0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    for(int j = 0; j<n;j++)
    {
        if(checkValid(n,row,j))
        {
            board[row][j] =1;
            queenhelper(n,row+1);
            board[row][j] = 0;
        }

    }
    return;
}
void placeQueens(int n)
{
    memset(board,0,11*11*sizeof(int));
    queenhelper(n,0);
}
main()
{
    int n;
    cin>>n;
    placeQueens(n);
    return 0;
}
