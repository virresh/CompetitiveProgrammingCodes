#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000002
#define INF 1000000
ll dp[sz];
ll a[sz];
ll f(ll n)
{
    if(n<0){return INF;}
    else if(n<sz && dp[n]!=-1){return dp[n];}
    else
    {
        ll ans= min(f(n-1),f(n-2));
        ans=min(ans,f(n-3)) + a[n];
        if(n<sz) dp[n]=ans;
        return ans;
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    //memset(a,INF,sizeof(a));
    ll i,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    dp[0]=a[0];
    if(n>1)
    dp[1]=a[1];
    if(n>2)
    dp[2]=a[2];
    cout<<f(n);
    return 0;
}
