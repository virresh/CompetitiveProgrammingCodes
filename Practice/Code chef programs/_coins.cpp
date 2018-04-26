#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define ms 1000000
ll a[ms]={0};
ll maxsum(ll n)
{
   if(n<12){ a[n]=n; return n;}
   if(n<ms)
   {
       if(a[n]!=0){return a[n];}
       else
       {
       a[n]=max(n,maxsum(n/2)+maxsum(n/3)+maxsum(n/4));
       return a[n];
       }
   }
   else
    {
        ll temp=max(n,maxsum(n/2)+maxsum(n/3)+maxsum(n/4));
        return temp;
    }
}
int main()
{
    ll n;
    while(cin>>n)
    {
        cout<<maxsum(n)<<"\n";
    }
    return 0;
}
