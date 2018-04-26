#include <bits/stdc++.h>
#define ll long long
#define sz 300000
using namespace std;

ll t,n,m,a[sz];
int main()
{
    ll i,r,l,window,res=0;
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        r=l=0;window=a[l];
        while(r<n)
        {
            if(window<m)
                {
                    r++;
                    window+=a[r];
                    if(window>res && window <=m)
                    {res=window;}
                }
            else if(window>m)
            {
                    window-=a[l]; l++;
                    if(window<=m && window >res){res=window;}
            }
            else
            {
                    res=m; break;
            }
        }
        cout<<res;
    return 0;
}
