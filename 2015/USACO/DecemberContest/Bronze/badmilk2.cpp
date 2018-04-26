#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[60][60];  // rows-> persons
                // cols -> milks
pair<bool,int> gotsick[60];
set<int> badmilk;
set<int>::iterator it;
int main()
{
    ofstream fout ("badmilk.out");
    ifstream fin ("badmilk.in");
    int n,m,d,s,p,t,mil,I,J;
    fin>>n>>m>>d>>s;
    memset(a,0,sizeof(a));
    for(I=0;I<=s;I++){gotsick[I].first=false;}
    for(I=0;I<d;I++)
    {
        fin>>p>>mil>>t;
        if(a[p][mil]!=0)
        {
            a[p][mil]=min(a[p][mil],t);
        }
        else
        {
            a[p][mil]=t;
        }
    }
    for(I=0;I<s;I++)
    {
        fin>>p>>t;
        gotsick[p].first=true;
        gotsick[p].second=t;
    }
    int tempvar=0;
    for(I=1;I<=m;I++)
    {
        tempvar=0;
        for(J=0;J<=n;J++)
        {
            if(a[J][I]!=0){tempvar++;}
        }
        a[J][I]=tempvar;
    }
    for(I=1;I<=n;I++)
    {
        if(gotsick[I].first==true)
        {
            for(J=1;J<=m;J++)
            {
                if(a[I][J]!=0)
                {
                    if(a[I][J]<=gotsick[I].second){badmilk.insert(J);}
                }
                else
                {
                    if(badmilk.find(J)!=badmilk.end())
                    {
                        badmilk.erase(J);
                    }
                }
            }
        }
    }
    int ans=0;
    for(it=badmilk.begin();it!=badmilk.end();it++)
    {
        if(a[n+1][*it]>ans){ans=a[n+1][*it]; }
    }
    fout<<ans<<"\n";
    cerr<<ans<<"\n";
    return 0;
}
