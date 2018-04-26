#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 200000000000000ll


int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,k,x,m,s;
		ll dist[100005];
		vector < pair<ll,ll> > adjL[100005];
		cin>>n>>k>>x>>m>>s;
		// every old city has a distance x from another old city
		for(ll i=1; i<=m; i++){
			ll a,b,c;			
			cin>>a>>b>>c;
			adjL[a].push_back(make_pair(b,c));
			adjL[b].push_back(make_pair(a,c));
			// make an adjacency list from the m edges
		}
		//apply djikstra's on them
		for(ll i=1; i<=n; i++){
			if(i!=s){
				dist[i]=INF;
			}
			else{
				dist[i]=0;
			}
		}

		priority_queue < pair<ll,ll>, vector< pair<ll,ll> >, greater<pair<ll,ll> > > pq;
		pq.push(make_pair(0ll,s));
		while(!pq.empty()){
			ll u = pq.top().second;
			ll d = pq.top().first;
			pq.pop();

			if(d>dist[u]){
				continue;
			}
			for(ll j=0; j<adjL[u].size(); j++){
				ll v = adjL[u][j].first;
				ll w = adjL[u][j].second;
				if(dist[v] > dist[u]+w){
					dist[v]=dist[u]+w;
					pq.push(make_pair(dist[v],v));
				}
			}
		}

		ll minD = 1;
		for(ll i=1; i<=k; i++){
			if(dist[i] < dist[minD]){
				minD=i;
			}
		}

		for(ll i=1; i<=k; i++){
			if(dist[i] > dist[minD]+x){
				dist[i]=dist[minD]+x;
			}
		}
		for(ll i=1; i<=k; i++)
		{
			// for(ll j=0; j<adjL[i].size(); j++){
			// 	pq.push(make_pair(adjL[i][j].second,i));
			// 	//cout<<adjL[i][j].second<<" "<<i<<"\n";
			// }
			pq.push(make_pair(dist[i],i));
		}
		while(!pq.empty()){
			ll u = pq.top().second;
			ll d = pq.top().first;
			pq.pop();

			if(d>dist[u]){
				continue;
			}
			for(ll j=0; j<adjL[u].size(); j++){
				ll v = adjL[u][j].first;
				ll w = adjL[u][j].second;
				if(dist[v] > dist[u]+w){
					dist[v]=dist[u]+w;
					pq.push(make_pair(dist[v],v));
				}
			}
		}


		for(ll i=1; i<=n; i++){
			cout<<dist[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}