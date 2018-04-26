#include <bits/stdc++.h>
using namespace std;

#define sz 30005
#define ll long long

int main(){
	ll t,n;
	ll x[sz],y[sz],xodd=0,xeven=0,yodd=0,yeven=0;
	cin>>t;
	while(t--){
		cin>>n;
		xodd=0,xeven=0,yodd=0,yeven=0;
		for(ll i=0;i<n;i++){
			cin>>x[i];
			if(i%2==0){
				xodd +=x[i];
			}
			else{
				xeven +=x[i];
			}
		}

		for(ll i=0;i<n;i++){
			cin>>y[i];
			if(i%2==0){
				yodd += y[i];
			}
			else{
				yeven += y[i];
			}
		}

		ll res = min((xodd+yeven),(xeven+yodd));
		cout<<res<<"\n";
	}
	return 0;
}