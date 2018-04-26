#include<bits/stdc++.h>
using namespace  std;
#define ll long long
#define sz 1000000
struct node
{
	int x,y,indx;
};

vector<int> adj[sz];
vector<node> nodes;
char maze[1001][1001];
int visited[sz];

int bfs(int snode)
{
	queue <int> q;
	int top,i;
	visited[snode]=0;
	q.push(snode);
	while(!q.empty())
	{
		top=q.front();
		q.pop();
		//cout<<nodes[top].x<<" "<<nodes[top].y<<"\n";
		if(maze[nodes[top].x][nodes[top].y]=='E'){return visited[top];}
		for(i=0;i<adj[top].size();i++)
		{
			if(visited[adj[top].at(i)]==0)
			{
				visited[adj[top].at(i)]=visited[top]+1;
				q.push(adj[top].at(i));
			}
		}
		
	}
	return -1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int n,m,k,i,j,nd=0,snode=0;
	node p,q;
	memset(visited,0,sizeof(visited));
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>maze[i][j];
			//cout<<maze[i][j];
			if(maze[i][j]!='#')
			{
				p.x=i; p.y=j; p.indx=nd;
				nodes.push_back(p);
				nd++;
				for(k=0;k<nodes.size();k++)
				{
					q=nodes[k];
					if((p.x==q.x+1 || p.x==q.x-1)&& p.y==q.y){adj[p.indx].push_back(q.indx); adj[q.indx].push_back(p.indx);}
					if((p.y==q.y+1 || p.y==q.y-1)&& p.x==q.x){adj[p.indx].push_back(q.indx); adj[q.indx].push_back(p.indx);}
				}
				if(maze[i][j]=='S')
				{snode=p.indx;}
			}
		}
		cout<<"\n";
	}
	/*for(i=0;i<nd; i++)
	{
		cout<<nodes[i].x<<" "<<nodes[i].y<<":- \n";
		for(j=0;j<adj[i].size();j++)
		{
			cout<<nodes[adj[i].at(j)].x<<" "<<nodes[adj[i].at(j)].y<<"\n";
		}
		cout<<"\n\n";
	}*/
	cout<<bfs(snode)<<"\n";
	return 0;
}