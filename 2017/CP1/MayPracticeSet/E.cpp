#include <bits/stdc++.h>

using namespace std;
#define ll long long


ll a[1000005];
ll n;

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	sort(a,a+n);

	ll lo=0, hi = n-1;
	while(lo<hi){
		cout<<a[lo]<<" "<<a[hi]<<" ";
		lo++;
		hi--;
	}
	if(lo == hi){
		cout<<a[lo]<<"\n";
	}
	else{
		cout<<"\n";
	}
	return 0;
}