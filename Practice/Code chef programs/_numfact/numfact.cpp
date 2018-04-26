#include <iostream>
typedef long long ll;
#define siz 100000
#define siz2 1000000
using namespace std;
int pr[siz]={0};
bool isPrime(ll a)
{
    if(a<siz)
    {
        if(pr[a]==1){return true;}
        else if(pr[a]==2){return false;}
    }
    if(a%2==0 && a!=2){if(a<siz){pr[a]=2;} return false;}
    for(ll i=3;i<=a/i;i+=2)
    {
        if(a%i==0)
        {
            if(a<siz){pr[a]=2;}
            return false;
        }
    }
    if(a<siz){pr[a]=1;}
    return true;
}
ll sdiv(ll a)
{
    if(a==1||a==0){return 1;}
    else if(a%2==0){return 2;}
    for(ll i=3;i<=a/i;i+=2)
    {
        if(a%i==0)
        {
            return i;
        }
    }
    return a;
}
void factorize(ll n,char *a)
{
    ll j;
    if(isPrime(n)){a[n]++; return;}
    while(n>1)
    {
        j=sdiv(n);
        a[j]++;
        n=n/j;
    }
}
void calc(ll &n,char *a)
{
    n=1;
    for(ll i=2;i<siz2;i++)
    {
        n*=(a[i]+1);
    }
}
int main()
{
    pr[0]=2; pr[1]=2; pr[2]=1;
    int t,n;
    ll ans=1,i;
    cin>>t;
    while(t--)
    {
        char a[siz2]={0};
        cin>>n;
        while(n--)
        {
            cin>>i;
            factorize(i,a);
        }
        calc(ans,a);
        cout<<ans<<"\n";
    }
    return 0;
}
