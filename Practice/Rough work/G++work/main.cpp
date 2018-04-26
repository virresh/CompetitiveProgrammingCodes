#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n,k,flag=0,a;
    cin>>n;
    cin>>k;
    while(n--)
    {
        scanf("%lld",&a);
        if(a%k==0)
        {
            flag+=1;
        }
    }
    cout<<flag;
    return 0;
}

