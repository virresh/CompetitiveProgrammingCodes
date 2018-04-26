#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[25],sum,dp[25];

ll ways(ll x)
{
    if(dp[x]!=-1)
    {
        return dp[x];
    }
    ll k=0;
    for(;k<)
}
int main()
{
    ll n,t,k;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        sum=0;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(n%k==0)
        {
            if(ways(n/k)!=0)
            {
                cout<<"yes\n";
            }
            else
            {
                cout<<"no\n";
            }
        }
        else
        {
            cout<<"no\n";
        }
    }
    return 0;
}
