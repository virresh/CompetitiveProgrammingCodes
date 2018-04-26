#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1005
#define inf 10000000
/*
ID: virresh1
PROG: skidesign
LANG: C++
*/

int elevation[sz];
int cost[]={0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676,729,784,841,900,961,1024,1089,1156,1225,1296,1369,1444,1521,1600,1681,1764,1849,1936,2025,2116,2209,2304,2401,2500,2601,2704,2809,2916,3025,3136,3249,3364,3481,3600,3721,3844,3969,4096,4225,4356,4489,4624,4761,4900,5041,5184,5329,5476,5625,5776,5929,6084,6241,6400,6561,6724,6889,7056,7225,7396,7569,7744,7921,8100,8281,8464,8649,8836,9025,9216,9409,9604,9801,10000};
int main()
{
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    int n,i,low,j,up,tcost=inf;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>elevation[i];
    }
    for(low=0;low<=83;low++)
    {
        int lcost=0;
        up=low+17;
        for(i=1;i<=n;i++)
        {
            if(elevation[i]<low)
            {
                lcost += cost[low-elevation[i]];
            }
            else if(elevation[i]>up)
            {
                lcost += cost[elevation[i]-up];
            }
        }
        tcost=min(lcost,tcost);
    }
    fout<<tcost<<"\n";
    return 0;
}
