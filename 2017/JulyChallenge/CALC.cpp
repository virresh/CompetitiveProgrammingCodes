#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,b;
        cin>>n>>b;
        int lo = 1, hi=n, ans=-1;
        while(lo<hi)
        {
            ll mid=(lo+hi)/2;
            // spend the first mid units in pressing first screen
            ll energy = mid + b*(n-mid);
            if(energy <= n)
            {
                lo = mid;
            }
            else
            {
                hi = mid-1;
            }

        }
        ll f_mid = (lo)*(n-lo);
        cout<<f_mid<<" "<< lo<<"\n";
    }
	return 0;
}
