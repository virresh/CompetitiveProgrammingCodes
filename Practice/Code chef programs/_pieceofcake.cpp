#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char s[51];
        int a[27]={0},total=0;
        scanf("%s",s);
        bool x=false;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]>='a' && s[i]<='z'){a[s[i]-'a']++;}
            total++;
        }
        for(int i=0;i<=26;i++)
        {
            if(a[i]==total-a[i]){x=true; break;}
        }
        if(x){cout<<"YES\n";}
        else{cout<<"NO\n";}
    }
}
