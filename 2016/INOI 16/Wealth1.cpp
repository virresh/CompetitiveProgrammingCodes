#include <bits/stdc++.h>
using namespace std;
/* Viresh Gupta, 36003 , Wealth Disparity */

/*
4 5 10 6 12 2 -1 4 2
*/
#define sz 100005
#define ii pair<int,int>
int n,root,gmax=-sz;
int parent[sz],wealth[sz];
vector  <int> alist[sz];
bool visited[sz]={false};
void printg()
{
	int i;
	for(i=0;i<n;i++)
	{
		int n2=alist[i].size();
		cout<<"Neigbours of "<<i<<" :\n";
		for(int k=0;k<n2;k++)
		{
			int q=alist[i][k];
			cout<<q<<"\n";
		}
	}
}

/*void dfs(int cnode,int csum)
{
	if(csum>gsum){gsum=csum;
	}
	for(int j=0; j<alist[cnode].size();j++)
	{
		ii p=alist[cnode][j];
		
	}
}*/

stack <ii> s;
void solve(int current)
{
	bool visited[sz]={false};
	vector <int> v;
	queue <int> q;
	q.push(current);
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		if(!visited[p])
		{
			visited[p]=true;
			int n1=alist[p].size();
			for(int j=0;j<n1;j++)
			{
				int pa=alist[p][j];
				if(!visited[pa])
				{
					q.push(pa);
				}
			}
			if(abs(wealth[p]-wealth[current])>gmax)
			{
				gmax=abs(wealth[p]-wealth[current]);
			}
		}
	}
	
}
void fullSearch()
{
	for(int i=0;i<n;i++)
	{
		solve(i);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>wealth[i];
	}
	for(int j=0;j<n;j++)
	{
		cin>>parent[j];
		if(parent[j]!=-1) 
		{
		    alist[parent[j]-1].push_back(j);   // first has edge length , second has index no
	    }
	    else
	    {
	    	root=j;
	    }
	}
	//printg();
	fullSearch();
	cout<<gmax<<"\n";
	return 0;
}