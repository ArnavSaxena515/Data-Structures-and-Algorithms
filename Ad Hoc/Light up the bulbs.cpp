#include<bits/stdc++.h>
using namespace std;
main()
{
   long long int n,x,y;
    cin>>n>>x>>y;
    string bulbs;
    cin>>bulbs;
   long long int groups=0;
  long long  int cost = 0;
  bool check = false;
  long long int j;
    if(n==1)
    {
        if(bulbs[0] == '1')
        {
            cost = 0;
        }
        if(bulbs[0] == '0')
        {
            cost =y;
        }
    }
    else if(n!=1){
    for(long long int i = 0; i < n-1; i ++)
    {
        if(bulbs[i]=='0')
        {
            for(j=i; bulbs[j]!='1';j++)
            {
                if(j>=n)
                {
                    break;
                }
            }
            i=j;
            groups++;

        }
    }
    cout<<"Number of groups: "<<groups<<endl;
    if(groups == 0)
    {
        if(bulbs[0] == '1')
        {
            cost = 0;
        }
        else if(bulbs[0]=='0')
        {
            cost = y;
        }
    }
   else
    {
        cost = (groups-1) * min(x,y) + y;
    }
    }
   cout<<cost;
}
