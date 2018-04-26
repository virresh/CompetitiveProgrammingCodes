#include <bits/stdc++.h>
using namespace std;

#define sz 100005
#define ll long long

int main(){
	ll t,n;
	ll a[sz];
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		ll ans = a[n-1];
		for(ll k=1;k<n;k++){
			if(a[k]!=a[k-1]+1){
				ans = a[k];
			}
		}
		if(a[0]!=a[1]-1){
			ans = a[0];
		}
		else if (a[n-1] != a[n-2]+1){
			ans = a[n-1];
		}
		cout<<ans<<"\n";
	}
	return 0;
}