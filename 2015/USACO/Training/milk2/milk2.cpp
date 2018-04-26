#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 5005
/*
ID: virresh1
PROG: milk2
LANG: C++
*/
struct mman{
    int stime,etime;
};

bool comp(mman a,mman b)
{
    if(a.stime!=b.stime)
    {
        return (a.stime<b.stime);
    }
    else
    {
        return (a.etime<b.etime);
    }
}
bool comp2(mman a,mman b)
{
    return (a.etime<b.stime);
}
//int start[sz];
//int end[sz];
mman a[sz];
int main()
{
    int n,i,lwans=0,lfans=0,tstart,tend,j,fstart,fend;
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>a[i].stime>>a[i].etime;
    }
    sort(a,a+n,comp);
    //sort(end,end+n);
    for(i=0;i<n;i++)
    {
        tstart=a[i].stime;
        tend=a[i].etime;
        lwans=max(tend-tstart, lwans);
        for(j=i+1;j<n;j++)
        {
            if(a[i].etime>=a[j].stime)
            {
                if(a[j].etime-a[i].stime > lwans)
                {
                    lwans=max(a[j].etime-a[i].stime,lwans);
                }
            }
            else break;
        }
    }
    sort(a,a+n,comp2);
    lfans=0;
    for(i=0;i<n;i++)
    {
        tstart=a[i].stime;
        tend=a[i].etime;
        for(j=i+1;j<n;j++)
        {
            if(a[i].etime<a[j].stime)
            {
                if(a[j].stime-a[i].etime > lfans)
                {
                    lfans=a[j].stime-a[i].etime;
                }
            }
            if(a[i].etime>=a[j].etime){}
            else {break;}
        }
    }
    fout<<lwans<<" "<<lfans<<"\n";
    return 0;
}
