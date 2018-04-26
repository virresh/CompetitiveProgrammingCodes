#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for (int iN = 1; iN <= t; ++iN)
	{
		set<string> places;
		map<string, string> graph;
		map<string, string> revgraph;
		int n;
		cin>>n;
		for(int i=0; i<n; i++)
		{
			string u,v;
			cin>>u>>v;
			graph.insert(pair<string,string>(u,v));
			revgraph.insert(pair<string,string>(v,u));
			places.insert(u);
			places.insert(v);
		}	

		string endVertex;
		for(set<string>::iterator it = places.begin(); it!=places.end(); it++)
		{
			string q = *it;
			if(graph.find(q) == graph.end())
			{
				endVertex = q;
				break;
			}
		}

		stack<string> result;
		while(revgraph.find(endVertex) != revgraph.end())
		{
			result.push(endVertex);
			endVertex = revgraph[endVertex];
		}
		cout<<"Case #"<<iN<<": ";
		while(!result.empty())
		{
			string p = result.top(); result.pop();
			cout<<revgraph[p]<<"-"<<p<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
