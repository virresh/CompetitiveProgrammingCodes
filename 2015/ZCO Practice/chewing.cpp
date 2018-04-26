#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000003
ll a[sz];
int main()
{
    ll n,k,i,cnt=0,t;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;a[i]<k;i++)
    {
        t= lower_bound(a,a+n,k-a[i])-a-1 ;
        if(t<i){break;}
        cnt+=t-i;
    }
    cout<<cnt;
    return 0;
}
