#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,k,l;
    cin>>n>>k>>l;
    // k first op. l second op;
    int arr[n];
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i = 0; i < n ; i++)
    {
        cin>>arr[i];
        if(arr[i] <min)
        {
            min = arr[i];
        }
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    int min_cost=INT_MAX;
    cout<<"Min is: "<<min<<"\tMax is: "<<max<<endl;
    for(int x = min; x <=max;x++)
    {
        int increase = 0, decrease = 0, cost = 0;
        for(int i = 0; i < n; i ++)
        {
            if(arr[i]<x)
            {
                increase = increase + x-arr[i];
            }
            if(arr[i]>x)
            {
                decrease = decrease + arr[i]-x;
            }
        }
        cout<<"Increase is: "<<increase<<"\tDecrease is: "<<decrease<<"\tX is: "<<x<<endl;
        if(decrease <= increase)
        {
            cost = cost+ decrease * k;
            cost = cost+ (increase-decrease)*l;
            cout<<"Cost is: "<<cost<<endl;
            if(cost < min_cost)
            {
                min_cost = cost;
            }
            cout<<"Min cost  is : "<<min_cost;
        }
        else
        {
            continue;
        }
        cout<<endl<<endl<<endl;
    }
    cout<<min_cost;

}
