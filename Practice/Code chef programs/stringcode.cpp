#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s,p;
    set <string> q;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        for(int i=1;i<s.length();i++)
        {
            p=s[i-1];
            p+=s[i];
            q.insert(p);
        }
        cout<<q.size()<<"\n";
        q.clear();
    }

    return 0;
}
