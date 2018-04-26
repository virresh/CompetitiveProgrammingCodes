#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define sz 1000005
int main()
{
	ll n,t;
	ll a[sz];
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	ll variation=0;
	sort(a,a+n);
	for(int k=1; k<n;k++){
		if(a[k]!=a[k-1]){
			variation++;
		}
	}
	if(variation > 2){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
	}
	return 0;
}
