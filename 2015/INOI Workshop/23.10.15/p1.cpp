#include <bits/stdc++.h>
using namespace std;
#define asize 100000
typedef long long ll;
char a[asize];
void generateprime()
{
    ll i=2,j;
    for(i=2;i<asize;i++)
    {
        if(a[i]==-1)
        {
            a[i]=1;  j=2*i;
            for(;j<asize;j++)
            {
                a[j]=0;
            }
        }
        if(a[i]==0){while(a[i]!=-1 && i<asize){i++;}}
    }
}

ll lprime(ll num)
{
    ll i;
    for(i=2;i<=num/i; i++)
    {
        if(num%i==0)
        {
            if(num/i==1){return num;}
            else
            {
                while(num%i==0){num/=i; if(num/i==1){return num;}}
            }
        }
    }
    return num;
}

int main()
{
    memset(a,-1,sizeof(a));
    ios::sync_with_stdio(false);
    generateprime();
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<lprime(n)<<"\n";
    }
    return 0;
}
