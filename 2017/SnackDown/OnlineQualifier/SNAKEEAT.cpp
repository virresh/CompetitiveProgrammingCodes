#include <bits/stdc++.h>

using namespace std;
#define ll long long


ll l[100005],sum[100005];

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

		sum[n-1]=l[n-1];
		sum[n]=0;
		
		for(ll i=n-2; i>=0; i--){
			sum[i] = sum[i+1]+l[i];
		}

		// for(ll i=0; i<n; i++){
		// 	cout<<sum[i]<<"\n";
		// }
		
		for(ll i=0; i<q; i++){
			ll k;
			cin>>k;
			ll sIndex=0,endIndex=n-1;
			endIndex = lower_bound(l,l+n,k) - l;
			endIndex--;
			ll ans = n-1-endIndex;
			ll lo = 0, hi = endIndex;
			while(lo<hi){
				ll mid = (lo+hi)/2;
				ll numsnakesExcluded = endIndex-mid+1;
				ll numsnakesReq = numsnakesExcluded * k - sum[mid] + sum[endIndex+1];

				if(numsnakesReq>mid){
					lo = mid+1;
				}
				else{
					hi = mid;
				}
			}

			ll numsnakesExcluded = endIndex-lo+1;
			ll numsnakesReq = numsnakesExcluded * k - sum[lo] + sum[endIndex+1];
			// cout<<"Evaluated : "<<numsnakesReq<<" Low : "<<lo<<" Sum(lo) = "<<sum[lo]<<"\n";
			if(numsnakesReq <= lo)
				ans += endIndex-lo+1;
			// while(sIndex < endIndex){
			// 	ll numsnakes = n-endIndex;
			// 	ll snakesReq = numsnakes * k - sum[numsnakes];

			// 	if(snakesReq >= endIndex){
			// 		break;
			// 	}
			// 	ans+;
			// 	sIndex += k-l[endIndex];
			// 	endIndex --;
			// }
			cout<<ans<<"\n";
		}

	}
	return 0;
}