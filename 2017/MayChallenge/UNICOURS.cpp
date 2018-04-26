#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,tempM=-1;
		cin>>n;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			tempM = max(tempM,x);
		}
		int ans=n-tempM;
		cout<<ans<<"\n";
	}
	return 0;
}