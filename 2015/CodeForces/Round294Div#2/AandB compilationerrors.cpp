#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n=0,s1=0,s2=0,s3=0,i=0,a=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        s1+=a;
    }
    for(i=0;i<n-1;i++)
    {
        cin>>a;
        s2+=a;
    }
    for(int i=0;i<n-2;i++)
    {
        cin>>a;
        s3+=a;
    }
    cout<<s1-s2<<"\n"<<s2-s3;
}
