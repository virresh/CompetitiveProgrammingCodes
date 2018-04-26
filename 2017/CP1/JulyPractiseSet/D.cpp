#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ll n;
	cin>>n;
	ll a,b,c;
	cin>>a>>b>>c;

	ll n_a = n/(a) ,n_b = n/(b),n_c = n/(c), n_ab = n/(a*(b/(__gcd(a,b)))), n_ac = n/(a*(c/(__gcd(a,c)))), n_bc = n/(b*(c/(__gcd(b,c))));
	ll n_abc = n/((a/__gcd(a,b))*(b/(__gcd(b,c)))*(c/__gcd(c,a))*(__gcd(__gcd(a,b),c)));
	ll ans = n_a+n_b+n_c - n_ab - n_ac - n_bc + n_abc ;
	cout<<ans<<"\n";
	//cout<<n_a<<" "<<n_b<<" "<<n_c<<"\n";
	//cout<<n_ab<<" "<<n_bc<<" "<<n_ac<<"\n";
	return 0;
}
