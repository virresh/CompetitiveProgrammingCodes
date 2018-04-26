#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll N,Q,R,key;

unordered_map<ll,ll> keyOf;
unordered_map<ll,ll> keyMax;
unordered_map<ll,ll> keyMin;
unordered_map<ll,ll> parent;

ll getBits(ll x){
    return __builtin_popcount(x);
}

ll doMin(ll v, ll k){
    ll tMin = k^keyMin[v];
	return tMin;
}

ll doMax(ll v, ll k){
    ll tMax = k^keyMax[v];
	return tMax;
}

int main(){

	cin >> N >> Q;
	cin >> R >> key;

	parent[R] = -1;
	keyOf[R] = key;
	keyMax[R]= key;
	keyMin[R] = key;

	ll i,t;
	ll u,v,k;
	for (i = 0; i < N-1; i++)
	{
		cin >> u >> v >> k;
		parent[u] = v;
		keyOf[u] = k;

		ll a = getBits(k);
		ll b = getBits(keyMax[v]);
		ll c = getBits(keyMin[v]);

		keyMax[u] = a<b ? keyMax[v] : k;
		keyMin[u] = a>c ? keyMin[v] : k;

		//cout<<"Parent of "<<u<<" is "<<parent[u]<<"\n";
	}

	ll last_answer = 0;

	for (i = 0; i < Q; i++)
	{
		cin >> t;

    	// find real value of t
		t ^= last_answer;
		//cout<<last_answer<<"\n";
		//cout<<t<<"\n";

		if (t == 0)
		{
			//add a new station
			cin >> v >> u >> k;
        	// find real values for u, v, and k
			u ^= last_answer;
			v ^= last_answer;
			k ^= last_answer;

			//cout<<v<< " "<<u<<" "<<k<<"\n";
			keyOf[u] = k;
			parent[u] = v;

			ll a = getBits(k);
            ll b = getBits(keyMax[v]);
            ll c = getBits(keyMin[v]);

            keyMax[u] = a<b ? keyMax[v] : k;
            keyMin[u] = a>c ? keyMin[v] : k;
		}
		else
		{
		    // do the security check
			cin >> v >> k;
        	// find real values for v, and k
			v ^= last_answer;
			k ^= last_answer;

        	// compute the requested values
			ll min_answer = doMin(v,k);
			ll max_answer = doMax(v,k);

			cout << min_answer << " "<< max_answer<<"\n";

			// update last_answer
			last_answer = min_answer ^ max_answer;
		}
	}

	return 0;
}
