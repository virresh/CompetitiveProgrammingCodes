#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000000
ll a[sz];
ll bsearch(ll n,ll k,ll i)
{
    ll low=0, high=n-1,mid=9;
    while(low<high)
    {
        mid= (low+high)/2;
        if(a[mid]<k+a[i]){low=mid+1;}
        else if(a[mid]>= k +a[i]){high=mid;}
    }
    if(a[low]-a[i]>=k)
    return low;
    return -1;
}
int main()
{
    ll n,k,i,ans=0,l;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        l=bsearch(n,k,i);
        if(l!=-1){ans+= n-l;}
    }
    cout<<ans<<" ";
    return 0;
}
