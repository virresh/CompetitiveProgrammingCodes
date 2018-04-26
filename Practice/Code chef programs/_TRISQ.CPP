#include <iostream>
using namespace std;
long ans[10002]={0};
void precompute()
{
    long b=3;
    ans[0]=0;
    ans[1]=0;
    ans[2]=0;
    for(;b<=10001;b++)
    {
        ans[b]=(b-2)/2 + ans[b-2];
    }
}
int main()
{
    long t,b;
    cin>>t;
    precompute();
    while(t--)
    {
        cin>>b;
        cout<<ans[b]<<"\n";
    }
    return 0;
}
