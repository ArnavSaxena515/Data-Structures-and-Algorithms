#include<bits/stdc++.h>
using namespace std;
bool sortJobs(int jobs[], int n)
{
    if(n == 1 || n == 0)
    {
        return true;
    }
    for(int i = 0 ; i <n-1 ; i++)
    {
        if(jobs[i] > jobs[i+1])
        {
            if(abs(jobs[i] - jobs[i+1]) == 1)
            {
                int temp;
                temp = jobs[i];
                jobs[i] = jobs[i+1];
                jobs[i+1] = temp;
            }
            else
            {
                return false;
            }
        }
    }
}
main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n;
        cin>>n;
        int jobs[10000];
        for(int i = 0 ; i< n ; i++)
        {
            cin>>jobs[i];
        }
        bool check = sortJobs(jobs, n);
        if(check)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        t--;
    }
}

/*
*/
