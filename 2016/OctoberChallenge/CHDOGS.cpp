#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll s,v;
		cin>>s>>v;
		double res = (2.0*s)/(3.0*v);
		cout<<setprecision(9)<< fixed <<res<<"\n";
	}
	return 0;
}