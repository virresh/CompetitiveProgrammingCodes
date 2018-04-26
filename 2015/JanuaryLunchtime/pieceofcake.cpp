#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    int t,n=0,l=0,fl=0,j=0;
    char a[50],ch;
    cin>>t;
    while(t)
    {
        cin>>a;
        n=strlen(a);
        l=0,fl=0;
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if(a[i]!=a[i+1])
            {
                if(n-i+l-1==i-l+1){fl=1; break;}
                l=i+1;
            }
        }
        if(fl==1){cout<<"YES\n";}
        else if(fl==0) {cout<<"NO\n";}
        t--;
    }
    return 0;
}
