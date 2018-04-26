#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	ll m,n;
	cin>>n>>m;
	ll ans =m,i=1,tempm =n-m;
	if(n<=m){
		ans = n;
	}
	else{
		while(tempm-i>0){
			tempm-=i;
			i++;
		}
		ans+=i;
	}
	cout<<ans<<"\n";
	return 0;
}