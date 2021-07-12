#include<bits/stdc++.h>

using namespace std;
bool merge(int jobs[], int start,int mid, int end)
{
    int temp[10000];
    int i = start, j = mid+1, k = start;
    while(i <= mid && j <end)
    {
        if(jobs[i] > jobs[j])
        {
            if(abs(jobs[i] - jobs[j]) == 1)
            {
                temp[k++] = jobs[i++];
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(abs(jobs[i] - jobs[j] == 1))
            {
                temp[k++] = jobs[j++];
            }
            else
            {
                return false;
            }
        }
    }

}
void mergeSort(int jobs[], int start, int end)
{
    if(start>end)
    {
        return;
    }
    int mid = start+ (end-start)/2;
    mergeSort(jobs,start,mid);
    mergeSort(jobs,mid+1,end);
    if(!merge(jobs,start,mid,end))
    {
        cout<<"NO";
        return;
    }

}
void sortJobs(int jobs[],int n)
{

   int start = 0;
   int end = n;
    mergeSort(jobs,start,end);
}
main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n;
        int jobs[10000];
        cin>>n;
        for(int i = 0; i < n ; i++)
        {
            cin>>jobs[i];
        }
        t--;
    }
}
