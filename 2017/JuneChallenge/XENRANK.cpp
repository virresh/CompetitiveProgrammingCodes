#include <bits/stdc++.h>
using namespace std;
#define sz 40000
#define ll long long

int main(){
	int t;
	cin>>t;
	while(t--){
		ll u,v;
		cin>>u>>v;
		ll ans=0,x;
		x = u+v;

		ans = x*(x+1)/2 + u + 1;
		cout<<ans<<"\n";
	}
	return 0;
}