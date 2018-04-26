#include <bits/stdc++.h>
using namespace std;
 
#define sz 100005
#define ll unsigned long long
#define ui unsigned int
ui a[sz];
 
int main()
{
	ll n,q;
	cin>>n>>q;
	for(ll i=1; i<=n; i++)
	{
		cin>>a[i];
	}
 
	while(q--){
		ll L,R;
		cin>>L>>R;
		ui ans = 0, pSum = 0, nSum = 0, mInt = ((1l<<31)-1), tempMsb=0;
		int nBits[32];
		memset(nBits,0,sizeof(nBits));
		for(int i=L; i<=R; i++)
		{
			int t = a[i];
			int index=0;
			while(t>0)
			{
				int bit = t&1;
				if(bit==1){
					nBits[index]++;
				}
				t>>=1;
				index++;
			}
		}
		int threshHold = (R-L+1+1)/2;
		for(int i=0; i<31; i++)
		{
			if(nBits[i] < threshHold){
				ans = ans | ((1<<i));
			}
		}
		printf("%u\n",ans );
	}
	return 0;
}
 