#include<bits/stdc++.h>
#include<strings.h>
#include<string>
using namespace std;
char matrix[20][20];
bool filled[20][20];
int countWords(string words)
{
    int count = 1;
    for(int i = 0; words[i]!='\0';i++)
    {
        if(words[i] == ';')
        {
            count++;
        }
    }
    return count;
}
void printCrossword()
{
    for(int i = 0; i <10; i++)
    {
        for(int j = 0; j <10;j++)
        {
            cout<<matrix[i][j];
        }
    }
}
string getWord(string words, int index)
{
    if(index == 0)
    {
        int i;
        for(i = 0; words[i] != ';';i++);
        return words.substr(0,i);
    }
    else
    {
        int i;
        int count = 0;
        for(i = 0; count!=index; i++)
        {
            if(words[i] == ';')
            {
                count++;
            }
        }
        //cout<<endl<<"count: "<<count<<endl;
        i++;
        int j;
        j = i;
        while(j<words.length())
        {
            if(words[j]==';')
            {
                break;
            }
            /*if(words[j]=='/0')
            {
                break;
            }*/
            j++;
        }
        //cout<<endl<<"i: "<<i<<endl<<"j: " <<j;
        return words.substr(i-1,j-i+1);
    }
}
bool checkVertical(int row, int column, string word)
{
    // to fill, we need dashes required, word can be common
    for(int i = 0; i < word.length();i++)
    {
        if(matrix[row+i][column] == '-' || matrix[row+i][column] == word[i])
        {
            continue;
        }
        if(row+i >= 10 || column >=10)
        {
            return false;
        }
        if(matrix[row+i][column] == '+')
        {
            return false;
        }
    }
    return true;
}
bool checkHorizontal(int row, int column, string word)
{
    for(int i = 0; i < word.length(); i++)
    {
        if(matrix[row][column+i] == '-' ||matrix[row][column+i] == word[i])
        {
            continue;
        }
        if(row >= 10 || column + i >=10)
        {
            return false;
        }
        if(matrix[row][column+i] == '+')
        {
            return false;
        }
    }
    return true;
}
void setVertical(int row, int column, string words, int index)
{
    string word = getWord(words,index);
    for(int i = 0; i < word.length();i++)
    {
        if(matrix[row+i][column] == word[i])
        {
            filled[index][i] = false;
        }
        else if(matrix[row+i][column] =='-')
        {
           matrix[row+i][column] = word[i];
           filled[index][i] = true;
        }
    }
}
void setHorizontal(int row, int column, string words, int index)
{
    string word = getWord(words,index);
    for(int i = 0; i < word.length();i++)
    {
        if(matrix[row][column+i] == word[i])
        {
            filled[index][i] = false;
        }
        else if(matrix[row][column+i] =='-')
        {
           matrix[row][column+i] = word[i];
           filled[index][i] = true;
        }
    }
}
void resetVertical(int row, int column, int length, int index)
{
    for(int i = 0; i < length; i++)
    {
        if(filled[index][i] == true)
        {
            matrix[row+i][column] = '-';
        }

    }
}
void resetHorizontal(int row, int column, int length, int index)
{
    for(int i = 0; i < length; i++)
    {
        if(filled[index][i] == true)
        {
            matrix[row][column+i]= '-';
        }
    }
}
bool helpSolve(string words, int index, int n)
{
    if(n == 0)
    {
        return true;
    }
    for(int i =0; i <10; i++)
    {
        for(int j = 0; j <10; j++)
        {
            //vertical
            if(checkVertical(i, j, getWord(words,index)))
            {
                setVertical(i,j,getWord(words,index), index);
                if(!helpSolve(words,index+1,n-1))
                {
                    string w = getWord(words,index);
                    resetVertical(i,j,w.length(),index);
                    return false;
                }
            }

            else if(checkHorizontal(i,j,getWord(words,index)))
            {
               {
                   setHorizontal(i,j,getWord(words,index),index);
                   if(!helpSolve(words,index+1,n-1))
                    {
                        string w = getWord(words,index);
                        resetHorizontal(i,j,w.length(),index);
                        return false;
                    }
               }
            }
           /* else
            {
                return false;
            }*/
        }
    }
}
void solveCrossword(string words, int n)
{
    helpSolve(words,0,n);
    printCrossword();
}
main()
{
    memset(filled,false,10*10*sizeof(bool));
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10 ; j++)
        {
            cin>>matrix[i][j];
        }
    }
    string words;
    cin>>words;
    int n = countWords(words);
    solveCrossword(words,n);

}
/*
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
*/
