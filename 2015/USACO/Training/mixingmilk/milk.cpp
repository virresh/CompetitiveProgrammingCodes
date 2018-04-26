#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
ID: virresh1
PROG: milk
LANG: C++
*/
int main()
{
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int n,m,i,sum=0,k=0,qty=0;
    fin>>n>>m;
    vector <pair<int,int> > v;
    pair<int,int> p;
    for(i=0;i<m;i++)
    {
        fin>>p.first>>p.second;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    while(qty!=n && k!=v.size())
    {
        if(v[k].second <= n-qty)
        {
            qty+=v[k].second;
            sum+= v[k].first*v[k].second;
        }
        else
        {
            sum+= v[k].first* (n-qty);
            qty=n;
        }
        k++;
    }
    fout<<sum<<"\n";
    return 0;
}
