#include <bits/stdc++.h>
using namespace std;

//int sz = 100005;
#define sz 50005

vector<int> adjList[sz];
int matrix[sz][505];
int parent[sz];
bool visited[sz];
int ans;

int dfs(int start, int k)
{
    visited[start]=true;
    matrix[start][0]=1;
    for(int i=0; i<adjList[start].size(); i++)
    {
        int v = adjList[start][i];
        if(!visited[v])
        {
            //cout<<"Here\n";
            parent[v]=start;
            //iterate over all child nodes and fill up path matrix
            dfs(v,k);
        }
    }
    for(int i=0; i<k ; i++)
    {
        ans = ans + matrix[parent[start]][i] * matrix[start][k-i-1];
    }

    for(int i=1; i<=k; i++)
    {
        matrix[parent[start]][i] = matrix[parent[start]][i] + matrix[start][i-1];
    }
}

int main()
{
	int n,k;
	cin>>n>>k;
	ans=0;
	for(int i=0; i<n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    memset(visited,false,sizeof(visited));
    memset(parent,0,sizeof(0));
    memset(matrix,0,sizeof(0));
    parent[1]=0;
    dfs(1,k);
    cout<<ans<<"\n";
	return 0;
}
