#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz 100000+5

vector <int> adjList[sz];
int visited[sz];
vector <int> indices[11]; // this stores all the indices where a number appears in the string s
void process(string s)
{
	int i;
	for(i=0;i<s.length();i++)
	{
		int k=s[i]-'0';
		if(i-1>=0){adjList[i].pb(i-1);}
		if(i+1 < s.length()){adjList[i].pb(i+1);}
		int tsize=indices[k].size();
		for(int j=0;j<tsize;j++)
		{
			if(!(indices[k][j]-i == 1) && !(i-indices[k][j] == 1))	// not neigbours already
			{
				adjList[i].pb(indices[k][j]);
				adjList[indices[k][j]].pb(i);
			}
		}
		indices[k].pb(i);
	}
}
void display_graph(string s)
{
	for(int i=0;i<s.length();i++)
	{
		cout<<"Showing neigbours of node \t"<<i<<" with a value of "<<s[i]<<"\n";
		int t=adjList[i].size();
		for(int k=0;k<t;k++)
		{
			cout<<" "<<adjList[i][k]<<"\n";
		}
		cout<<"\n";
	}
}

int bfs(int start_node,int end_node)
{
	int t;
	queue <int> q;
	visited[start_node]=1;
	q.push(start_node);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		int k=adjList[t].size();
		for(int I=0;I<k;I++)
		{
			int x=adjList[t][I];
			if(!visited[x])
			{
				q.push(x);
				visited[x]=visited[t]+1;
				if(x==end_node)
				{
					return visited[end_node]-1;
				}
			}
		}
	}
}
int main()
{
    string s;
	cin>>s;
	process(s); // makes the graph for s
	//display_graph(s);
	cout<<bfs(0,s.length()-1)<<"\n";
    return 0;
}