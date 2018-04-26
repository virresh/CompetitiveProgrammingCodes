#include<iostream>
#include <cstdio>
using namespace std;

bool prime(unsigned long int i)
{
    unsigned long long int j=1,k;
    while (j*j<=i)
    {j++;}
    if((i!=2)&&(i%2==0)){return false;}
    for(k=3;k<=j;k+=2)
    {
            if(i%k==0){return false;}
    }
    if(i==1){return false;}
    return true;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    unsigned long long int t,n,m;
    scanf("%llu",&t);
    while(t--)
    {
            scanf("%llu %llu",&n,&m);
            for(unsigned long long int j=n;j<=m;j++)
            {
                    if(prime(j)){printf("%llu\n",j);}
            }
            printf("\n");
    }
}
