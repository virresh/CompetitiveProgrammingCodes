#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
		ll c,d,l;
		cin>>c>>d>>l;
		ll maxLegs = (d+c)*4; // since at max, all animals should be on ground
		ll minLegs=0;
		if(c-2*d > 0){
			// there aren't enough dogs to handle the cats
			minLegs = (c-d) * 4;
		}
		else{
			minLegs = d * 4;
		}

		if(l>=minLegs && l<=maxLegs && l%4==0){
			cout<<"yes\n";
		}
		else{
			cout<<"no\n";
		}

	}
	return 0;
}