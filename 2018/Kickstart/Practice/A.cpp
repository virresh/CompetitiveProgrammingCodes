#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for (int iN = 1; iN <= t; ++iN)
	{
		int n;
		cin>>n;
		int buses[10005];
		memset(buses,0,sizeof(buses));
		for(int j=0; j<n; j++)
		{
			int a,b;
			cin>>a>>b;
			for(int i=a; i<=b; i++)
			{
				buses[i]++;
			}
		}

		int p;
		cin>>p;
		cout<<"Case #"<<iN<<": ";
		for(int i=1; i<=p; i++)
		{
			int bNum;
			cin>>bNum;
			cout<<buses[bNum]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
