#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 200000

ll m,n,pow2[sz],a[sz],b[sz];
// a stores the number of periodic strings
// b stores nonperiodic strings
// a[n]= SUM(2^k - b[k]) for all k s.t n|k
// a[1]=0
// b[1]=2;
void compute()
{
    pow2[0]=1;  // 2^0 =1
    for(ll i=1;i<=n;i++)
    {
        pow2[i]=(pow2[i-1]<<1)%m;
    }
}
ll solve(ll x) // solve for nonperiodic strings with len=x
{
    if(b[x]!=-1){return (b[x]);}
    else if(a[x]!=-1)
    {
        b[x]=pow2[x]-a[x];
        return b[x];
    }
    if(x==1){a[1]=0; b[1]=2; return b[x];}
    queue <ll> q;   // to take out factors of x
    ll temp=0;
    for(ll i=2;i<=x/i;i++)
    {
        if(x%i==0)
        {
            q.push(i);
            if(x != i*i)
            {
                q.push(x/i);
            }
        }
    }
    q.push(1);
    while(!q.empty())
    {
        ll t=q.front();
        q.pop();
        //cout<<t<<"\n";
        temp= (temp + solve(t) )%m;
    }
    if(temp<0){temp+=m;}
    a[x]=temp;
    b[x]=pow2[x]-a[x];
    if(b[x]<0)
    {
        while(b[x]<0)
        {
            b[x]+=m;
        }
    }
    return b[x];
}
int main()
{
    cin>>n>>m;
    memset(a,-1,sizeof(a));
    memset(b,-1,sizeof(b));
    compute();
    cout<<solve(n)<<"\n";
    /*
    for(int i=0;i<=n;i++)
    {
        if(dp[i]!=-1)
            cout<<dp[i]<<" "<<i<<"\n";
    }*/
    return 0;
}
