#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int t,n,x,maxe=-1,mine=100;
    cin>>t;
    while(t--)
    {
        mine=100; maxe=-1;
        cin>>n;
        while(n--)
        {
            cin>>x;
            if(x>maxe){maxe=x;}
            if(x<mine){mine=x;}
        }
        cout<<2*(maxe-mine)<<"\n";
    }
    return 0;
}
