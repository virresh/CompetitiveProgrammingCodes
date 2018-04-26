#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100005
#define pb push_back
vector <int> adjList[sz];
bool visited[sz]={false};
int n,m;

void dfs(int s)
{
    cout<<s<<" ";
    visited[s]=true;
    int p=adjList[s].size(),q;
    for(int i=0;i<p;i++)
    {
        q=adjList[s][i];
        if(!visited[q])
        {
            visited[q]=true;
            dfs(q);
            visited[q]=false;
        }
    }
}
int main()
{
    cin>>n>>m;
    int v1,v2;
    for(int i=0;i<m;i++)
    {
        cin>>v1>>v2;
        adjList[v1].pb(v2);
        adjList[v2].pb(v1);
    }
    dfs(1);
    return 0;
}
