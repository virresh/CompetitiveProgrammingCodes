#include <iostream>
using namespace std;

int main()
{
    int t;
    unsigned long long n,k,i,ans=0;
    cin>>t;
    while(t--)
    {
        ans =0;
        cin>>n>>k;
        for(i=1; i<=k; i++)
        {
            if(n%i>ans)
            {
                ans = n%i;
                //cout<<i<<"\n";
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
