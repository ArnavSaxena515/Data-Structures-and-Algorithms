#include<bits/stdc++.h>
using namespace std;
int countCost(string s, string t, int n)
{
    int cost = 0;
    for(int i = 0; i <n;)
    {
        if(s[i]!=t[i])
        {
            //either swipe or flip and increment cost
            if(i+1<n && s[i]!=s[i+1] && s[i+1]!=t[i+1])
            {
                i+=2;
            }
            else
            {
                i++;
            }
            cost++;
        }
        else
        {
            i++;
        }
    }
    return cost;
}
main()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s;
    cin>>t;
    cout<<countCost(s,t,n);
}
