#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	int n1;
	ll l1max=-1,l2max=-1,r1min = LLONG_MAX,r2min = LLONG_MAX;
	cin >>n1;
	for(int i=0; i<n1 ; i++){
		ll l1i,r1i;
		cin>>l1i>>r1i;
		l1max = max(l1i,l1max);
		r1min = min(r1i,r1min);
	}

	int n2;
	cin>>n2;
	for(int k=0; k<n2; k++){
		ll l2i,r2i;
		cin>>l2i>>r2i;
		l2max = max(l2i,l2max);
		r2min = min(r2i,r2min);
	}

	ll d1,d2;
	d1 = l2max - r1min;
	d2 = l1max - r2min;
	cout<<(max(d1,d2)>0?max(d1,d2):0) <<"\n";
	return 0;
}