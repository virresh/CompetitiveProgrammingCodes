#include <bits/stdc++.h>
using namespace std;

#define sz 100005
#define mod 1000000007
#define ll long long

ll a[sz];

int main()
{
    ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
    {
        int N;
        cin>>N;
        ll g=0;
        for(int i=0; i<N; i++)
        {
            cin>>a[i];
            if(i==0){
                g = a[i];
            }
            else{
                g = __gcd(g,a[i]);
            }
        }
        ll ans=1;
        for(int i=0; i<N; i++)
        {
            ans = (ans * (a[i] / g)%mod)%mod;
        }
        cout<<ans<<"\n";
    }
	return 0;
}
