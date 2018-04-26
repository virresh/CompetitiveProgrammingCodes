#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define md 1000000007
ll powp[13];
ll p,i,j;
ll Y[13];
void precompute()
{
	p=23;
	powp[0]=1;
	for(i=1;i<p;i++)
	{
		powp[i]=powp[i-1]*p % md;
	}
}
int main()
{
	ll t,n,m,d;
	cin>>t;
	precompute();
	while(t--)
	{
		cin>>n>>d;

	}
	return 0;
}