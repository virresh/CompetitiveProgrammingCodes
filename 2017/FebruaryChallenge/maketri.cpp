#include <bits/stdc++.h>

using namespace std;

#define sz 1000005
#define ll long long

int a[sz];

int  main(){
    ll n,l,r,maxele=0,minele=LONG_LONG_MAX;
    cin>>n>>l>>r;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);
    ll mstr = a[n-1]+a[n-2];

    return 0;
}
