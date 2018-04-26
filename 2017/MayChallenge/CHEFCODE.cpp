#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll a[35],k,ans;
double b[35],logK;
// bool visit[35];
int n;


void solve(int level, double sum){
	if(level>n){
		return;
	}
	if(sum>=logK){
		return;
	}

	if(sum+b[level-1]<=logK){
		ans++;
		solve(level+1,sum+b[level-1]);
		solve(level+1,sum);
	}
}


int main(){
	cin>>n>>k;
	ans=0;
	logK = log(k);
	for(int i=0; i<n; i++){
		cin>>a[i];
		// b[i]=log(a[i]);
		// cout<<b[i]<<" ";
	}
	sort(a,a+n);
	for(int i=0; i<n; i++){
		b[i]=log(a[i]);
	}
	solve(1,0);
	cout<<ans<<"\n";
	return 0;
}