#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 10
typedef char arr;
arr a[sz][sz],b[sz][sz],c[sz][sz],d[sz][sz];
/*
ID: virresh1
PROG: transform
LANG: C++
*/
bool compare(arr a[sz][sz],arr b[sz][sz],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=c[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void rotate_90(arr a[sz][sz],arr b[sz][sz],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[n-1-j][i];
        }
    }
}

void reflect(arr a[sz][sz],arr b[sz][sz],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[i][n-1-j];
        }
    }
}

int check(int n)
{
    int flag=0;
    if(compare(a,c,n)){flag=1;}
        rotate_90(a,b,n);
    if(compare(b,c,n)){return 1;}
        rotate_90(b,d,n);
    if(compare(d,c,n)){return 2;}
        rotate_90(d,b,n);
    if(compare(b,c,n)){return 3;}
        reflect(a,d,n);
    if(compare(d,c,n)){return 4;}
        rotate_90(d,b,n);
    if(compare(b,c,n)){return 5;}
        rotate_90(b,d,n);
    if(compare(d,c,n)){return 5;}
        rotate_90(d,b,n);
    if(compare(b,c,n)){return 5;}
    if(flag==1){return 6;}
    return 7;
}
int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int n,i,j;
    fin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fin>>a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fin>>c[i][j];
        }
    }
    fout<<check(n)<<"\n";
    return 0;
}
