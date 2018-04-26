#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

int main()
{
    freopen("rainin.txt","r",stdin);
    freopen("rainout.txt","w",stdout);
    ll n,c,currentvol=0,t=0,flag=0,i,days=0;
    cin>>n>>c;
    for(i=1;i<=n;i++)
    {
        cin>>t;
        currentvol+=t;
        if(currentvol>=c && flag==0){days=i; flag=1;}
    }
    cout<<days;
    return 0;
}
