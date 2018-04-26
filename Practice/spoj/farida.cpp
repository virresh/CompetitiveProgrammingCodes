		#include <bits/stdc++.h>
		using namespace std;
		#define ll long long
		#define sz 10000
		ll memo[sz],a[sz];

		ll f(ll *a, ll n)
		{
			if(n<0){return 0;}
			else if(n==0){return a[n];}
			else if(n<sz && memo[n]!=-1){return memo[n];}
			else
			{
				ll res;
				res = max(f(a,n-1), f(a,n-2)+a[n]);
				if(n<sz){memo[n]=res;}
				return res;
			}
		}
		int main()
		{
			ll t,i,n,j=0;
			cin>>t;
			while(j++<t)
			{
				cin>>n;
				memset(memo,-1,sizeof(memo));
				for(i=0;i<n;i++)
				{
					cin>>a[i];
				}
				cout<<"Case "<<j<<": "<<f(a,i-1)<<"\n";
			}
			return 0;
		}