#include <bits/stdc++.h>
using namespace std;
#define ll long long
//  1-> (    2-> )
//  3-> [    4-> ]
int main()
{
    stack< pair<ll,int> > s;
    pair <ll,int> p,q; //stack handles
    ll n,i,galtdepth=0,taltdepth=1,brack1=0,temp,brack2=0; // taltdepth - temporary alternating depth g- global
    int y=0,curr_type=0;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>y;

        if(y==1 || y==3) // Need to push onto stack
        {
            if(s.empty()){taltdepth=1; curr_type=y;}
            p.first=i;
            p.second = y;
            s.push(p);
            if(y!=curr_type)
            {
                curr_type=y;
                taltdepth++;
            }
        }
        else if(y==2|| y==4) // Need to pop an element
        {
            q=s.top();
            s.pop();
            if(!s.empty())
            {
                curr_type=s.top().second;
            }
            if(y==2)
            {
                temp= i-q.first+1;
                if(temp>brack1)
                {
                    brack1=temp;
                }
            }
            else if(y==4)
            {
                temp= i-q.first+1;
                if(temp>brack2)
                {
                    brack2=temp;
                }
            }
            if(taltdepth>galtdepth)
            {
                galtdepth=taltdepth;
            }
            if(q.second!=curr_type)
                taltdepth--;
        }
    }
    cout<<galtdepth<<" "<<brack1<<" "<<brack2;
    return 0;
}
