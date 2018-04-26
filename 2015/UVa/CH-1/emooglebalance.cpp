#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 10005

int main()
{
    int t,k=1,i,x,n2,n1;
    while(cin>>t)
    {
        n2=0;
        n1=0;
        if(t==0){break;}
        for(i=0;i<t;i++)
        {
            cin>>x;
            if(x==0){n2++;}
            else {n1++;}
        }
        cout<<"Case "<<k<<": "<<n1-n2<<"\n";
        k++;
    }
    return 0;
}
