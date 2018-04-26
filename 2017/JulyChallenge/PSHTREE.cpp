#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz 100005

vector< pair<int,int> > adj[sz];
vector<int> prefiX[sz];
vector<int> ancestorC[sz];
int parent[sz]; //parent representation of the tree
int cost[sz]; //dfs cost from parent[i] to ith node
int depth[sz]; //depth of ith node
bool visited[sz];
int sqN;

void dfs(int start, int p, int d)
{
    visited[start]=true;
    parent[start]=p;
    depth[start]=d;

    // process this node
    if(start==1){
        cost[start]=0;
        ancestorC[start].push_back(0);
    }

    if(start!=1 && d%sqN ==1)
    {
        // this node is at a depth where we can decompose via sqrt
        int pr = parent[start];
        ancestorC[start].push_back(cost[start]);
        while(ancestorC[pr].size()==0)
        {
            ancestorC[start].push_back(cost[pr]);
            pr = parent[pr];
        }

        for(int l=0; l<pr; l++)
        {
            ancestorC[start].push_back(ancestorC[pr][l]);
        }
    }


    for(int j=0; j<adj[start].size(); j++)
    {
        int dest = adj[start][j].first;
        int co = adj[start][j].second;
        if(visited[dest]==false)
        {
            cost[dest] = co;
            dfs(dest,start,d+1);
        }
    }
}


int query(int u, int k)
{
    // return all XOR from node 1 to node U of elements less than k
    if(u==1)
    {
        return 0;
        // path from 1 to 1 has no edges
    }

    int ans=0, pr=u;
    while(depth[pr]%sqN!=1 && pr>0)
    {
        if(cost[pr]<=k)
        {
            ans = ans^cost[pr];
        }
        pr = parent[pr];
        //cout<<pr<<"\n";
    }

    int pos = upper_bound(ancestorC[pr].begin(),ancestorC[pr].end(), k) - ancestorC[pr].begin();
    pos-=1;
    if(pos<0)
    {
        // no edge less than cost k
        return 0;
    }
    return prefiX[pr][pos]^ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        memset(parent,0,sizeof(parent));
        memset(cost,0,sizeof(cost));
        memset(depth,0,sizeof(depth));
        memset(visited,false,sizeof(visited));

        int N;

        cin>>N;
        //sqN = int(sqrt(N));
        sqN = 1000;
        for(int k=1; k<=N; k++)
        {
            adj[k].clear();
            prefiX[k].clear();
            ancestorC[k].clear();
        }
        for(int i=0; i< N-1; i++)
        {
            int U,V,C;
            cin>>U>>V>>C;
            adj[U].push_back(make_pair(V,C));
            adj[V].push_back(make_pair(U,C));
        }

        dfs(1,1,1);

        for(int k=1; k<=N; k++)
        {
            // compute prefix xor's
            if(ancestorC[k].size()!=0)
            {
                sort(ancestorC[k].begin(),ancestorC[k].end());
                prefiX[k].push_back(ancestorC[k][0]);
                for(int l=1; l<ancestorC[k].size(); l++)
                {
                    prefiX[k].push_back(prefiX[k][l-1]^ancestorC[k][l]);
                }
            }
        }

        int M;
        cin>>M;
        //cout<<"here\n";
        for(int o=0; o<M; o++)
        {
            int u,v,k;
            cin>>u>>v>>k;
            int an = query(u,k)^query(v,k);
            cout<<an<<"\n";
        }
    }
	return 0;
}
