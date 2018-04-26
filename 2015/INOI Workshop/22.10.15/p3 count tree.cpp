#include <bits/stdc++.h>
#define ll long long
#define md 1000000007
using namespace std;
// Count tree
ll k,n,mem[302],fct[302],pow2[6];
void precomputefac()
{
    mem[0]=1;
    mem[1]=1;
    //mem[2]=4;
    ll i=2; fct[0]=1;  fct[1]=1;
    for(i=2; i<302; i++)
    {
        fct[i]=fct[i-1]*i%md;
    }
}

ll f(ll n)
{
    if(mem[n]!=-1){return mem[n];}
    ll res=0,i;
    for(i=1; i<=n; i++)
    {
        res+= f(i)%md;
    }
    mem[n]=((fct[n] )*(res%md))%md;
    return mem[n];

}

int main()
{
    memset(fct,-1,sizeof(fct));
    memset(mem,-1,sizeof(mem));
    precomputefac();
    cin>>k;
    while(k--)
    {
        cin>>n;
        cout<<f(n)<<"\n";
    }
    //cin>>k;
    //cout<<f(k);
    return 0;
}
