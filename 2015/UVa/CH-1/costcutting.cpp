#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int t,a[3];
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        for(int i=0;i<3;i++)
        {
            cin>>a[i];
        }
        sort(a,a+3);
        cout<<"Case "<<j<<": "<<a[1]<<"\n";
    }
    return 0;
}
