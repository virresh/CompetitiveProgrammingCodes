#include <iostream>
#include <cstdio>
using namespace std;
#define asize 10000000
typedef long long ll;
ll primestore[asize]={0};
bool isprime(ll num)
{
    if(num<asize)
    {
        if(primestore[num]==1){return true;}
        else if(primestore[num]==2) {return false;}
    }
         ll i=3,l=2;
         if(num==1){return false;}
         else if(num==2){return true;}
         else if((num%2==0)&&(num>=2)){return false;}
         for(i=3;i<=num/i;i+=2)
         {
                              if(num%i==0){return false;}
         }
         return true;
}
void printprime(ll m,ll n)
{
    for(ll i=m;i<=n;i++)
    {
        if(isprime(i))
        {
                printf("%d \n",i);
                if(i<asize){primestore[i]=1;}
        }
        else
        {
            if(i<asize) {primestore[i]=2;}
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll m,n;
        cin>>m>>n;
        //scanf("%lld %lld\n",&m,&n);
        printprime(m,n);
        cout<<"\n";
    }
    return 0;
}
