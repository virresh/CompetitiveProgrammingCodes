#include <bits/stdc++.h>
using namespace std;

#define sz 100005
#define ll unsigned long long
#define ui unsigned int
ui a[sz];
int precompute[32][sz];

int main()
{
	ll n,q;
	cin>>n>>q;
	memset(precompute,0,sizeof(precompute));
	for(ll i=1; i<=n; i++)
	{
		cin>>a[i];
	}

	for(int i=1; i<=n+20; i++)
	{
		ui t = a[i];
		int index=0;
		for(index = 0; index < 31; index++)
		{
			int bit = t&1;
			precompute[index][i] = precompute[index][i-1];
			if(bit==1){
				precompute[index][i]++;
			}
			t>>=1;
		}
	}
	// for(int i=0; i<31; i++)
	// {
	// 	for(int j=0; j<n; j++)
	// 	{
	// 		cout<<precompute[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	while(q--){
		ll L,R;
		cin>>L>>R;
		ui ans = 0;
		int threshHold = (R-L+1+1)/2;
		for(int i=0; i<31; i++)
		{
			int nBits = precompute[i][R] - precompute[i][L-1];
			// cout<<nBits<<" ";
			if(nBits < threshHold){
				ans = ans | ((1<<i));
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
