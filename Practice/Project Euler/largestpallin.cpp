#include<iostream>
using namespace std;

bool ispallin(long n)
{
    long rev=0,i,tem=n;
    while(n>0)
    {
        rev=rev*10+n%10;
        n/=10;
    }
    return rev==tem;
}
int main()
{
    long i,j,m=0;
    for(i=999;i>100;i--)
    {
        for(j=999;j>100;j--)
        {
            if(ispallin(i*j))
                m=max(i*j,m);
        }
    }
    cout<<m<<"\n";
    return 0;
}
