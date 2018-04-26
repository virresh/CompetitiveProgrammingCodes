#include <bits/stdc++.h>
using namespace std;
#define sz 3000
#define ll long long
#define mod 1000000007

int a[sz][sz];


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin >>n>>k;
		for(int i=0; i<n; i++){
			int l;
			cin>>l;
			a[i][0]=l;
			for(int j=1; j<=l; j++){
				cin>>a[i][j];
			}
			sort(a[i]+1,a[i]+l+1);
		}

		int ans=0;

		for(int i=0; i<n; i++){
			// choose set 1
			for(int j=i+1;j<n; j++){
				//choose set 2
				int len1 = a[i][0],len2=a[j][0],common=0;
				for(int p=1; p<=len1; p++){
					if(binary_search(a[j]+1,a[j]+1+len2,a[i][p])){
						common++;
					}
				}
				if(len2+len1-common == k){
					ans++;
				}
			}
		}

		cout<<ans<<"\n";
	}
	return 0;
}