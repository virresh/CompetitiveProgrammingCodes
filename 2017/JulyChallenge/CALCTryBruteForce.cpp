#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,b;
        cin>>n>>b;
        ll ans=0;

        ll midBK = ll (ceil(floor(float(n)/float(b))/2.0 ));

        ans = midBK * (n-b*midBK);

/*        for(ll k=1; (n-b*k)>0; k++)
        {
            ll e2 = b*k; // energy spent in second button
            ll e1 = n - b*k;
            cout<<"K = "<< k << " Val = "<< k * e1<<"\n";
            ans = max(ans, k * (n-b*k));
        }*/
        cout<<ans<<"\n";
    }
	return 0;
}
