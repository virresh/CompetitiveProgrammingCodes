#include <bits/stdc++.h>

using namespace std;
#define ll long long


ll groups[100005];
ll n,m;

ll f(ll x){
	// return number of mics needed if we have at max x students on one mic
	ll ans=0;
	for(ll i=0; i<n; i++){
		ans= ans+ ceil((float)groups[i] / (float)(x));
	}
	return ans;
}

int main(){
	cin>>n>>m;
	ll minSiz,maxSiz;
	
	for(int i=0; i<n; i++){
		cin>>groups[i];
		if(i==0){
			minSiz = groups[i];
			maxSiz = groups[i];
		}
		else{
			minSiz = min(minSiz,groups[i]);
			maxSiz = max(maxSiz,groups[i]);
		}
	}

	ll lo=1,hi=maxSiz;
	while(lo<hi){
		ll mid = (lo+hi)/2;
		// cout<<mid<<" "<<f(mid)<<"\n";
		if(f(mid)>m){
			lo = mid+1;
		}
		else{
			hi = mid;
		}
	}

	cout<<lo<<"\n";

	return 0;
}