#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct citizen{
    int cobol,vault,eating,t;
};

bool operator <(citizen const &c1,citizen const &c2)
{
    if(c1.t==c2.t)
    {
        return c1.cobol>c2.cobol;
    }
    else
    {
        return c1.t>c2.t;
    }
}

vector <citizen> v;
int main()
{
    int n,i,ans=-1,delayTime=0;
    cin>>n;
    citizen c;
    for(i=0;i<n;i++)
    {
        cin>>c.cobol>>c.vault>>c.eating;
        c.t=c.vault+c.eating;
        v.push_back(c);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        //cout<<v[i].cobol<<" "<<v[i].vault<<" "<<v[i].eating<<"\n";
        ans=max(ans,delayTime+v[i].cobol+v[i].t);
        delayTime+=v[i].cobol;
    }
    cout<<ans<<"\n";
    return 0;
}
