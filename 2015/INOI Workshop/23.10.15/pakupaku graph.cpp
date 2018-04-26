#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,indx;
};
vector <node> adj[1000002];
vector <node> nodes;
int visited[1000002];
char maze[1001][1001];
int bfs(int snode)
{
    queue <node> q;
    node top;
    int i;
    q.push(nodes[snode]);
    visited[snode]=0;
    while(!q.empty())
    {
        top=q.front();
        //cout<<top.x<<" "<<top.y<<" outside i's location\n\n";
        q.pop();
        for(i=0;i<adj[top.indx].size(); i++)
        {
            //cout<<top.x<<" "<<top.y<<"  inside i's location\n";
            if(visited[adj[top.indx].at(i).indx] == 0)
            {
                q.push(nodes[adj[top.indx].at(i).indx]);
                visited[adj[top.indx].at(i).indx]=visited[top.indx]+1;
            }
        }
        if(maze[top.x][top.y]=='E'){return visited[top.indx];}
    }
    return -1;
}

int main()
{
    memset(visited,0,sizeof(visited));
    //memset(visited,'0',sizeof(visited));
    //freopen("in.txt","r",stdin);
    int n,m,i,j,nd=0,snode=0,k;
    node p,q;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>maze[i][j];
            //cout<<maze[i][j]<<" ";
            if(maze[i][j]!='#')
            {
                p.x=i; p.y=j; p.indx=nd; nd++;
                nodes.push_back(p);
                if(maze[p.x][p.y]=='S'){snode=nd-1;}
                for(k=0;k<nodes.size();k++)
                {
                    q=nodes[k];
                    if((p.x==q.x+1||p.x==q.x-1)&& p.y==q.y){adj[p.indx].push_back(q); adj[q.indx].push_back(p);}
                    if((p.y==q.y+1||p.y==q.y-1)&& p.x==q.x){adj[p.indx].push_back(q); adj[q.indx].push_back(p);}
                }
            }
        }
        //cout<<"\n";
    }

    /*for(i=0;i<nodes.size();i++)
    {
        p=nodes[i];
        for(j=0;j<nodes.size();j++)
        {
            q=nodes[j];
            if((p.x==q.x+1||p.x==q.x-1 )&& p.y==q.y){adj[p.indx].push_back(q);}
            if((p.y==q.y+1||p.y==q.y-1)&& p.x==q.x){adj[p.indx].push_back(q);}
        }
    }
    for(j=0;j<nodes.size();j++)
    {
        cout<<nodes[j].x<<" "<<nodes[j].y<<": - \n";
        for(i=0;i<adj[j].size();i++)
        {
            cout<<adj[j].at(i).x<< " "<<adj[j].at(i).y<<"\n";
        }
        cout<<"\n";
    }*/
    cout<<bfs(snode)<<"\n";
    return 0;
}
