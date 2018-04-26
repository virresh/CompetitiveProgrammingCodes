#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define sz 2005
#define mod 1000000007

ll C[sz][sz];
ll a[sz];

void precalculate(){
	memset(C,0,sizeof(C));
	//precalculate nCr mod p for all values needed
	C[0][0]=1;
	for(int i=1; i<sz; i++){
		C[i][0]=1;
		for(int j=1; j<=i; j++){
			C[i][j]= (C[i-1][j] + C[i-1][j-1])%mod;
		}
	}

	// for(int i=1; i<sz; i++){
	// 	for(int j=1; j<=i; j++){
	// 		cout<<C[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }


}


int main(){
	precalculate();
	// cout<<C[2000][1000]<<"\n";
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		for(ll i=0; i<n; i++){
			cin>>a[i];
		}
		sort(a,a+n);
		ll score=0;
		// for(ll windowSize=1; windowSize<=n; windowSize+=2){
		// 	// ll left=0,right=windowSize-1;
		// 	// while(right<n){
		// 	// 	ll index = (left+right)/2;
		// 	// 	ll numL=index, numR= n-1-index, r = windowSize/2;
		// 	// 	score+= (((a[index] * C[numR][r])%mod) * C[numL][r])%mod;
		// 	// 	left++;
		// 	// 	right++;
		// 	// }
		// 	// cout<<score<<"\n";
		// }

		for(int i=0; i<n; i++){
			ll left = i, right = n-1-i;
			ll rMax = min(left,right);
			score = (score +(a[i]*C[left+right][rMax])%mod ) %mod;
		}
		cout<<score<<"\n";
	}
	return 0;
}