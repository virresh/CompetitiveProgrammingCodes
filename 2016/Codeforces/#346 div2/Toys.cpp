#include <bits/stdc++.h>
using namespace std;
#define ll long long

set<int> a;
vector <int> bought;
int main()
{
    int n,m,t;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		a.insert(t);
	}	
	for(int j=1; j<=m; j++)
	{
		if(a.find(j)==a.end())
		{
			m-=j;
			bought.push_back(j);
		}
	}
	cout<<bought.size()<<"\n";
	for(int i=0; i<bought.size(); i++)
	{
		cout<<bought[i]<<" ";
	}
	cout<<"\n";
    return 0;
}
