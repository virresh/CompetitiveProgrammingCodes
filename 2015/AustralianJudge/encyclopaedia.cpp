#include <iostream>
#include <cstdio>
#define ll long long
#define sz 10001
using namespace std;
ll p[sz];
int main()
{
    freopen("encyin.txt","r",stdin);
    freopen("encyout.txt","w",stdout);
    ll n,q,x,i;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    for(i=1;i<=q;i++)
    {
        cin>>x;
        cout<<p[x]<<"\n";
    }
    return 0;
}
