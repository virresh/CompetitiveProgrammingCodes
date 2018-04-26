#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	int t;
	cin>>t;
	while(t--){
		char a[100005];
		int pre[100005];
		memset(pre,0,sizeof(pre));
		ll n,k;
		scanf("%lld %lld",&n,&k);
		scanf("%s",a);
		int temp=0,maxB=0;
		for(int i=n-1; i>=0; i--){
			if(a[i]=='b'){
				temp++;
				pre[i]=temp;
			}
		}
		maxB=temp;
		temp=0;
		ll ans=0;
		for(int i=n-1; i>=0; i--){
			if(a[i]=='b'){
				temp=pre[i];
			}
			else if(a[i]=='a'){
				pre[i]=temp;
				ans = ans + k*pre[i] + ((k * (k-1))/2)*maxB;
			}
		}
		// for(int i=0; i<n; i++){
		// 	cout<<a[i]<<" ";
		// }
		cout<<ans<<"\n";

	}
	return 0;
}