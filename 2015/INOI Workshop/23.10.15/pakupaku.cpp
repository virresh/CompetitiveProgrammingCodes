#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100005
#define wall '#'
#define start 'S'
#define exit 'E'
ll visited[1000002]={0};
vector <ll> adj[sz];
struct node
{
    ll x,y,index;
};
vector <node> nodes;

bool isAd(node a,node b)
{
    if(a.x==b.x && (a.y==b.y+1 || a.y+1==b.y)){return true;}
    else if(a.y==b.y && (a.x==b.x+1 || a.x+1==b.x)){return true;}
    return false;
}

ll bfs(ll snode,ll enode)
{
    queue <int> q;
    ll i,j,p=snode;;
    visited[p]=0;
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(i=0;i<adj[p].size(); i++)
        {
            j=adj[p].at(i);
            if(visited[j]==0){visited[j]=visited[p]+1; q.push(j);}
        }
        if(p==enode){return visited[p];}
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    ll n,m,i,j,start_node,k,end_node;
    cin>>n>>m;
    node p,q;
    char x;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>x;
            if(x!=wall)
            {
                p.x=i; p.y=j; p.index=nodes.size(); nodes.push_back(p);
                for(k=0; k<nodes.size()-1;k++)
                {
                    q=nodes[k];
                    if(isAd(p,q))
                    {
                            adj[p.index].push_back(q.index);
                            adj[q.index].push_back(p.index);
                    }
                }
            }
            if(x==start){start_node=nodes.size()-1 ;}
            if(x==exit){end_node=nodes.size()-1;}
        }
    }
    cout<<bfs(start_node,end_node);
    return 0;
}
