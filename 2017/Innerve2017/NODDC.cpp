#include <bits/stdc++.h>
using namespace std;

#define sz 10005
vector<int> adj[sz];
vector< pair<int,int> >edges;
        bool visited[sz];
        int level[sz];

bool bfs(int start, int rEd)
{
    queue<int> Q;
    Q.push(start);
    visited[start]=true;
    level[start]=0;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        //cout<<"Vertex "<<u<<"\n ";
        for(int j=0; j<adj[u].size(); j++)
        {
            int v = adj[u][j];
            if((u == edges[rEd].first && v == edges[rEd].second)||(v == edges[rEd].first && u == edges[rEd].second))
            {
                continue;
            }
            //cout<<v<<" "<<visited[v]<<" "<<level[v]<<"\n ";
            if(!visited[v])
            {
                visited[v] = true;
                level[v] = level[u]+1;
                Q.push(v);
            }
            else if(level[v] == level[u])
            {
                return false;   // not a bipartite graph
            }
        }
    }
    return true;
}

int func(int N, int M)
{
    int finalAns=0;
    for(int f=0; f<M; f++)
    {
        //cout<<"Edge "<<f<<"\n ";
        bool canRemove=true;
        int restrictedEdge = f;
        memset(visited,false,sizeof(visited));
        memset(level,0,sizeof(level));
        for(int i=1; i<=N; i++)
        {
            bool hasOddCycle=false;
            if(!visited[i])
            {
                //cout<<"BFS from "<<i<<" ";
                hasOddCycle = !bfs(i,restrictedEdge);
                //cout<<hasOddCycle<<"\n ";
            }
            if(hasOddCycle)
            {
                canRemove = false;
                break;
            }
        }
        //cout<<"\nRemovable - "<<canRemove<<"\n";
        if(canRemove==true)
        {
            finalAns++;
        }
    }
    return finalAns;
}

int main()
{
	int N,M;
	cin>>N>>M;
	for(int j=0; j<M; j++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edges.push_back(make_pair(x,y));
    }

    cout<<func(N,M)<<"\n";

	return 0;
}
