#include <iostream>
using namespace std;
typedef long long ll;
ll &mini(ll &a,ll &b){return a>b?b:a;}
ll &maxi(ll &a,ll &b){return a>b?a:b;}
int main()
{
    ll m,n,*j,*k,result=0;
    cin>>n>>m;
    k=&mini(m,n);
    j=&maxi(n,m);
    while(*k>0 && *j>0)
    {
        k=&mini(m,n);
        j=&maxi(m,n);
        (*k)= (*k)-1;
        (*j)= (*j)-2;
        if(*j>=0&& *k>=0){result+=1;}
    }
    cout<<result;
    return 0;
}
