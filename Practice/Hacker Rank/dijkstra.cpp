#include <bits/stdc++.h>
using namespace std;
#define INF 1200000
#define ii pair<int,int>
vector <ii> alist[3005];
priority_queue <ii,vector<ii>,greater<ii> > pq;
int main() {
    freopen("dij.in","r",stdin);
    freopen("dij.out","w",stdout);
    int t,m,n,s;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int x,y,r;
            cin>>x>>y>>r;
            alist[x].push_back(ii(r,y));
            alist[y].push_back(ii(r,x));
        }
        cin>>s;
        pq.push(ii(0,s));
        int dist[3005];
        for(int k=0;k<=n;k++)
            {dist[k]=INF;}
        dist[s]=0;
        while(!pq.empty())
        {
            ii front=pq.top(),v;
            pq.pop();
            int u=front.second,d=front.first;
            cerr<<u<<" ";
            if(d>dist[u]){continue;}
            for(int k=0;k<alist[u].size();k++)
            {
                v=alist[u][k];
                if(dist[u]+v.first<dist[v.second])
                {
                    dist[v.second]=dist[u]+v.first;
                    pq.push(ii(dist[v.second],v.second));
                }
            }
        }
        for(int l=1;l<=n;l++)
        {
            /*if(l==s){}
            else if(dist[l]!=INF)
                cout<<dist[l]<<" ";
            else
                cout<<"-1 ";
                */
                cout<<dist[l]<<" ";
        }

    }
    return 0;
}
