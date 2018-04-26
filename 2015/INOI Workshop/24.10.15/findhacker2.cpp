#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100002

ll indegree[sz];
ll outdegree[sz];
int main()
{
    ll t,m,n=sz,i,h,q,flag=0;
    cin>>t;
    while(t--)
    {
        memset(indegree,0,sizeof(indegree));
        memset(outdegree,0,sizeof(outdegree));
        flag=0;
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            cin>>h>>q;
            indegree[q]++;
            outdegree[h]++;
        }
        for(i=1;i<=n;i++)
        {
            if(indegree[i]==0 && outdegree[i]>0){cout<<i<<"\n"; flag=1; break;}
        }
        if(flag==0){cout<<"-1\n";}
    }
    return 0;
}
