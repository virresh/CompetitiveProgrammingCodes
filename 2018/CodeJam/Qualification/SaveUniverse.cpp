#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	// Specifically made for test case one
	int t;
	cin>>t;
	for(int u=1; u<=t; u++)
	{
		ll d;
		string p;
		cin>>d;
		cin>>p;
		ll totalShoots=0;
		ll Cloc = -1;
		for(int i=0; i<p.length(); i++)
		{
			if(p[i] == 'C')
			{
				Cloc = i;
			}
			else
			{
				totalShoots++;
			}
		}
		cout<<"Case #"<<u<<": ";
		if(totalShoots > d)
		{
			cout<<"IMPOSSIBLE\n";
		}
		else
		{
			ll curCost = 0;
			if(Cloc != -1)
				curCost = Cloc + (p.length()-Cloc-1)*2;
			else
				curCost = p.length();

			ll ans = max(0ll,curCost-d);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
