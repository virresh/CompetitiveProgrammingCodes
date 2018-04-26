#include <bits/stdc++.h>

using namespace std;
#define sz 100005
#define ll long long
ll a[sz];
int main()
{

    ll n;
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ll ans=0;

    if(a[0]!= a[1] && a[1]!=a[2]){
        int i=2;
        ll cnt=1;
        while(a[i+1]==a[i] && i+1<n){
                cnt++;
                i++;
        }
        ans = cnt;
    }
    else if(a[0]!=a[1] && a[1]==a[2]){
        int i=1;
        ll cnt=1;
        while(a[i+1]==a[i] && i+1<n){
                cnt++;
                i++;
        }
        ans = cnt * (cnt-1)/2;
    }
    else if(a[0] == a[1] && a[1] == a[2]){
        int i=0;
        ll cnt=1;
        while(a[i+1]==a[i] && i+1<n){
                cnt++;
                i++;
        }
        ans = cnt * (cnt-1) * (cnt-2)/6;
    }
    else if(a[0]==a[1] && a[1]!=a[2])
    {
        int i=2;
        ll cnt = 1;
        while(a[i+1]==a[i] && i+1<n){
                cnt++;
                i++;
        }
        ans = cnt;
    }

    cout<<ans<<"\n";

    return 0;
}
