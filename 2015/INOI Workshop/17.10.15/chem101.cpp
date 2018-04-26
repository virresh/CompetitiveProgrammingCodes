#include <bits/stdc++.h>
using namespace std;
char s[505];
int mass(char c)
{
    switch (c)
    {
        case 'C' : return 12;
        case 'H' : return 1;
        case 'O' : return 16;
        default  : return 0;
    }
}
int main()
{
    stack <int> stc;
    scanf("%s",s);
    int i,sum=0;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='(')
        {
            stc.push(-1);
        }
        else if(s[i]==')')
        {
            int tsum=0;
            while(stc.top()!=-1)
            {
                tsum+=stc.top();
                stc.pop();
            }
            stc.pop();
            stc.push(tsum);
        }
        else if(s[i]>='2' && s[i]<='9')
        {
            int tsum=stc.top();
            stc.pop();
            tsum=tsum*(s[i]-'0');
            stc.push(tsum);
        }
        else{stc.push(mass(s[i]));}
    }
    while(!stc.empty()){sum+=stc.top(); stc.pop();}
    cout<<sum<<"\n";
    return 0;
}
