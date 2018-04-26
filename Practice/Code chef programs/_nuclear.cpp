#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,n,k;
    cin>>a>>n>>k;
    while(k--)
    {
        cout<<a%(n+1)<<" ";
        a/=(n+1);
    }
    return 0;
}
