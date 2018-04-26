#include <iostream>
#include <math.h>
#define ll long long int
using namespace std;
int main()
{
    double s1,s2,x,y;
    ll n,m,a,z,t1,t2;
    cin>>n>>m>>a;
    x=n; x/=a; y=m; y/=a;
    t1=x; s1=t1;
    t2=y;s2=t2;
    t1=ceil(x);
    t2=ceil(y);
    z=t1*t2;
    cout<<z<<"\n";
    return 0;
}
