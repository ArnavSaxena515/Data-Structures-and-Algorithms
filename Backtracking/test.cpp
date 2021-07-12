#include<bits/stdc++.h>
#include<strings.h>
#include<string>
using namespace std;
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
main()
{
    string words;
    char t;
    do
    {
        string w;
        cin>>words;
        int index;
        cin>>index;
        w= getWord(words,index);
        cout<<endl<<"length of word is : "<<w.length();
        cout<<endl<<w<<endl<<endl;
        cout<<endl<<endl<<"Number of words: "<<countWords(words);
        cin>>t;
        vector<string> wo;
        int x=0;
        int count = countWords(words);
        /*for(int i = 0; i<words.length();i++)
        {
            if(words[i] == ';')
            {
                cout<<endl<<"pushing string: "<<words.substr(x,i-1);
                wo.push_back(words.substr(x,i-1));
                x=i+1;
            }
        }*/

        for(int i = 0; i < count; i ++)
        {
            wo.push_back(getWord(words,i));
        }
        cout<<endl<<endl<<endl;
        vector<string>::iterator it;
        it = wo.begin();
        while(it<wo.end())
        {
            cout<<*it<<"  ";
            it++;
        }

    }
    while(t == 'y' || t == 'Y');
}
