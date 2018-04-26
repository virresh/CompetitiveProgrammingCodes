#include <bits/stdc++.h>
using namespace std;
#define ll long long
int arr[1005],n;
int LCS(int n1,int n2)   // find LCS in i...j
{
    int maxLCS=0;
    int dp[1005]={0};
    dp[n1]=1;
    bool condition=true;
    if(n1==n2)
       condition=false;
    for(int i=n1+1;condition==true;i=(i+1)%n)
    {
        if(n2==i){condition=false;}
        if(i==0)            // cannot be base case thus has to be wrap around
        {
            if(arr[i]>arr[n-1])
            {
                dp[i]=dp[n-1]+1;
            }
            else
            {
                dp[i]=1;
            }
        }
        else if(arr[i]<=arr[i-1])   // the optimal solution cannot be continued.. new one starts here
        {
            dp[i]=1;
        }
        else    // solution is continued
        {
            dp[i]=dp[i-1]+1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(dp[i]>maxLCS){maxLCS=dp[i];}
    }
    return maxLCS;
}
int main()
{
    int t,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ans=LCS(1,0);
        for(int i=0;i<n;i++)
        {
            ans=max(ans,LCS(i+1,i));
        }
        cout<<ans<<"\n";
    }
    return 0;
}
