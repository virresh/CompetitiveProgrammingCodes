#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100005

int indeg[sz];
int main()
{
    int n,i,j,x;
	cin>>n;
	memset(indeg,0,sizeof(indeg));
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(x!=0)
		{
			indeg[x]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(indeg[i]==0){cout<<i<<" ";}
	}
	cout<<"\n";
    return 0;
}
