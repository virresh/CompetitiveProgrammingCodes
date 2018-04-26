#include <bits/stdc++.h>
#define ll long long
#define sz 1000002
using namespace std;
char a[sz];
int main()
{
    ll t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++){cin>>a[i];}
        if(next_permutation(a,a+n))
        {
            for(i=0;i<n;i++)
            {
                cout<<a[i];
            }
            cout<<"\n";
        }
        else cout<<"-1\n";
    }
    return 0;
}
