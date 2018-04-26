#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int t,n,m;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m;
        if(n<m){cout<<'<';}
        else if(n>m){cout<<'>';}
        else {cout<<'=';}
        cout<<"\n";
    }
    return 0;
}
