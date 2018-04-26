#include <bits/stdc++.h>
using namespace std;
#define sz 1000005
#define ll long long
#define mod 1000000007

bool prime[sz];
int nextPrime[sz];
node a[sz];

class node{
public:
	int start,end;
	int val;
	node(int x){
		start=-1;
		end=-1;
		val = x;
	}
};

void precompute(){
	memset(prime,true,sizeof(prime));
	prime[1]=false;
	prime[2]=true;
	for(int i=2; i<sz; i++){
		if(prime[i]==true){
			for(int k=2*i; k<sz;k+=i){
				prime[k]=false;
			}
			primes.push_back(i);
		}
	}
	int lastPrime = -1;
	for(int i=sz-1; i>=1; i--){
		nextPrime[i] = lastPrime;
		if(prime[i]==true){
			lastPrime = i;
		}
	}
}

ll f(ll L,ll R,ll X,ll Y){
	ll result = 0;
	for(int j=L;  j<=R; j++){
		ll num = a[j];
		ll pF = 2;
		while(pF * pF <= num){
			while(num%pF==0){
				num/=pF;
				if(pF>=X && pF<=Y){
					result++;
				}
			}
			pF = nextPrime[pF];
		}
		if(num!=1 && num>=X && num<=Y){
			result++;
		}
	}
	return result;
}



int main(){
	ios::sync_with_stdio(false);
	precompute();
	int n,q;
	cin>>n;
	for(int i=1; i<=n;i++){
		cin>>a[i];
	}
	cin>>q;
	while(q--){
		int L,R,X,Y;
		cin>>L>>R>>X>>Y;
		ll ans = f(L,R,X,Y);
		cout<<ans<<"\n";
	}
	return 0;
}
