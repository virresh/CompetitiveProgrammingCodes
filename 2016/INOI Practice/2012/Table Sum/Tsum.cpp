#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 200005
//  --> O(n^2) solution
//  not enough for second case

int a[sz],ans[sz]; // b--> stores for step i
int n;
void solve(int depth)
{
    if(depth==n)
    {
        return;
    }
    int cnt=0;
    for(int k=depth+1;cnt<n;cnt++)
    {
        ans[depth]=max(a[cnt]+k,ans[depth]);
        k++;
        if(k>n){k-=n;}
    }
    solve(depth+1);
}

int main()
{
    int i;
    memset(ans,-1,sizeof(ans));
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];

    }
    solve(0);
    for(i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
