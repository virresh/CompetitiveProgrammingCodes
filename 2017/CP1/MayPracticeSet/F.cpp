#include <bits/stdc++.h>

using namespace std;
#define ll long long


ll x[1000005],y[1000005];
ll n;

int main(){
	cin>>n;
	map <ll,ll> xM;
	map <ll,ll> yM;
	map < pair<ll,ll>, ll> coordinates;
	for(int i=0; i<n; i++){
		cin>>x[i]>>y[i];
		if(xM.find(x[i])==xM.end()){
			xM[x[i]]=0;
		}
		if(yM.find(y[i])==yM.end()){
			yM[y[i]]=0;
		}
		xM[x[i]] = xM[x[i]] + 1;
		yM[y[i]] = yM[y[i]] + 1;
		pair<ll,ll> p = make_pair(x[i],y[i]);
		if(coordinates.find(p)==coordinates.end()){
			coordinates[p] = 0;
		}
		coordinates[p] = coordinates[p]+1;
	}
	ll ans =0,numX=0,numY=0,both=0;
	map <ll,ll>::iterator it;
	for(it = xM.begin(); it!=xM.end(); it++){
		if(it->second > 1){
			ll t=it->second;
			numX += t*(t-1)/2;
		}
	}
	for(it = yM.begin(); it!=yM.end(); it++){
		if(it->second > 1){
			ll t=it->second;
			numY += t*(t-1)/2;
		}
	}

	map < pair<ll,ll>, ll>::iterator it2;
	for(it2 = coordinates.begin(); it2 != coordinates.end(); it2++){
		if(it2->second > 1){
			ll t=it2->second;
			both += t*(t-1)/2;
		}
	}

	ans = numX + numY - both ;
	cout<<ans<<"\n";
}