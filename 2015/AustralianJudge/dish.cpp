#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

int main()
{
    freopen("dishin.txt","r",stdin);
    freopen("dishout.txt","w",stdout);
    ll n,i=0,tnum,mi=1000000,ma=-1,sum=0,avg;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>tnum;
        sum+=tnum;
        if(tnum<mi){mi=tnum;}
        if(tnum>ma){ma=tnum;}
    }
    avg=sum/n;
    cout<<mi<<" "<<ma<<" "<<avg;
    return 0;
}
