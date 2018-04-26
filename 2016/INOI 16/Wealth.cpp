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
vector  <ii> alist[sz];

void printg()
{
	int i;
	for(i=0;i<n;i++)
	{
		int n2=alist[i].size();
		cout<<"Neigbours of "<<i<<" :\n";
		for(int k=0;k<n2;k++)
		{
			ii q=alist[i][k];
			cout<<q.second<<"\t"<<q.first<<"\n";
		}
	}
}

void dfs(int cnode,int csum)
{
	if(csum>gmax)
	{
		gmax=csum;
	}
	int q=alist[cnode].size();
	for(int j=0;j<q;j++)
	{
		ii p=alist[cnode][j];
		int diff=p.first,u=p.second;
		//cout<<cnode<<" "<<u<<"\n";
		if(csum+diff >= diff)
		{
			dfs(u,csum+diff);
		}
		else if(abs(diff) > csum)
		{
			dfs(u,diff);
		}
	}
	//cout<<csum<<"\n";
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
		    int d=wealth[parent[j]-1]-wealth[j];
		    alist[parent[j]-1].push_back(ii(d,j));   // first has edge length , second has index no
	    }
	    else
	    {
	    	root=j;
	    }
	}
	//printg();
	dfs(root,gmax);
	cout<<gmax<<"\n";
	return 0;
}