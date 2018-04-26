#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 3005

int blocks[sz];
int n,k,ans=0;
int solve(int pos,int phase)
{
    if(pos<0 || pos>n)
    {
        return 0;
    }
    else if(pos==0){return ans;}
    if(phase ==1) // forward phase
    {

    }
    else if(phase==0) //backward phase
    {

    }
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>block[i];
    }
    cout<<max(solve(k,1),solve(k,0));
    return 0;
}
