#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz 10005
ll n,k;
pair<ll,ll> aid[sz];
ll a[sz],d[sz],b[sz],bSum[sz+5], prefixSum[sz+5];

ll getSum(int l, int r){
	// sum from index l to r inclusive
	return prefixSum[r] - prefixSum[l] + d[l];
}

ll binSearchEnd(int l, int r, int val){
	for(int i=1; i<=100; i++)
	{
		if(getSum(0,r-1) < val && i!=100)
		{
			if(2*r >= n){
				r = n-1;
			}
			else{
				r = 2*r;
			}
		}
		else
		{
			l = r;
			r = (r+l)/2;
		}
	}
	return r-1;
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(ll i=0; i<n; i++)
		{
			cin>>a[i];
			aid[i].first = a[i];
		}
		for(ll i=0; i<n; i++)
		{
			cin>>d[i];
			aid[i].second = d[i];
			if(i==0){
				prefixSum[i] = aid[i].first * aid[i].second;
			}
			else{
				prefixSum[i] = aid[i].first * aid[i].second + prefixSum[i-1];
			}
		}
		sort(aid,aid+n);
		for(ll j=0; j<n; j++)
		{
			d[j] = aid[j].second;
			a[j] = aid[j].first;
			if(j==0){
				prefixSum[j] = d[j];
			}
			else{
				prefixSum[j] = d[j] + prefixSum[j-1];
			}

		}

		for(ll i=0; i<k; i++)
		{
			cin>>b[i];
		}

		for(int k=0; k<n; k++)
		{
			cout<<d[k]<<" ";
		}
		cout<<"\n";
		cout<<binSearchEnd(1,1,7)<<"\n";

		// for(ll j=0; j<n; j++)
		// {
		// 	cout<<aid[j].first<<" "<<aid[j].second<<"\n";
		// }

		ll first = 0;
		ll last = n-1;

		for(ll i=0; i<k && first < n && last >= 0; i++)
		{
			// chef -> even, bro -> odd
			if(i%2==0)
			{
				ll toKeep = b[i];
				ll tempLast = last;
				while(toKeep > 0 && first < n && last >= 0)
				{
					if(aid[tempLast].second >= toKeep){
						aid[tempLast].second = toKeep;
						toKeep = 0;
					}
					else{
						toKeep = toKeep - aid[tempLast].second;
						tempLast--;
					}
				}
				first = tempLast;
			}
			else
			{
				ll toKeep = b[i];
				ll tempFirst = first;
				while(toKeep > 0 && first < n && last >= 0)
				{
					if(aid[tempFirst].second >= toKeep){
						aid[tempFirst].second = toKeep;
						toKeep = 0;
					}
					else{
						toKeep = toKeep - aid[tempFirst].second;
						tempFirst++;
					}
				}
				last = tempFirst;
			}
		}
		ll ans = 0;
		for(ll j=first; j<=last; j++)
		{
			ans = ans + aid[j].second * aid[j].first;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
