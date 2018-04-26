#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long int num,i,m,f,sum=0,tem;
    while(t--)
    {
        cin>>num>>m;
        tem=m*(m-1)/2;
        f=num/m;
        i=(num%m);
        sum=(f*tem)+(i*(i+1)/2);
        cout<<sum<<"\n";
    }
    return 0;
}
