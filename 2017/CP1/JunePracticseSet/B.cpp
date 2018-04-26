#include <bits/stdc++.h>
using namespace std;
#define sz 20005
#define INF 1000000


void djikstra(int dist[],int src,vector<pair<int,int> > adjL[])
{
    priority_queue < pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0,src));
    dist[src]=0;
    while(!pq.empty())
    {
        pair<int,int> temp = pq.top();
        pq.pop();
        int u = temp.second,d=temp.first;
        if(d>dist[u]){
            continue;
        }
        for(int i=0; i<adjL[u].size(); i++)
        {
            int v = adjL[u][i].second;
            int wt = adjL[u][i].first;
            if(dist[v] > dist[u]+wt)
            {
                dist[v] = dist[u] + wt;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,M,V,B,G,H, GHdistance=-1;
        int parent[sz];
        int dist[sz],distG[sz],distH[sz];
        memset(dist,INF,sizeof(dist));
        memset(distG,INF,sizeof(distG));
        memset(distH,INF,sizeof(distH));

        cin>>N>>M>>V;
        cin>>B>>G>>H;
        for(int i=1; i<=N; i++)
        {
            parent[i] = i;
        }
        vector<pair<int, int> >adjL[sz];
        vector<int> destinations;
        for(int i=0; i<M; i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            if((u==G && v==H)||(u==H && v==G)){
                GHdistance = c;
            }
            adjL[u].push_back(make_pair(c,v));
            adjL[v].push_back(make_pair(c,u));
        }
        for(int i=0; i<V; i++)
        {
            int z;
            cin>>z;
            // destinations.insert(z);
            destinations.push_back(z);
        }

        djikstra(dist,B,adjL);
        djikstra(distG,G,adjL);
        djikstra(distH,H,adjL);
        sort(destinations.begin(),destinations.end());
        for(int i=0; i<destinations.size(); i++)
        {
            bool possible=false;
            int v=destinations[i]; //possible bus stand
            int aD,bD,cD=GHdistance;
            // take G closer to B and H closer to V
            aD = dist[G];
            bD = distH[v];
            if(aD + bD + cD == dist[v]){
                possible=true;
            }
            // take H closer to B and G closer to V
            aD = dist[H];
            bD = distG[v];
            if(aD + bD + cD == dist[v]){
                possible = true;
            }

            if(possible)
            {
                cout<<destinations[i]<<" ";
            }
        }
        cout<<"\n";

//        for(int i=1; i<=N; i++)
//        {
//            cout<<parent[i]<<" ";
//        }
//        cout<<"\n";
//
//        for(int i=1; i<=N; i++)
//        {
//            cout<<dist[i]<<" ";
//        }
//        cout<<"\n";
    }
	return 0;
}

/*
1
9 13 0
9 1 2
9 1 4
9 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
