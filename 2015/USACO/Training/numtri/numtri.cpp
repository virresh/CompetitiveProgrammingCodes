#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000
/*
ID: virresh1
PROG: numtri
LANG: C++
*/
int ans[sz+1][sz+1],arr[sz+1][sz+1];

int main()
{
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int n;
    fin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            fin>>arr[i][j];
        }
    }
    ans[0][0]=arr[0][0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j!=0)
                ans[i][j]=arr[i][j]+max(ans[i-1][j],ans[i-1][j-1]);
            else
                ans[i][j]=arr[i][j]+ans[i-1][j];
        }
    }
    int res=ans[n-1][0];
    for(int i=1;i<n;i++)
    {
        res=max(res,ans[n-1][i]);
    }
    fout<<res<<"\n";
    return 0;
}
