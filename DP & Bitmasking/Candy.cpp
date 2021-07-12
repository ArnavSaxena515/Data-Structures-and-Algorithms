/*
Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with different flavours. But the problem is some students like certain flavour while some doesn't. Now Gary wants to know the number of ways he can distribute these N candies to his N students such that every student gets exactly one candy he likes.
Input Format :
Line 1 : An integer N (1<= N <= 16) denoting number of students and candies.
Next N lines : N integers describing the preferences of one student. 1 at i'th (0 <= i < N) position denotes that this student likes i'th candy , 0 means he doesn't.
Assume input to be 0-indexed based.
Output Format :
Return the number of ways Gary can distribute these N candies to his N students such that every student gets exactly one candy he likes.`
*/
#include<bits/stdc++.h>
using namespace std;
#define MAXN 16
long long solve(int like[][MAXN], int n)
{
    // mask is 000000...n times
    int mask = 0;
    int *dp = new int[1<<n];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < (1<<n);i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int mask = 0; mask <((1<<n) - 1); mask++)
    {
        // count set bits in the mask;
        int temp = mask;
        int k = 0;
        while(temp >0)
        {
            if((temp % 2) == 1)
            {
                k++;
            }
            temp = temp/2;
        }
        // k is the number of set bits, representing the kids that have been given a candy
        // check for unset bits
        for(int j = 0; j < n; j++)
        {
            if(!(mask&(1<<j)) && like[k][j] )//jth bit of mask is unset
            {
                dp[mask| (1<<j)] += dp[mask];
            }
        }
    }
     /*for(int i = 0; i < (1<<n);i++)
    {
        cout<<dp[i]<<"  ";
    }
    */
    //cout<<endl;
    return dp[(1<<n) -1];
}
main()
{
    int n,like[MAXN][MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++){
			cin>>like[i][j];
		}
	}
	cout<<solve(like,n)<<endl;
}
