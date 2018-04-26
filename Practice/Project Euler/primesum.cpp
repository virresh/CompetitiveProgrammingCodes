#include <iostream>
typedef long long ll;
#define ss 1000000
#define len 2000000
using namespace std;
int prime[ss]={0};
bool isPrime(ll n)
{
    if(n<ss)
        {
            if(prime[n]==2)
            {return false;}
            else if(prime[n]==1)
            {return true;}
        }
    for(ll i=2;i<=n/i;i++)
    {
        if(n%i==0){if(n<ss){prime[n]=false;}  return false;}
    }
    ll x=2;
    while(n*x < ss)
    {
        prime[n*x]=false;
        x++;
    }
    return true;
}
int main()
{
    prime[1]=2; prime[2]=1;
    ll sum=0;
    for( ll j=2;j<len; j++)
    {
        if(isPrime(j)){sum+=j;}
    }
    cout<<sum;
    return 0;
}
