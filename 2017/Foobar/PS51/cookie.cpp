#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz 100005
ll a[sz],b[sz];

int main()
{
	ll n,k;
	cin>>n>>k;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}

	for(int i=0; i<n; i++)
	{
		cin>>b[i];
	}

	ll hi=100000009,lo=0;
	while(lo<hi)
	{
		ll left=0;
		ll mid = (hi-lo+1)/2 + lo;

		for(int i=0; i<n; i++)
		{
			if(a[i]*mid > b[i])
			{
				left = left + a[i]*mid - b[i];
			}
		}
		if(left > k){
			hi = mid-1;
		}
		else{
			lo = mid;
		}
	}
	cout<<lo<<"\n";
	return 0;
}
