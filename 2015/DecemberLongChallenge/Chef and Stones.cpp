#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ll t,n1,n2,m,x;
    cin>>t;
    while(t--)
    {
        cin>>n1>>n2>>m;
        if(min(n1,n2)>(m*(m+1))/2){x=((m)*(m+1))/2;}
        else
        {

        }
        cout<<n1+n2-2*x<<"\n";
    }
    return 0;
}
