#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main()
{
    int t,a[52];
    scanf("%d \n",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        char c[201];
        //scanf("%s ",c);
        cin>>c;
        int ans=0,i=0;
        //for(i=0;c[i]!='\0';i++)
        while(c[i]!='\0')
        {
            //cin.get(c[i]);
            //cout<<c[i]<<" ";
            if(c[i]>='a'&& c[i]<='z')
            {
                a[c[i]-'a']++;
            }
            else if(c[i]>='A' && c[i]<='Z')
            {
                a[c[i]-'A'+26]++;
            }
            i++;
        }
        for(i=0;i<52;i++)
        {
            ans+= ceil(a[i]/2.0);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
