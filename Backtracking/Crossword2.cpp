#include <bits/stdc++.h>
using namespace std;

int ways = 0;

void printMatrix(vector<string>& matrix, int n)
{
	for (int i = 0; i < n; i++)
    {
        for(int j = 0; j <n;j++)
		{
		    cout << matrix[i][j]<<" " ;
		}
		cout<<endl;
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
            if(words[j]=='/0')
            {
                break;
            }
            j++;
        }
        //cout<<endl<<"i: "<<i<<endl<<"j: " <<j;
        return words.substr(i-1,j-i+1);
    }
}


vector<string> checkHorizontal(int x, int y, vector<string> matrix, string currentWord)
{
	int n = currentWord.length();

	for (int i = 0; i < n; i++)
        {
		if (matrix[x][y + i] == '-' ||
			matrix[x][y + i] == currentWord[i]) {
			matrix[x][y + i] = currentWord[i];
		}
		else {


			matrix[0][0] = '@';
			return matrix;
		}
	}

	return matrix;
}


vector<string> checkVertical(int x, int y,
							vector<string> matrix,
							string currentWord)
{
	int n = currentWord.length();

	for (int i = 0; i < n; i++) {
		if (matrix[x + i][y] == '-' ||
			matrix[x + i][y] == currentWord[i]) {
			matrix[x + i][y] = currentWord[i];
		}
		else {

			matrix[0][0] = '@';
			return matrix;
		}
	}
	return matrix;
}


void solvePuzzle(vector<string>& words, vector<string> matrix, int index, int n)
{
	if (index < words.size())
        {
		string currentWord = words[index];
		int maxLen = n - currentWord.length();


		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= maxLen; j++) {
				vector<string> temp = checkVertical(j, i,
										matrix, currentWord);

				if (temp[0][0] != '@') {
					solvePuzzle(words, temp, index + 1, n);
				}
			}
		}

		for (int i = 0; i < n; i++)
            {
			for (int j = 0; j <= maxLen; j++)
			 {
				vector<string> temp = checkHorizontal(i, j, matrix, currentWord);

				if (temp[0][0] != '@') {
					solvePuzzle(words, temp, index + 1, n);
				}
			}
		}
	}
	else {


		printMatrix(matrix, n);
		cout << endl;


		ways++;
		return;
	}
}


int main()
{
	int n1 = 10;
	char m[10][10];
	for(int i = 0; i <10;i++)
    {
        for(int j = 0; j <10; j++)
        {
            cin>>m[i][j];
        }
    }


	vector<string> matrix;


	for(int i = 0; i <10;i++)
    {
        string temp="";
        int j;
        for( j = 0; j <10;j++)
        {
            temp = temp +m[i][j];
        }
        temp[j+1] = '\0';
       // cout<<endl<<"temp is : "<<temp;
        matrix.push_back(temp);
    }


	//printMatrix(matrix,10);
	string word;
	cin>>word;
	vector<string> words;
	int count = 1;
    for(int i = 0; word[i]!='\0';i++)
    {
        if(word[i] == ';')
        {
            count++;
        }
    }
        for(int i = 0; i < count; i ++)
        {
            words.push_back(getWord(word,i));
        }

        ways = 0;


	solvePuzzle(words, matrix, 0, n1);
	//cout << "Number of ways to fill the grid is "<< ways << endl;

	return 0;
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
