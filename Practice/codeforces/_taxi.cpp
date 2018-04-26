#include<iostream>
using namespace std;
int fix(int a,int b,int c,int d,int ans)
{
    ans=d;
    while(a>0 && c>0)
    {
        a--; c--; ans++;
    }
    while(b>1)
    {
        b-=2; ans++;
    }
    if(a>0 && b>0)
    {
        if(a>=2)
            {a-=2; b--; ans++;}
        else
            {a--; b--; ans++;}
    }
    while(c>0)
    {
        c-=1; ans++;
    }
    if(b>0){b--; ans++;}
    while(a>0)
    {
        a-=4; ans++;
    }
    return ans;
}
int main()
{
    int s,a[4]={0},i;
    long n,ans=0;
    cin>>n;
    while(n--)
    {
        cin>>s;
        a[s-1]++;
    }
    cout<<fix(a[0],a[1],a[2],a[3],ans);
    return 0;
}
