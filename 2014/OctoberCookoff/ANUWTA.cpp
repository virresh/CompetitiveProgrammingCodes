
#include <iostream>
using namespace std;
 
int main()
{
    unsigned long int t;
    cin>>t;
    while(t--)
    {
        unsigned long long int n,d=0;
        cin>>n;
        d=(n*(n+1))/2 + n;
        if(n==0){cout<<1<<"\n";}
        else {cout<<d<<"\n";}
    }
    return 0;
}
