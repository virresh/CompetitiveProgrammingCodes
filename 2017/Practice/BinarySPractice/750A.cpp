#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){

	int n,k;
	cin>>n>>k;

	int lo=0,hi=n;
	while(lo<hi){
		int mid = ceil((lo+hi)/2.0);
		if((5*mid*(mid+1)/2) <= (240-k)){
			lo = mid;
		}
		else{
			hi = mid-1;
		}
	}

	cout<<lo<<"\n";

	return 0;
}