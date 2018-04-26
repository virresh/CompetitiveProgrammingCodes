#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    char a[105],b[]="hello";
    scanf("%s",a);
    int i,j=0;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]==b[j]){j++;}
    }
    cout<<(j==5?"YES":"NO");

    return 0;
}
