#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 10005
int a[sz][sz];

int main()
{
    memset(a,0,sizeof(a));
    int n,i,j,q,k,li,ri,tparity=0,x,y;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>li>>ri;
        for(k=li;k<=ri;k++)
        {
            a[i][k]=1;
            a[i][0]++;
            a[0][k]++;
            tparity++;
        }
    }
    /*for(j=0;j<=n;j++)
    {
        for(k=0;k<=n;k++)
        {
            cout<<a[j][k]<<" ";
        }
        cout<<"\n";
    }*/
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>x>>y;
        cout<< (((tparity-a[x][0]-a[0][y]+a[x][y])%2==0) ? "E" : "O" )<<"\n";
    }
    return 0;
}
