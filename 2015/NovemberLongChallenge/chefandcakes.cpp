#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,n,m,k,ans=1;
    cin>>t;
    while(t--)
    {
        set <int> s;
        ans=1;
        cin>>n>>m;
        k=m+1;
        do
        {
            s.insert(k);
            k=(k-1+m)%(n)+1;
            //cout<<k<<" ";
            if(s.find(k)!=s.end()){break;}
            ans++;
            cout<<k<<" "<<ans<<"\n";
        }while(1);
        if(ans==n){cout<<"Yes\n";}
        else {cout<<"No "<<n-ans<<"\n";}
    }
    return 0;
}
