#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int t,x;
    cin>>t;
    while(t--)
    {
        cin>>x;
        cout<<abs(((315*x +36962)/10))%10<<"\n";
    }
    return 0;
}
