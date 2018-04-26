#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[1002];
int main()
{
    int t,n,i,res;
    cin>>t;
    while(t--)
    {
        res=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            res+=a[i]/3;
        }
        cout<<res<<"\n";
    }
    return 0;
}
