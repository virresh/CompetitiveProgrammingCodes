#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char s[53];
    int n,ans=0;
    cin>>n;
    scanf("%s",s);
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1]){ans++;}
        }
    cout<<ans<<"\n";
    return 0;
}
