#include <bits/stdc++.h>

using namespace std;
#define ll long long


ll l[100005],f[100005];
// f[i] == preprocessed value of i snakes

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,q;
		cin>>n>>q;
		for(ll i=0; i<n; i++){
			cin>>l[i];
		}
		sort(l,l+n);
		
		
		//pre-process the input for all possible n
		f[0]=10000005;
		for(int i=1; i<=n; i++){
			int edibleSnakes = n-i;
			f[i] = min(l[edibleSnakes]+edibleSnakes, )
		}

		for(ll i=0; i<q; i++){
			ll k;
			cin>>k;
			ll sIndex=0,endIndex=n-1;
			endIndex = lower_bound(l,l+n,k) - l;
			endIndex--;
			ll ans=n-1-endIndex;
			while((sIndex < endIndex) && ((k-l[endIndex])<=(endIndex-sIndex))){
				ans++;
				sIndex += k-l[endIndex];
				endIndex --;
			}
			cout<<ans<<"\n";
		}

	}
	return 0;
}