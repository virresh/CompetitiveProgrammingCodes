#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1005
#define INF 1000000005
ll arr[sz];
ll dp[sz][sz];
bool isPallindrome(ll *a, ll beg,ll en)
{
    int i=0;
    for(i=beg;i<=(beg+en)/2;i++)
    {
        if(a[i]!=a[beg+en-i]){return false;}
    }
    return true;
}
ll f(ll *a,ll beg,ll en)
{
    if(beg>en){return 0;}
    else if(isPallindrome(a,beg,en)){dp[beg][en]=1; return 1;}
    else if(dp[beg][en]!=-1){return dp[beg][en];}
    else
    {
        ll ans=INF,i;
        for(i=beg;i<en;i++)
        {
            ans=min(ans,f(a,beg,i)+f(a,i+1,en));
            //cout<<ans<<"\n";
        }
        dp[beg][en]=ans;
        return ans;
    }
}
int main()
{
    ll n,i;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<f(arr,0,n-1);
    return 0;
}
