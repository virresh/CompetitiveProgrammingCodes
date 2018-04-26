#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

int main()
{
    freopen("taktakin.txt","r",stdin);
    freopen("taktakout.txt","w",stdout);
    ll n,cycles=0;
    cin>>n;
    while(n%11 != 1)
    {
        n*=2;
        cycles++;
    }
    cout<<cycles <<" "<<n;
    return 0;
}
