#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 10004
#define md 1000000007
int a[sz],res[sz],n,m;

void solve(int node,int i) // at node th dog and in ith pass
{
	//cout<<"At dog "<<node<<"\n";
	if(i>m){
		// no more passes left
		res[node]=(res[node]+1)%md;
		return;
	}
	if((node-a[i] <= 0) && (node+a[i] > n)) // no valid pass possible
	{
		//res[node]++;
		return;
	}
	if(node-a[i] > 0) //left pass possible
	{
		solve(node-a[i],i+1);
	}
	if(node+a[i] <= n) // right pass possible
	{
		solve(node+a[i],i+1);
	}
}

int main()
{
    int t;
	cin>>t;
	while(t--)
	{
		int s;
		memset(res,0,sizeof(res));
		cin>>n>>m>>s;
		for(int i=1;i<=m;i++)
		{
			cin>>a[i];
		}
		solve(s,1);
		for(int k=1;k<=n;k++)
		{
			cout<<res[k]<<" ";
		}
		cout<<"\n";
	}
    return 0;
}
