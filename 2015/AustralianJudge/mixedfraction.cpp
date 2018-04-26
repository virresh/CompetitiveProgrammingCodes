#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("mixin.txt","r",stdin);
    freopen("mixout.txt","w",stdout);
    long n,d;
    cin>>n>>d;
    long a=0,n2=n,d2=d;
    while(n2>=d2)
    {
        n2-=d2; a++;
    }
    cout<<a<<" "; if(n2!=0){cout<<n2<<"/"<<d2;}
    return 0;
}
