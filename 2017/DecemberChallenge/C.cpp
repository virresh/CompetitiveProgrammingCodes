#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz 1000005

ll memo[sz];

int lookup(int x){
	return (x%2==0)?(x):(-x);
}

int r(int i, int n){
	//return number of rooms with number i in grid of n
	if(i<=1 || i>(2*n)){
		return 0;
	}
	if(i<=n+1){
		return i-1;
	}
	else{
		return (2*n)-(i-1);
	}
}

int f(int i){
	// return the diamonds at this room value
	int ans=0;
	while(i > 0){
		int t = i%10;
		i = i/10;
		ans  = ans + lookup(t);
	}
	return abs(ans);
}

ll solve(int N){
	if(memo[N] !=-1){
		return memo[N];
	}
	ll ans = 0;

	if(N == 1){
		return 2;
	}
	ans = solve(N-1);
	for(int i=N+1; i<=2*N; i++){
		ans = ans + 1LL * 2 * f(i);
	}
	ans = ans - f(2*N);
	memo[N] = ans;
	return ans;
}

int main()
{
	int t;
	cin>>t;
	memset(memo,-1,sizeof(memo));
	while(t--)
	{
		int n;
		cin>>n;
		cout<<solve(n)<<"\n";
	}
}
