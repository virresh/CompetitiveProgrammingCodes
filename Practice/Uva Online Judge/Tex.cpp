#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    char s[1000];
    int i,fl=0;
    while(scanf("%[^\n]%*c",s)!=EOF)
    {
        for(i=0; s[i]!='\0'; i++)
        {
            if(s[i]=='\"' && fl==0)
            {
                printf("%c%c",'`','`');
                fl=1;
            }
            else if(s[i]=='\"' && fl==1)
            {
                printf("%c%c",'\'','\'');
                fl=0;
            }
            else
            {
                printf("%c",s[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
