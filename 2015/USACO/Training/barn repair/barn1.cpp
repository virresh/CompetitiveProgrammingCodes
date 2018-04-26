#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
ID: virresh1
PROG: barn1
LANG: C++
*/

struct diff{
    int start,ending,num;
    void print()
    {
        cerr<<start<<" "<<ending<<" "<<num<<"\n";
    }
};
bool operator <(const diff &x,const diff &y)
{
    return (x.num>y.num )? true:false;
}
bool comp(diff d1,diff d2){return d1.num>d2.num ;}
int arr[205];
diff d[205];

int main()
{
    diff gmax={0,0,0};
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int m,s,c,i,j,sum=0,tend,tstart,x=0,k=0;
    fin>>m>>s>>c;
    for(i=0;i<c;i++)
    {
        fin>>arr[i];
    }
    sort(arr,arr+c);
    for(i=0;i<c;i++)
    {
        cerr<<arr[i]<<" ";
    }
    cerr<<"\n";
    for(i=0;i<=c-2;i++)
    {
        if(arr[i+1]-arr[i]>1)
        {
            d[k].start=arr[i]+1;
            d[k].ending=arr[i+1]-1;
            d[k].num= d[k].ending-d[k].start+1;
            k++;
        }
    }
    sort(d,d+k);
    /*for(i=0;i<k;i++)
    {
        d[i].print();
    }*/
    sum=arr[c-1]-arr[0]+1;
    for(i=0;i<m-1 && i<k;i++)
    {
        sum=sum-d[i].num;
        d[i].print();
    }
    fout<<sum<<"\n";
    return 0;
}
