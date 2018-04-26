#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        ll u,v;
        cin>>u>>v;
        ll x;
        cin>>x;
        double d = u+v;
        double ans = double(x)/d;
        cout.precision(11);
        cout<<fixed<<ans<<"\n";

    }
	return 0;
}
