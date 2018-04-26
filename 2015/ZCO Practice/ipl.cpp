#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000002
#define INF -1
ll dp[sz];
ll a[sz];

ll f(ll x,int y)
{
    if(x<0 || y==0){return 0;}
    else if(dp[x]!=-1){return dp[x];}
    else
    {
        if(y==2)
            dp[x]= max(f(x-1,0)+a[x], f(x));
        else if(y==1)
            dp[x]= max(f(x-2,))

        cout<<dp[x]<<" ";
        return dp[x];
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    memset(a,0,sizeof(a));
    ll i,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    dp[0]=a[0];
    dp[1]=a[0]+a[1];
    cout<<f(0,2)<<"\n";
    for(i=0;i<n;i++){cout<<dp[i]<<" ";}
    return 0;
}
