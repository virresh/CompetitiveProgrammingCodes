#include <bits/stdc++.h>
using namespace std;
#define sz 1000005
bool holes[sz];

int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    memset(holes,false,sizeof(holes));
    for(int i=1; i<=m; i++)
    {
        int p;
        cin>>p;
        holes[p] = true;
    }
    int ans=-1,curPosition=1;
    if(holes[curPosition]==true)
    {
        ans = curPosition;
    }
    for(int i=1; i<=k; i++)
    {
        int u,v;
        cin>>u>>v;
        if(u==curPosition)
        {
            curPosition = v;
        }
        else if(v==curPosition){
            curPosition = u;
        }

        if(holes[curPosition]==true && ans == -1)
        {
            ans = curPosition;
        }
    }
    if(ans==-1)
    {
        cout<<curPosition<<"\n";
    }
    else
    {
        cout<<ans<<"\n";
    }
	return 0;
}
