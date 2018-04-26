#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1005
struct player
{
    int id,ls;
};
player a[sz];

bool comp(player a,player b)
{
    if(a.ls!=b.ls)
        return a.ls>b.ls;
    else
    {
        return a.id<b.id;
    }
}
int main()
{
    freopen("listin.txt","r",stdin);
    freopen("listout.txt","w",stdout);
    int f,i,x,y;
    player p;
    cin>>f;
    for(i=0;i<sz;i++)
    {
        a[i].id=i; a[i].ls=0;
    }
    for(i=0;i<f;i++)
    {
        cin>>x>>y;
        a[x].ls++; a[y].ls++;
    }
    sort(a,a+sz,comp);
    x=a[0].ls;
    for(i=0;a[i].ls==x;i++)
    {
        cout<<a[i].id<<"\n";
    }
    return 0;
}
