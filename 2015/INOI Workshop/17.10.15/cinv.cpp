#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100000
pair<ll,ll> a[sz],c;
bool comp(pair<int,int> a, pair<int,int>b)
{
    return a.first<b.first;
}
int main()
{
    int t;
    ll n,i,res=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i].first);
            a[i].second=i;
        }
        //for(i=0;i<n;i++)
        //printf("%d %d %d\n",a[i].first,a[i].second);
        sort(a,a+n);
        c=a[n-1];
        res=0;
        for(i=n-2;i>=0;i--)
        {
            if(a[i].second<c.second)
            {
                c=a[i];
            }
            else
            {
                if ((a[i].second-c.second)>res){res= a[i].second-c.second;}
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
