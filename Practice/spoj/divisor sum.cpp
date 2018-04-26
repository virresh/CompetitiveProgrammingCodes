#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <pair<ll,ll> >primes;

bool isprime(ll n)
{
    ll i;
    if(n%2==0){return 0;}
    for(i=3;i<=n/i;i+=2)
    {
        if(n%i==0){return false;}
    }
    return true;
}

void precompute()
{
    ll i; pair<ll,ll> p;
    p.second=0;
    p.first=2;
    primes.push_back(p);
    for(i=3;i<1000;i+=2)
    {
        if(isprime(i)){
            p.first=i;
            primes.push_back(p);
        }
    }
}
int main()
{
    ll t,n,i,sum=0;
    precompute();
    scanf("%lld",&t);
    while(t--)
    {
        sum=0;
        for(i=0;i<primes.size(); i++){primes[i].second=0;}
        scanf("%lld",&n);
        for(i=0;i<primes.size(); i++)
        {
            if(n%i==0)
            {
                while(n%i==0){n/=i; primes[i].second++;}
            }
        }
    }
     
    return 0;   
}
