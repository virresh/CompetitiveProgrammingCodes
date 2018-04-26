#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,uniq=0;
		int arr[100005];
		cin >>n>>k;
		string ans="";
		for(int i=1; i<=k;i++){
			arr[i]=0;
		}
		for(int i=1; i<=n; i++){
			int p,u=0;
			cin>>p;
			for(int j=1; j<=p; j++){
				int x;
				cin>>x;
				arr[x]++;
				if(arr[x]==1){
					u=1;
				}
			}
			uniq+=u; //increment the islands with unique ingredients
		}
		int unavIng=0;
		for(int i=1; i<=k; i++){
			if(arr[i]==0){
				unavIng++;
			}
		}

		if(unavIng>0){
			ans="sad";
		}
		else{
			//all ingredients can be collected
			if(uniq ==n){
				//all islands have a unique ingredient amongst them
				ans="all";
			}
			else{
				ans="some";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}