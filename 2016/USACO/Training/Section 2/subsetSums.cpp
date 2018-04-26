#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,ans=0;
bool s[40]={false};
//int ways[1600];
/*
ID: virresh1
PROG: subset
LANG: C++
*/
void solve(int sum,int i)      //complete search
{
    //cout<<"SUM : "<<sum<<" SET : ";
    //for(int q=1;q<=n;q++){cout<<s[q]<<" ";}  cout<<"\n";
    if(sum==0){ans++; return;}
    if(sum<0){return;}
    if(i==n+1){return;}
    for(int j=i;j<=n;j++)
    {
        if(!s[j] && j<=sum)
        {
            //cout<<i<<" "<<j<<" "<<sum<<" ";
            s[j]=true;      //select this number
            solve(sum-j,j+1);
            s[j]=false;     // backtrack
        }
        if(j>sum){break;}
    }
}
int main()
{
    //memset(ways,0,sizeof(ways));
    //s[0]=true;
    //freopen("subset.in","r",stdin);
    //freopen("subset.out","w",stdout);
    cin>>n;
    int q=n*(n+1)/2;
    if(q%2==0)
    {
        solve(q/2,1);
        cout<<ans/2<<"\n";
    }
    else
    {
        cout<<"0\n";
    }
    /*for(int j=1;j<=(n*(n+1))/2;j++)
    {
        cout<<ways[j]<<" ";
    }*/
    return 0;
}
