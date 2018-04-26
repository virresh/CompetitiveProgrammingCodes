#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100005
ll a[sz],pre[sz];
set<pair<ll,pair<int,int> > > pq;
set<pair<ll,pair<int,int> > >::iterator it;
//vector <ll> v;
int sumq(ll l,ll r)  //return sum[L,R]
{
    return pre[r]-pre[l]+a[l];   // a1+a2+a3+a4+... aR - a1 -a2 -a3-...-aL
                                // aL+1  + aL+1 +... aR =Sum (L,R]
}

void solve(ll l,ll r)
{
    if(l<=r)
    {
        //cout<<l<<" "<<r<<"\n";
        pq.insert(make_pair(sumq(l,r),make_pair(l,r)));
        //v.push_back((sumq(l,r)));
        solve(l+1,r);
        solve(l,r-1);
    }
}
int main()
{
    ll n,k;
    cin>>n>>k;
    pre[0]=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];  //calculate prefix sums
    }
    solve(1,n);
    it=pq.end();
    it--;
    //sort(v.begin(),v.end(),greater<ll>());
    for(ll i=0;i<k;i++,it--)
    {
        cout<<(*it).first<<"\n";
    }
    //cout<<"\n"<<v.size()<<"\n";
    return 0;
}
