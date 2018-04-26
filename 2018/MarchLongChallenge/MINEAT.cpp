#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
 
ll findHours(ll speed, ll pile[], ll pSize){
	ll ans = 0;
	for(ll i=0; i<pSize; i++)
	{
		ans = ans + (ll)ceil(((double)pile[i])/((double)speed));
	}
	return ans;
}
 
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,h;
		cin>>n>>h;
		ll pile[n+5];
 
		for(ll i=0; i<n; i++)
		{
			cin>>pile[i];
		}
 
		ll lo = 0, hi = 10000000009;
		while(lo < hi)
		{
			ll mid = (lo+hi+1)/2;
			ll hT = findHours(mid,pile,n);
 
			// cout<<"lo - "<<lo << " high - "<<hi<<" | "<<mid<<" f(mid) - "<<hT<<"\n";
			if(hT > h){
				lo = mid;
			}
			else{
				hi = mid-1;
			}
		}
		cout<<lo+1<<"\n";
	}
	return 0;
}