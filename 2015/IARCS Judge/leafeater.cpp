#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 25
ll arr[sz];
ll gcd(ll a,ll b)
{
    ll x,y,r;
    x=max(a,b);
    y=min(a,b);

    while(y!=0)
    {
        r=x%y;
        x=y; y=r;
    }
    return x;
}
ll gcd_all(ll n)
{
    if(n==1){return a[0];}
    ll i,j=gcd(a[0],a[1]);
    for(i=2; i<n;i++)
    {
        j=gcd(j,a[i]);
    }
    return j;
}
ll lcm_all(ll n,ll g)
{
    ll p=1,i;
    for(i=0;i<n;i++)
    {
        p*=a[i];
    }
    p/=g;
}
int main()
{
    ll n,k,i,j,x,y;
    cin>>n>>k;
    for(i=0;i<k;i++)
    {
        cin>>a[i];
    }
    x=gcd_all(k);
    if(x==1)
    {

    }
    else
    {
        y=lcm_all(k,g);
    }
    return 0;
}
