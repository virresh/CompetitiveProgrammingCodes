#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100005
#define md 100000007
vector <int> adjList[sz];
ll visited[sz];
ll colors[sz];
void dfs(ll x,ll color)
{
	ll t = adjList[x].size();
	for(ll i=0;i<t;i++)
	{
		ll p=adjList[x][i];
		if(visited[p]==-1)
		{
			visited[p]=color;
			colors[color]++;
			dfs(p,color);
		}
	}
}

ll floodfill(ll n)
{
	ll color=0;
	for(ll i=1;i<=n;i++)
	{
		if(visited[i]==-1)
		{
			colors[color]=1;
			visited[i]=color;
			dfs(i,color);
			color++;
		}
	}
	return color;
}

void printGraph(int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<"Neigbours of "<<i<<"\n";
		for(int j=0;j<adjList[i].size();j++)
		{
			cout<<adjList[i][j]<<" ";
		}
		cout<<"\n";
	}
}
int main()
{
    ll t;
	cin>>t;
	while(t--)
	{
		memset(visited,-1,sizeof(visited));
		
		ll n,m;
		cin>>n>>m;
		for(ll i=0;i<m;i++)
		{
			ll p,q;
			cin>>p>>q;
			adjList[p].push_back(q);
			adjList[q].push_back(p);
		}
		ll no_of_components,ways=1;;
		no_of_components=floodfill(n);
		
		/*for(int i=1;i<=n;i++)
		{
			cout<<visited[i]<<" ";
		}*/
		//cout<<"\n";
		for(ll k=0;k<no_of_components;k++)
		{
			ways= (ways * colors[k])%md;
		}
		//printGraph(n);
		cout<<no_of_components<<" "<<ways<<"\n";
		for(ll i=1;i<=n;i++)
		{
			adjList[i].clear();
		}
	}
    return 0;
}
