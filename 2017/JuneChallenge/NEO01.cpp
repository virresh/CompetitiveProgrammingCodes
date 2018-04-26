#include <bits/stdc++.h>
using namespace std;
#define sz 100005
#define ll long long
#define mod 1000000007

ll a[sz];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		sort(a,a+n);
		ll posSum=0,si=0, negsum=0;
		ll curM=0;
		for(int i=n-1; i>=0; i--){
			if(a[i]>=0){
				curM+=a[i];
				si++;
			}
			else if((curM + a[i])*(si+1) >= (curM*si)){
				curM +=a[i];
				si++;
			}
			else{
				negsum+=a[i];
			}
		}

		cout<< curM*si + negsum <<"\n";
	}
	return 0;
}