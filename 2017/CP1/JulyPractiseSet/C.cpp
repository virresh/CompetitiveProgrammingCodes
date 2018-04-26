#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


ll fastExp(ll a,ll x)
{
    if(x==0)
    {
        return 1;
    }
    else if(x==1)
    {
        return a%mod;
    }
    else
    {
        ll p = fastExp(a,x/2);
        if(x%2==0)
        {
            return (p*p)%mod;
        }
        else
        {
            return (((p*p)%mod)*a)%mod;
        }
    }
}

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        ll i;
        cin>>i;

        ll twoP = fastExp(2,i-1);
        ll ans = (((i*i-i+2)%mod)*twoP -1 )%mod;
        cout<<ans<<"\n";

    }
	return 0;
}
