#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int i,a,b,c,ans=1080;
    //while(scanf("%d %d %d %d ",&i,&a,&b,&c) && (a||b||c||i))
    while(cin>>i>>a>>b>>c)
    {
        if(a==0 && b==0 && c==0 && i==0){break;}
        ans=1080;
        if(i-a < 0){ans+=(i-a+40)*9;}
        else {ans+= (i-a)*9;}
        //cout<<ans<<"\n";
        if(b-a< 0){ans+= (b-a+40)*9;}
        else {ans+= (b-a)*9; }
        //cout<<ans<<"\n";
        if(b-c< 0){ans+=(b-c+40)*9;}
        else {ans+= (b-c)*9;}
        //printf("%d\n",ans);
        cout<<ans<<"\n";
    }
    return 0;
}
