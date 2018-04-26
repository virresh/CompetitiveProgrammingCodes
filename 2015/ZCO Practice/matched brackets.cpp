#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    stack <ll> stc;
    ll n,i,x,maxdepth,maxdeppos,maxseq,maxseqpos,p;
    ll tdep,tseq;
    maxdepth=maxdeppos=maxseq=maxseqpos=-1;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        p=i;
        if(x==1)
        {
            stc.push(p);
            if(stc.size()>maxdepth){maxdepth=stc.size(); maxdeppos=p+1;}
        }
        if(x==2)
        {
            p=stc.top();
            stc.pop();
            if(i-p+1 > maxseq){maxseq=i-p+1; maxseqpos=p+1;}
        }
    }
    cout<<maxdepth<<" "<<maxdeppos<<" "<<maxseq<<" "<<maxseqpos<<" ";
    return 0;
}
