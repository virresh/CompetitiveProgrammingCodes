#include <bits/stdc++.h>
using namespace std;
char a[2002];

int main()
{
    int t,i,ctr=0,res=0;
    stack <char> s;
    cin>>t;
    while(t--)
    {
        ctr=0; res=0;
        scanf("%s",a);
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='{')
            {
                s.push(a[i]);
            }
            else if(a[i]=='}')
            {
                if(s.empty()){res++; s.push('{');}
                else{s.pop();}
            }
        }
        while(!s.empty())
        {
            s.pop(); ctr++;
        }
        res+=ctr/2;
        cout<<res<<"\n";
    }
    return 0;
}
