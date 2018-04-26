#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100005

int main()
{
    char s[sz];
    ll j=0,i;
    bool isTypeA;
    cin>>s;
    vector <string> a,b;
    string p;
    for(i=0;s[i]!='\0';i++)
    {
        p.erase();
        isTypeA=true;
        for(j=i;s[j]!=';' && s[j]!=',';j++)
        {
            if(isalpha(s[i]))
            {
                isTypeA=false;
            }
            p+=s[j];
        }
        if(isTypeA)
        {
            a.push_back(p);
        }
        else
        {
            b.push_back(p);
        }
        i=j-1;
    }
    for(i=0;i<a.size();i++)
    {
        if(i==a.size()-1)
        {
            cout<<a[i]<<"\n";
        }
        else
        {
            cout<<a[i]<<",";
        }
    }

    for(i=0;i<b.size();i++)
    {
        if(i==b.size()-1)
        {
            cout<<b[i]<<"\n";
        }
        else
        {
            cout<<b[i]<<",";
        }
    }
    return 0;
}
