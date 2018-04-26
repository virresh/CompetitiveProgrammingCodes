#include <bits/stdc++.h>
using namespace std;
#define  ll long long
int money[11];
bool f(int *a,int n,int m)
{
    if(n==0){return m==a[n];}
    else if(n<0)
    {
        return false;
    }
    else if(m==0){return true;}
    else if(m<0){return false;}
    else
    {
        if(f(a,n-1,m) || f(a,n-1,m-a[n])){return true;}
        return false;
    }
}
int main()
{
    int t,n,m,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>money[i];
        }
        if(f(money,n-1,m)){cout<<"Yes\n";}
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}
