#include <bits/stdc++.h>
using namespace std;
#define ll long long
void maxswap(ll &a, ll &b)
{
    if(a<b){ll t=b; b=a; a=t;}
}
int main()
{
    int t,i;
    ll a,b;
    cin>>t;
    while(t--)
    {
        i=0;
        cin>>a>>b;
        while(a>0 && b>0)
        {
            maxswap(a,b);
            a-=b;
            i++;
        }
        cout<<i<<"\n";
    }
    return 0;
}
