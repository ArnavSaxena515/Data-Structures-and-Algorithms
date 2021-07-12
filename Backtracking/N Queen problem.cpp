#include<bits/stdc++.h>
using namespace std;
int board[11][11];
bool checkvalid(int row, int column,int n)
{
    for(int i =0; i<row; i++)
    {

        if(board[i][column] == 1)
        {
            return false;
        }
    } // no attack in the column

    int r=row-1,c=column-1;
    while(r>=0 && c >=0) //upper left
    {
        if(board[r][c] == 1)
        {
            return false;
        }
        r--;
        c--;
    }

     r=row-1,c=column+1;
    while(r>=0 && c <n) //upper right
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

void help(int n,int row) //place the queem
{
    if(row == n)
    {
        for(int i=0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
        cout<<endl;
        return;
    }


       for(int j =0; j<n;j++)
       {
           if(checkvalid(row,j,n))
           {
               board[row][j] = 1;
               help(n,row+1);
               board[row][j] =0;
           }
       }
       return;

}

void placeQueens(int n)
{
    memset(board,0,11*11*sizeof(int));
    help(n,0);


}
main()
{
    int n;
    cin>>n;
    placeQueens(n);
    return 0;
}
