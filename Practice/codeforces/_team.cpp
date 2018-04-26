#include <iostream>
using namespace std;

int main()
{
    int n,t,r,ans=0;
    cin>>n;
    while(n--)
    {
        r=0;
        for(int i=0;i<3;i++)
        {
            cin>>t;
            r+=t;
        }
        if(r>=2){ans++;}
    }
    cout<<ans<<"\n";
    return 0;
}
