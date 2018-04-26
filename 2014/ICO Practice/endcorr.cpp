#include <iostream>
#include <cstdio>
using namespace std;
long long int a[110000],key,temp;
int main()
{
    long long int n,m,i=0,j=0,ap=0;
    scanf("%lld %lld\n",&m,&n);
    for(i=1;i<=(m+n);i++)
    {
        j=i-1;
        scanf("%lld\n",&key);
        if(key!=-1)
        {
            while(j>ap&&key>a[j-1])
            {
                a[j]=a[j-1];
                j--;
            }
            a[j]=key;
        }
        else
        {
            printf("%lld\n",a[ap]); ap++;
        }
    }
    return 0;
}
