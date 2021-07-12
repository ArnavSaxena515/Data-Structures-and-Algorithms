#include<bits/stdc++.h>
using namespace std;
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
main()
{
    long int n;
    cin>>n;
    int arr[n];
    bool flag = true;
    for(int i = 0; i < n; i ++)
    {
        cin>>arr[i];
    }
    // swappable only with the index directly at front
    // one player can swap twice at max;
    //sort arr now
    int swaps = 0;
    for(int i = n-1;i>=0;i--)
    {
        if(arr[i]==i+1)
        {
            continue;
        }
        else
            if(arr[i-1]==i+1 && (i-1)>=0)
        {
            int temp = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = temp;
            swaps++;
        }
        else if (arr[i-2] == i+1 && (i-2) >=0)
        {
            int temp;
            arr[i-2] = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = i+1;
            swaps+=2;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        cout<<"YES"<<endl;
        cout<<swaps;
    }
    else
    {
        cout<<"NO";
    }

}
