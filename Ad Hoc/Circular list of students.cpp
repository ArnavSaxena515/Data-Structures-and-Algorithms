#include<bits/stdc++.h>
using namespace std;
main()
{
    int t;
    cin>>t;
   // int arr[12]={0,1,2,3,4,5,6,7,8,9,10,11};
    while(t)
    {
        int i,p;
        cin>>i>>p;
        for(int count = 0; count < p; count++)
        {
            i++;
            if(i>11)
            {
                i=0;
            }
        }
        cout<<i<<endl;
        t--;
    }
}
