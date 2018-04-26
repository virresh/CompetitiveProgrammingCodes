#include <bits/stdc++.h>
using namespace std;

class swiftstack{
    char p[1000005];
    int sz;

public:
    swiftstack()
    {
        sz = 0;
    }

    char top()
    {
        if(sz>0){
            return p[sz-1];
        }
        else{
            cout<<"Here\n";
            return '=';
        }
    }

    void push(char x)
    {
        p[sz]=x;
        sz++;
    }

    void pop()
    {
        if(sz>0){
            sz--;
        }
        else{
            cout<<"Empty Stack\n";
        }
    }

    void clr()
    {
        sz=0;
    }

    bool mty()
    {
        if(sz==0)
        {
            return true;
        }
        return false;
    }
    int siz()
    {
        return sz;
    }
};


int main()
{
    int t;
    cin>>t;
    string s;
    swiftstack stk;
    while(t--)
    {
        int k=0;// ,mx=0,mn=0;
        cin>>s;
        stk.clr();
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] != '=')
            {
                if(stk.mty())
                {
                    stk.push(s[i]);
                    k=1;
                }
                else
                {
                    if(s[i]==stk.top())
                    {
                        stk.push(s[i]);
                        k = max(k,stk.siz());
                    }
                    else
                    {
                        stk.clr();
                        stk.push(s[i]);
                    }
                }
            }
        }
        int x = k+1;

        // x = x + (mx - mn);
        cout<<x<<"\n";
    }
    return 0;
}
