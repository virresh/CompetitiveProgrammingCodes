#include <bits/stdc++.h>
using namespace std;
#define sz 30005
#define inf 1000005
struct edge{
    int dest,wt;
};
vector<edge> adjList[sz];
int sDist[sz];
priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;
int main() {
	//freopen("inp.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b;
        memset(sDist,inf,sizeof(sDist));
        edge e;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int x,y,r;
            cin>>x>>y>>r;
            e.dest=y;
            e.wt=r;
            adjList[x].push_back(e);
            //adjList[y].push_back(edge{x,r});
        }
        cin>>a>>b;
        pq.push(make_pair(0,a));
        sDist[a]=0;
        while(!pq.empty()){
            pair<int,int> p;
            p=pq.top();
            pq.pop();
            int node=p.second,d=p.first;
            if(sDist[node]<d){continue;}
                for(int i=0;i<adjList[node].size();i++){
                    e=adjList[node][i];
                    if(sDist[node] + e.wt < sDist[e.dest]){
                        sDist[e.dest]= e.wt + sDist[node];
                        pq.push(make_pair(sDist[e.dest],e.dest));
                    }
                }
        }
        if(sDist[b]>=inf)
		{
			cout<<"NO\n";
		}
		else{
			cout<<sDist[b]<<"\n";
		}
        for(int i=1;i<=n;i++){
            adjList[i].clear();
        }
    }
    return 0;
}
