#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		ll k =1;
		//for(k=1; k<=a/k; k++){}
		k = (int)(sqrt(a));
		//cout<<k<<" ";
		if((k*(k+1))  > b){
			cout<<"Limak\n";
		}
		else{
			cout<<"Bob\n";
		}
	}
	return 0;
}