#include <iostream>
#include <cstdio>
using namespace std;
long long int a[2][500],len=0,i=0,j=0,dm[4][500],c=0,dp=0,lmax=0;
bool ispali(long long int s,long long int e)
{
    char flag=1;
    long long int i;
    for(i=s;i<=e/2;i++)
    {
        if(a[0][i]!=a[0][e-i]){flag=0; break;}
    }
    if(flag==1){return true;}
    else {return false;}
}
int main()
{
    freopen("4.in","r",stdin);
    cout<<"Enter length :\n";
    cin>>len;
    long long int tot=len-1;
    for(i=0;i<len;i++)
    {
        cin>>a[0][i];
    }
    for(i=0;i<len;i++)
    {
        for(j=len-1;j>i;j--)
        {
            if(a[0][i]==a[0][j])
                {
                    if(ispali(i,j)==1)
                    {
                        dm[0][dp]=i; dm[1][dp]=j;
                        dp++;
                        if(j-i==len-1){break;}
                        i=j+1;
                    }
                }
        }
    }
    while(tot>0)
    {
        lmax=0;
        for(i=0;i<dp;i++)
        {
            if((dm[2][i]==1)){break;}
            if(dm[2][i]>lmax)
                {
                    lmax=dm[2][i];
                }
        }
        if(lmax==0){lmax=1;}
        c++;
        tot-=lmax;
    }
    cout<<c<<"\n";
    return 0;
}
