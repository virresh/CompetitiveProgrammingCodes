#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 105
bool bulb[sz]={false}; // is bulb on ?
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int j,t;
        cin>>j;
        for(int k=0;k<j;k++)
        {
            cin>>t;
            bulb[t]=true;   // turn on bulb t
        }
    }
    bool flag=true;
    for(int t=1;t<=m;t++)
    {
        if(!bulb[t])
        {
            flag=false;
        }
    }
    if(!flag){cout<<"NO\n";}
    else
    {
        cout<<"YES\n";
    }
    return 0;
}
