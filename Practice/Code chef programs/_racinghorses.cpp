#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define INF 1000000005
ll s[5005];
int main()
{
    ll t,n,i,x; // y--> smallest x--> second smallest
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>s[i];
        }
        sort(s,s+n);
        x=s[1]-s[0];
        for(i=1;i<n;i++)
        {
            x=min(s[i]-s[i-1],x);
        }
        cout<<x<<"\n";
    }
    return 0;
}
