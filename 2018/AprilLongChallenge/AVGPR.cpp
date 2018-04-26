#include <bits/stdc++.h>
using namespace std;

#define sz 100005
#define offset 1000
#define ll long long
ll arr[sz];
ll freq[sz];

int main()
{
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(freq,0,sizeof(freq));
		ll ans = 0;
		for(ll i=0; i<n; i++)
		{
			cin>>arr[i];
			arr[i] = arr[i] + offset;
			freq[arr[i]]++;
		}
		for(ll i=0; i<=2000; i++)
		{
			if(freq[i]==0){
				continue;
			}
			ll Ak = 2*i;
			for(ll j=0; j<=2000; j++)
			{
				if(freq[j]==0){
					continue;
				}
				ll Aj = j;
				ll Ai = Ak-Aj;
				if(Aj <0 || Ai < 0){
					continue;
				}

				if(Ai!=Aj)
				{
					ans = ans + freq[Ai] * freq[Aj];
				}
				else
				{
					ans = ans + freq[Ai] * (freq[Ai]-1);
				}
			}
		}
		ans = ans / 2;
		cout<<ans<<"\n";

	}
	return 0;
}
