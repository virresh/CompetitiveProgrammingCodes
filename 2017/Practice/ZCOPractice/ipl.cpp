#include <bits/stdc++.h>
using namespace std;

#define sz 200005
int n;
int arr[sz];

int dp[sz][3];

int getAns(int start,int k){
    if(start>=n){
        return 0;
    }
    if(k>=2){
        if(dp[start+1][0]!=0){
            return dp[start+1][0];
        }
        dp[start+1][0] = getAns(start+1,0);
        return dp[start+1][0];
    }
    int p1=0,p2=0;
    if(dp[start+1][k+1] !=0){
        p1 = dp[start+1][k+1] + arr[start];
    }
    if(dp[start+1][0] !=0){
        p2 = dp[start+1][0];
    }
    if(p1==0){
        p1 = getAns(start+1,k+1)+arr[start];
    }
    if(p2==0){
        p2 = getAns(start+1,0);
    }
    int p = max(p1,p2);
    //cout<<" ------> "<<start<<" , "<< p<<" , "<<k<<"\n";
    return p;
}

int main()
{
    memset(dp,0,sizeof(dp));
	cin>>n;
	for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<getAns(0,0)<<"\n";
    return 0;
}
