/*
ID: virresh1
PROG: friday
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ans[7]={0}; //0-> Saturday 1-> Sunday 2-> Monday ....
bool isLeap(ll n)
{
    if(n%100==0){n/=100;}
    if(n%4==0)
    {
        return true;
    }
    return false;
}
int daysIn(int mnth,bool leap=false)// month no... 1-Jan 2-Feb ....
{
    switch (mnth)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: return 31;
    case 4:
    case 6:
    case 9:
    case 11: return 30;
    case 2: if(leap){return 29;}
            return 28;
    default : return 0;
    }
}
int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    ll n,i,j,k;
    int aindex=2;
    fin>>n;
    ll start_yr=1900,end_yr=1900+n-1;
    for(i=start_yr;i<=end_yr; i++)
    {
        bool x=isLeap(i);
        for(j=1;j<=12;j++)
        {
            for(k=1;k<=daysIn(j,x);k++)
            {
                if(k==13)
                {
                    ans[aindex]++;
                }
                aindex=(aindex+1)%7;
            }
        }
    }
    for(i=0;i<7;i++){fout<<ans[i];if(i!=6){fout<<" ";} else {fout<<"\n";}}
    return 0;
}
