#include <bits/stdc++.h>
#define ll long long
#define sz 1000005
using namespace std;

//ll pre[sz];
int main()
{
    /*for(ll i=0;i<sz;i++)
    {
        pre[i]=i*(i+1)/2 ;
    }*/
    int t;
    cin>>t;
    ll n,x;
    while(t--)
    {
        cin>>n;
        x=(ll)((sqrt(1+8*n)-1)/2);
        cout<<x<<"\n";
    }
    return 0;
}
