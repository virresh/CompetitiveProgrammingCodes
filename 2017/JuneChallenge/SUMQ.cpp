#include <bits/stdc++.h>
using namespace std;
#define sz 100005
#define ll long long
#define mod 1000000007

ll A[sz],B[sz],C[sz];
ll sumA[sz],sumC[sz];
ll p,q,r;

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(C,0,sizeof(C));
		cin>>p>>q>>r;
		for(ll i=0; i<p; i++){
			cin>>A[i];
		}
		for(ll i=0; i<q; i++){
			cin>>B[i];
		}
		for(ll i=0; i<r; i++){
			cin>>C[i];
		}

		sort(A,A+p);
		sort(B,B+q);
		sort(C,C+r);

		for(ll i=0; i<p; i++){
			sumA[i] = ((i==0) ? (A[i]) : ((A[i]+sumA[i-1])%mod) );
		}

		for(ll i=0; i<r; i++){
			sumC[i] = ((i==0) ? (C[i]) : ((C[i]+sumC[i-1])%mod) );
		}
		ll ans = 0;
		for(ll i=0; i<q; i++){
			ll b1 = upper_bound(A,A+p,B[i])- A;
			ll b2 = upper_bound(C,C+r,B[i])- C;
			ans = (ans + (((b1 * B[i])%mod + ((b1>0)?sumA[b1-1]:0) )%mod  * ( (b2 * B[i])%mod + ((b2>0)?sumC[b2-1]:0) )%mod )%mod)%mod;  
		}
		cout<<ans<<"\n";
	}
	return 0;
}