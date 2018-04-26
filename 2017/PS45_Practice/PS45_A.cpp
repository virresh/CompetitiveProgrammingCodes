#include <bits/stdc++.h>

using namespace std;
#define sz 100005

int a[sz],b[sz];

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		cin>>b[i];
	}

	sort(a,a+n);
	sort(b,b+n);
	int res=0;
	for(int i=0; i<n; i++){
		res += a[i]-b[i];
	}
	cout<<res<<"\n";
	return 0;
}