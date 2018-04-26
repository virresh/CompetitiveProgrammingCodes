#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000000
#define md 15746
int dp[sz];

int T(int x)
{
    int i=3;
    if(x>=sz){return (T(x-1)%md + T(x-2)%md)%md;}
    else if (dp[x]!=-1){return dp[x];}
    for(i=3;i<=x;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%md;
    }
    return dp[x];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    dp[1]=1; dp[2]=2;
    cout<<T(n);
    return 0;
}
