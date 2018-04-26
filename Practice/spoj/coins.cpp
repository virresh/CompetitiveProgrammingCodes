		#include <bits/stdc++.h>
		using namespace std;
		#define ll long long
		#define sz 100000
		ll mem[sz];

		ll f(ll n)
		{
			if(n==1){return 1;}
			else if(n==0){return 0;}
			else if(n<sz && mem[n]!=-1)
			{
				return mem[n];
			} 
			else
			{
				ll ans;
				ans= max(n, (f(n/2) + f(n/3) + f(n/4)));
				if(n<sz){mem[n]=ans;}
				return ans;
			}
		}
		int main()
		{
			ll n; mem[1]=1; mem[0]=0;
			memset(mem,-1,sizeof(mem));
			while(cin>>n)
			{	
				cout<<f(n)<<"\n"; 
			}
			return 0;
		}