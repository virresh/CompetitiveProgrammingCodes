#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 200002
ll a[sz];
int main()
{
    ll n,i,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=n-1; i>=0; i--)
    {
        ans+= a[i]*(2*i-n+1);
    }
    cout<<ans;
    return 0;
}
