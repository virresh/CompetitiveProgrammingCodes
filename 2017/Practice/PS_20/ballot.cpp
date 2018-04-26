#include <bits/stdc++.h>

using namespace std;
#define ll long long


int p[600005],n,b;

int f(int x){
	int q=0;
	for(int i=0; i<n; i++){
		q += (int)ceil(((float)p[i])/((float)x));
		// q = max(q, p[i]/x);
	}
	return q;
}


int main(){
	int lo=1,hi=0;
	cin>>n>>b;
	for(int i=0; i<n; i++){
		cin>>p[i];
		hi=max(hi,p[i]);
	}
	int mid;
	while(lo<hi){
		mid = (hi+lo)/2;
		int r = f(mid);
		// cout<<mid<<" "<<r<<"\n";
		if(r<=b){
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}

	cout<<lo<<"\n";

	return 0;
}