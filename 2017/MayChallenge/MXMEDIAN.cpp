#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		int a[100005];
		cin>>n;
		for(int i=0; i<2*n; i++){
			cin>>a[i];
		}

		sort(a,a+2*n);
		int ansIndex = (n-1)/2 + n;
		//cout<<ansIndex<<"\n";
		cout<<a[ansIndex]<<"\n";
		for(int j=0; j<n; j++){
			cout<<a[j]<<" "<<a[j+n]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}