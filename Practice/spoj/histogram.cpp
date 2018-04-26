#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100000
ll h[sz],res[sz];
int main()
{
    ll n,tmp,i;
    stack<ll> s;
    while(1)
    {
        cin>>n; if(n==0){break;}
        for(i=0;i<n;i++)
        {
            cin>>h[i];
        }
        for(i=0;i<n;i++)
        {
            if(s.empty()){s.push(i);}
            else
            {
                if(h[s.top()]<h[i]){s.push(i);}
                else if(h[s.top()]>h[i])
                {
                    while(h[i]<=s.top()){tmp=s.top(); s.pop(); res[tmp]= i-tmp+1;}
                    s.push(i);
                }
            }
        }
        if(!s.empty())
            {
                while(!s.empty()){tmp=s.top(); s.pop(); res[tmp]= i-tmp;}
            }
        ll *ptr=max_element(res,res+i);
        cout<<*ptr * h[ptr-res+1]<<"\n";
    }
    return 0;
}
