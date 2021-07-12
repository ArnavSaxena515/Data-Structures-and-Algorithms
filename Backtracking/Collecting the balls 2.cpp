#include<bits/stdc++.h>
using namespace std;
bool checkBalls(long long int n, long long int k)
{
   long long  int sharma=0,singh=0;
   long long int temp = n;
    while(temp > 0)
    {
        if(temp >=k)
        {
            temp=temp-k;
            sharma=sharma+k;
            singh = singh+  temp/10;
            temp=temp-temp/10;

        }
        else if (temp < k)
        {
            sharma = sharma + temp;
            temp = 0;
        }
    }
        cout<<endl<<"Candies remaining: "<<temp<<"\t"<<"Sharma has: "<<sharma<<"\tSingh has: "<<singh;

    if(sharma >= singh)
    {
        cout<<endl<<k<<" value satisfies";
        return true;
    }
    else
    {
        cout<<endl<<k<<" value does not satisfy";
        return false;
    }
}
main()
{
   long long int n;
    cin>>n;
    int start = 1, end = n, mid ,ans=n;
    while( start <= end)
    {
        mid = start + (end-start)/2;
        cout<<endl<<"start is : "<<start<<"\tmid is : "<<mid<<"\t end is : "<<end<<"\t ans is "<<ans;

        if(checkBalls(n,mid))
        {
            if(mid < ans)
            {
                ans = mid;
            }
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
        cout<<endl;
    }
    cout<<endl<<ans;
}
