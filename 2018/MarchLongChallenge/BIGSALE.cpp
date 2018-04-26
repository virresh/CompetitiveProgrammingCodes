#include <bits/stdc++.h>
using namespace std;

#define sz 100005

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double ans = 0;
		int n;
		cin>>n;
		for(int i=0; i<n; i++)
		{
			double price, qty, x;
			cin>>price>>qty>>x;
			ans = ans + qty * price * x * x;
		}
		cout<<(ans/10000.0)<<"\n";
	}
	return 0;
}
