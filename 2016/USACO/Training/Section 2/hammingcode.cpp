#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
ID: virresh1
PROG: hamming
LANG: C++
*/

vector<int> ans;

int hDist(int n1,int n2)  // return the hamming distance b/w n1 & n2
{
    int diff=0;
    while(n1>0 || n2>0)
    {
        if((n1&1) != (n2&1))
        {
            diff++;
        }
        n1>>=1; n2>>=1;
    }
    return diff;
}
int main()
{
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    int n,b,d;
    cin>>n>>b>>d;
    int x=0;
    ans.push_back(x);
    while(ans.size()<n)
    {
        x++;
        bool valid=true;
        for(int j=0;j<ans.size();j++)
        {
            if(hDist(ans[j],x)<d)
            {
                valid=false;
            }
        }
        if(valid)
        {
            ans.push_back(x);
        }
        if(ans.size()==n)
        {
            break;
        }
    }
    for(int i=0;i<n;)
    {
        for(int j=0;j<10 && i<n ;j++,i++)
        {
            if(j!=0){cout<<" ";}
            cout<<ans[i];
        }
        cout<<"\n";
    }
    return 0;
}
