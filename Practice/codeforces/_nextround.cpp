#include <iostream>
using namespace std;

int main()
{
    int n,k,m,ans=0;
    cin>>n>>k;
    int a[52];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==k-1){m=a[i];}
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>=m && a[i]>0){ans++;}
    }
    cout<<ans<<"\n";
    return 0;
}
