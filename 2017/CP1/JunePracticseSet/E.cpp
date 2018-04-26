#include <bits/stdc++.h>
using namespace std;
typedef int ll ;

#define sz 100005

vector<ll> adjL[sz];
vector<ll> revL[sz];
ll n,m,k,OreN,IronN;
vector<ll> iron, ore;

ll distOre[sz], distIron[sz], distSrc[sz];

void bfs(vector<ll> graph[], ll src, ll dist[])
{
//    for(ll i=1; i<=n+2; i++)
//    {
//        cout<<"Neigbours of "<<i<<" : ";
//        for(ll j=0; j<graph[i].size(); j++)
//        {
//            cout<<graph[i][j]<<" ";
//        }
//        cout<<"\n";
//    }

    queue<ll> q;
    bool visited[sz];
    memset(visited, false, sizeof(visited));
    q.push(src);
    dist[src]=0;
    while(!q.empty())
    {

        ll u = q.front();
        //cout<<u<<" ";
        q.pop();
        visited[u] = true;
        for(ll i=0; i<graph[u].size(); i++)
        {
            ll v = graph[u][i];
            if(!visited[v])
            {
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    //cout<<"\n\n";
}

int main()
{
    for(int i=0; i<sz; i++)
    {
        distSrc[i] = -1;
        distIron[i] = -1;
        distOre[i] = -1;
    }
    cin>>n>>m>>k;
    OreN = n+2;
    IronN = n+1;
    for(ll i=0; i<m; i++)
    {
        ll id;
        cin>>id;
        iron.push_back(id);
        revL[IronN].push_back(id);
        adjL[id].push_back(IronN);
    }

    for(ll i=0; i<k; i++)
    {
        ll id;
        cin>>id;
        ore.push_back(id);
        revL[OreN].push_back(id);
        adjL[id].push_back(OreN);
    }

    for(ll i=1; i<=n; i++)
    {
        ll t;
        cin>>t;
        while(t--)
        {
            ll v;
            cin>>v;
            adjL[i].push_back(v);
            revL[v].push_back(i);
        }
    }

    bfs(adjL,1,distSrc);
    bfs(revL,OreN,distOre);
    bfs(revL,IronN,distIron);

    ll ans=INT_MAX;
        for(ll i=2; i<=n; i++)
        {
            if(distSrc[i]!=-1 && distOre[i]!=-1 && distIron[i]!=-1)
            {
                ans= min(ans,(distSrc[i] + distOre[i] + distIron[i]));
            }
        }
        if(ans==INT_MAX)
            cout<<"impossible\n";
        else
            cout<<ans-2<<"\n";
	return 0;
}
