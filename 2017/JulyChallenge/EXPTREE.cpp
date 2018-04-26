#include <bits/stdc++.h>
using namespace std;

#define modA 1000000007
#define modB 1000000009
#define ll long long


ll fastPower(ll x, ll n, ll m)
{
    if(n==0)
    {
        return 1;
    }
    else if(n==1)
    {
        return x%m;
    }

    ll p = fastPower(x,n/2,m);
    if(n%2==0)
    {
        return (p * p)%m;
    }
    else
    {
        return ((x *((p*p)%m))%m);
    }
}


ll solve(ll n, ll &p, ll &q, ll mod)
{
    if(n==1)
    {
        p = 0;
        q = 0;
        return 0;
    }
    p = (n%mod)*((n-1)%mod)%mod;
    q = (2 * (2*(n % mod)%mod - 3 + mod)%mod)%mod;

    ll g = __gcd(p,q);
    p = p/g;
    q = q/g;

    ll qInv = fastPower(q,mod-2,mod);
    return ((p%mod)*(qInv%mod))%mod;
}

int main()
{

    ll T;
    cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        ll p,q;

        cout<<solve(n,p,q,modA)<<" "<<solve(n,p,q,modB)<<"\n";

    }
	return 0;
}
