#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1600][40];
/*
ID: virresh1
PROG: subset
LANG: C++
*/

ll f(int n,int k)
{
    if(n==0 && k==0){return 1;}
    if(n!=0 && k==0){return 0;}
    if(n<0 || k<0){return 0;}
    if(dp[n][k]!=-1){return dp[n][k];}
    ll p= f(n,k-1)+f(n-k,k-1);
    dp[n][k]=p;
    return dp[n][k];
}
int main()
{
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int q=(n*(n+1))/2;
    if(q%2!=0){cout<<"0\n";}
    else
    {
        cout<<f(q/2,n)/2<<"\n";
    }
    return 0;
}
