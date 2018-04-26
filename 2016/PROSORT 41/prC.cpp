#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1005
ll a[sz];
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		bool ans=false;
		for(int i=2;i<n;i++){
			if(a[i-2] + a[i-1] > a[i]){
				ans=true;
				break;
			}
		}
		if(ans){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
    return 0;
}
