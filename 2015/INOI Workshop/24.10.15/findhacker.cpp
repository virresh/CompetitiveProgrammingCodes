#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 10002
vector <int> adj[sz];
bool arr[sz][sz];
int main()
{
    ll t,m,n=sz,i,h,q,k,j;
    cin>>t;
    while(t--)
    {
        memset(arr,0,sizeof(arr));
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            cin>>h>>q;
            adj[h].push_back(q);
        }
        for(i=1;i<n;i++)
        {
            for(j=0; j<adj[i].size(); j++)
            {

            }
        }
    }
    return 0;
}
