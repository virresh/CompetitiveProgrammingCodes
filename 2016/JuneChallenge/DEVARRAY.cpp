#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000005
int a[sz];
int main()
{
    int n,q;
	cin>>n>>q;
	int mi=1e9+1,ma=-1;
	sort(a,a+n);
	
	for(int i=0; i<n; i++){
		cin>>a[i];
		if(a[i]<mi){
			mi=a[i];
		}
		if(a[i]>ma){
			ma=a[i];
		}
	}
	int t;
	for(int j=0; j<q; j++){
		cin>>t;
		if(t>=mi && t<=ma){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
    return 0;
}
