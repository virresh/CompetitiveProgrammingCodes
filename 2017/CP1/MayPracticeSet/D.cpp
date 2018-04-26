#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define sz 1000005

ll seive[sz],sum[sz];
ll a,b,k;

void precalculate(){
	//precalculate all the primes
	for(int i=0; i<sz; i++){
		seive[i]=1;
	}
	seive[1]=seive[0]=0;
	for(int i=2; i<sz; i++){
		if(seive[i]!=0){
			for(int k=2*i; k<sz; k+=i){
				seive[k]=0;
			}
		}
	}

	// now precalcultate the sum of primes till number i
	sum[0]=0;
	for(int i=1; i<sz; i++){
		if(seive[i]==1){
			sum[i] = sum[i-1]+1;
		}
		else{
			sum[i] = sum[i-1];
		}
	}
}


ll f(ll x){
	ll left = a,right=a+x-1,ans=x+1;
	while(right<=b){
		ans = min(ans,sum[right]-sum[left-1]);
		left++;
		right++;
	}
	return ans;
}

int main(){
	precalculate();
	cin>>a>>b>>k;
	// for(int i=a; i<=b; i++){
	// 	cout<<seive[i]<<" ";
	// }
	// cout<<"\n";

	ll lo=0, hi=b-a+1;
	while(lo<hi){
		ll mid = (lo+hi)/2;

		if(f(mid)>=k){
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	if(lo==0 || f(lo)<k){
		cout<<-1<<"\n";
	}
	else{
		cout<<lo<<"\n";
	}
	return 0;
}