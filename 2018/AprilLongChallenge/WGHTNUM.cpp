#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1000000007ll;
map<int,int> precompute;

ll fastExp(ll a, ll pow)
{
	ll res = 1;
	while(pow > 0)
	{
		if(pow & 1)
		{
			res = (res * a)%mod;
		}
		pow = pow >>1;
		a = (a*a)%mod;
	}
	return res;
}

int main()
{
	for(int w=-300; w<=300; w++)
	{
		precompute[w] = 0;
	}
	for (int i = 10; i <= 99; ++i)
	{
		int w = i%10 - i/10;
		precompute[w]++;
	}

	ll t;
	cin>>t;
	while(t--)
	{
		ll n,w;
		cin>>n>>w;
		// cout<<fastExp(10,n-2)<<" "<<n<<"\n";
		ll ans = (precompute[w] * fastExp(10,n-2))%mod;
		cout<<ans<<"\n";
	}
	return 0;
}
