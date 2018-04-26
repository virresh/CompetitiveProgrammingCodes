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

vector <mman> a,arr;
int main()
{
    int n,i,j=1,ans1,ans2;
    mman p;
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>p.stime>>p.etime;
        a.push_back(p);
    }
    sort(a.begin(),a.end(),comp);
    arr.push_back(a[0]);
    for(i=1;i<n;i++) // remove overlaps
    {
        if(a[i].stime <= arr[j-1].etime)
        {
            arr[j-1].stime=min(a[i].stime,arr[j-1].stime);
            arr[j-1].etime=max(a[i].etime,arr[j-1].etime);
        }
        else
        {
            j++;
            arr.push_back(a[i]);
        }
    }
    for(i=0;i<j;i++)
    {
        //cout<<arr[i].stime<<" "<<arr[i].etime<<"\n";
        if(i==0)
        {
            ans1=arr[i].etime-arr[i].stime;
            ans2=0;
        }
        else
        {
            if(arr[i].etime-arr[i].stime>ans1){ans1=arr[i].etime-arr[i].stime;}
            if(arr[i].stime-arr[i-1].etime>ans2){ans2=arr[i].stime-arr[i-1].etime;}
        }
    }
    fout<<ans1<<" "<<ans2<<"\n";
    return 0;
}

