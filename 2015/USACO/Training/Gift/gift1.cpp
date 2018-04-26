/*
ID: virresh1
PROG: gift1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct p
{
    char name[16];
    int bal,change;
};

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int n,i,j,nof,l=0,m;
    fin>>n;
    p a[11];
    char s[16],x[16];
    for(i=0;i<n;i++)
    {
        fin>>a[i].name;
        a[i].bal=0;
        a[i].change=0;
    }
    for(i=0;i<n;i++)
    {
        fin>>s;
        for(j=0;j<n;j++)
        {
            if(strcmp(s,a[j].name)==0){break;}
        }
        fin>>a[j].bal;
        fin>>nof;
        if(nof!=0)
        l=(a[j].bal)/(nof);
        else{l=0;}
        a[j].change= a[j].change - nof * l;
        for(m=0;m<nof;m++)
        {
            fin>>s;
            for(j=0;j<n;j++)
            {
                if(strcmp(s,a[j].name)==0){ a[j].change+=l; break;}
            }
        }
    }
    for(i=0;i<n;i++)
    {
        fout<<a[i].name<<" "<<a[i].change<<"\n";
    }
    return 0;
}
