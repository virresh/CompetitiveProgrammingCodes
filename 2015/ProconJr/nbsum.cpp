#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%2==0)
        {
            cout<<n*n/4 - n*(n+2)/4<<"\n";
        }
        else
        {
            cout<<(n+1)*(n+1)/4- (n-1)*(n+1)/4 <<"\n" ;
        }
    }
    return 0;
}
