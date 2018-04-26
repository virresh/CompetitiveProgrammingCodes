#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
ID: virresh1
PROG: wormhole
LANG: C++
*/

struct point{
    ll x,y;
    void show()
    {
        cout<<" X : "<<x<<"  Y : "<<y<<"\n";
    }
};
    bool operator < (const point &a,const point &b)
    {
        if(a.y!=b.y){return a.y<b.y;}
        else
        {
            return a.x<b.x;
        }
    }
vector <point> v;
int main()
{
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");

    int n,i;
    point a;
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>a.x>>a.y;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    ll curr=-1,ans=0;
    for(int i=0;i<n;i++)
    {
        if(v[i].y==curr && curr !=-1)
        {
            while(v[i].y==curr)
            {
                i++;
                ans++;
            }
            i--;
        }
        else
        {
            curr=v[i].y;
        }
    }
    fout<<ans<<"\n";
    return 0;
}
