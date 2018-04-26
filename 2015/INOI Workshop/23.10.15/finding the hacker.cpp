#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000005
vector <int> adjList[sz];
vector <int> masterHackers;
int isHackedBy[sz];
int Hacks[sz];
int main()
{
    int t,n,m,i,h,q,j;
    cin>>t;
    while(t--)
    {
        memset(isHackedBy,0,sizeof(isHackedBy));
        masterHackers.clear();
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            cin>>h>>q;
            adjList[h].push_back(q);
            isHackedBy[q]++;

        }
        for(i=1;i<=n;i++)
        {
            Hacks[i]
        }
        for(i=1;i<=n;i++)
        {
            if(isHackedBy[i]==0 && adjList[i].size()!=0)
            {
                masterHackers.push_back(i);
            }
        }

        if(masterHackers.size()!=0)
            cout<<masterHackers[0]<<"\n";
        else
            cout<<"-1\n";
        for(i=0;i<n;i++)
        {
            adjList[i].clear();
        }
    }
    return 0;
}
