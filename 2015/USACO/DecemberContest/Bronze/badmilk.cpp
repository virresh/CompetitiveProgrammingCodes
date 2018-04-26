#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[55][55];  // rows-> persons
                // cols -> milks
/* REDUNDANT FILE ---- WILL NOT COMPILE */
struct tester{
    int time,milk,pno;
};
vector <tester> adjlist[1003];
int main()
{
    ofstream fout ("badmilk.out");
    ifstream fin ("badmilk.in");
    int n,m,d,s,p,m,t,I,J,colsum;
    set <int> badmilk;
    set<int>::iterator it;
    pait<bool,int> gotsick[55],temp;
    bool flag;
    cin>>n>>m>>d>>s;
    memset(a,0,sizeof(a));
    for(I=0;I<d;I++)
    {
        flag=false;
        cin>>p>>m>>t;
        a[p][m]=1;
        for(J=0;J<adjlist[p].size();J++)
        {
            if(adjlist[p].at(J).milk==m)
            {
                adjlist[p].at(J).time= min(adjlist[p].at(J).time,t);
                flag =true; break;
            }
        }
        if(flag==false)
        {
            temp.pno=p;
            temp.milk=m;
            temp.time=t;
            adjlist[p].push_back(temp);
        }
    }
    for(J=1;J<=n;J++)
    {
        colsum=0;
        for(I=1;I<=m;I++)
        {
            if(a[I][J]==1){colsum++;}
        }
        a[I][J]=colsum;
    }
    for(I=0;I<s;I++)
    {
        cin>>p>>t;
        gotsick[p].first=true;
        gotsick[p].second=t;
    }
    int x=0;
    for(I=1;x<s;I++)
    {
        if(gotsick[I].first==true)
        {

        }
    }
    return 0;
}
