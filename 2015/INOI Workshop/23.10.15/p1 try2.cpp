#include <bits/stdc++.h>
using namespace std;
#define asize 10000000
typedef long long ll;
char primestore[asize];
/*void update(ll &n)
{
    n++;
    if(n<asize){while(primestore[n]!=1 && n<asize){n++;}}
}
void generatePrime()
{
    ll i,j;
    primestore[1]=0;
    for(i=2;i<asize;i++)
    {
        if(primestore[i]==-1)
        {
            primestore[i]=1;
            for(j=2*i; j<asize; j+=i){primestore[j]=0;}
        }
        else
        {
            while(primestore[i]==1){i++;}
        }
    }
}*/
bool isPrime(ll n)
{
    if(n<asize && primestore[n]!=-1)
        {
            if(primestore[n]==0)
            {return false;}
            else if(primestore[n]==1)
            {return true;}
        }
    if(n%2==0){return false;}
    for(ll i=3;i<=n/i;i+=2)
    {
        if(n%i==0){return false;}
    }
    if(n<asize){primestore[n]=1;}
    return true;
}
ll lpn(ll n)
{
    ll i;
    if(isPrime(n)){return n;}
    else if(n%2==0){i=n-1;}
    else{i=n-2;}
    for(; i >=2; i-=2)
    {
        if(isPrime(i) && n%i==0){return i;}
    }

}
int main()
{
    memset(primestore,-1,sizeof(primestore));
    //generatePrime();
    primestore[0]=0; primestore[1]=0; primestore[2]=1;
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<lpn(n)<<"\n";
    }
    return 0;
}
