#include <iostream>
#include <cstdio>
#define ll int
#define sz 10005
using namespace std;
ll word[sz][2]; // 0-> integerlandese 1-> Wholenumberland
int query(ll x,ll &t,ll n)
{
    t=-1;
    for(ll i=0; i<n;i++)
    {
        if(word[i][0]==x){t=i; return 1;}
    }
    return 0;
}
int main()
{
    freopen("dictin.txt","r",stdin);
    freopen("dictout.txt","w",stdout);
    ll d,w,x,i,t;
    cin>>d>>w;
    for(i=0;i<d;i++)
    {
        cin>>word[i][0]>>word[i][1];
    }
    for(i=1;i<=w;i++)
    {
        cin>>x;
        if(query(x,t,d)==1){cout<<word[t][1]<<"\n";}
        else{cout<<"C?"<<"\n";}
    }
    return 0;
}
