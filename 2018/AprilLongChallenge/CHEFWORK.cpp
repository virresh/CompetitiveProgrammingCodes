#include <bits/stdc++.h>
using namespace std;

#define sz 100005

int main()
{
	int n;
	cin>>n;
	int c[sz];
	int t[sz];
	int m[4];
	m[0] = m[1] = m[2] = m[3] = sz;
	for(int i=1; i<=n; i++)
	{
		cin>>c[i];
	}
	for(int i=1; i<=n; i++)
	{
		cin>>t[i];
	}

	for(int j=1; j<=3; j++)
	{
		for(int i=1; i<=n; i++)
		{
			if(t[i]==j)
			{
				m[j] = min(m[j],c[i]);
			}
		}
	}
	cout<<min(m[2]+m[1], m[3])<<"\n";
	return 0;
}
