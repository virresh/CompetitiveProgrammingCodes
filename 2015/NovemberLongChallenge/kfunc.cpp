#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll f(ll a)
{
    if(a==0){return 0;}
    ll p=a%9;
    if(p==0){return 9;}
    else {return p;}
}
int main()
{
    ll t,d,l,r,a;
    cin>>t;
    while(t--)
    {
        cin>>a>>d>>l>>r;
        cout<<f()
    }
    return 0;
}
