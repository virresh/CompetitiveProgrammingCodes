#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 500001
ll num[sz];
int main()
{
    ll n,t,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>num[i];
    }
    sort(num,num+n);
    ll ans=0;
    for(i=0;i<n;i++)
    {
        t=num[i] * (n-i);
        if(t>ans){ans=t;}
    }
    cout<<ans<<"\n";
    return 0;
}
