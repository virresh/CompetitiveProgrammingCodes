/*
ID: virresh1
PROG: beads
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    char necklace[400],type='w';
    ll n,ans=0,i=0,j=0,tmp;
    fin>>n;
    fin>>necklace;
    for(i=0; i<n;i++)
    {
        tmp=0;
        j=i+2; if(j>n-1){j=0;}
        type= ((i+1)<(n))?necklace[i+1]:necklace[0];
        for(;j!=(i+1)%n;)
        {
            //cout<<i<<" "<<j<<"\n";
            if(type=='w'){type=necklace[j];}
            if(type==necklace[j] || necklace[j]=='w')
            {
                j=j+1; tmp++;
                if(j>=n){j=0;}
            }
            else{break;}
        }
        if(j==i+1){ ans= n-2; break;}
        j=i-1;
        if(j<0){j=n-1;}
        type=necklace[i];
        for(;j!=i;)
        {
            //cout<<i<<" "<<j<<"\n";
            if(type=='w'){type=necklace[j];}
            if(type==necklace[j] || necklace[j]=='w')
            {
                j=(j-1); tmp++;
                if(j<0){j=n-1;}
            }
            else{break;}
        }
        //fout<<tmp<<" ";
        if(tmp>ans){ans=tmp;}
    }
    fout<<ans+2<<"\n";
    return 0;
}
