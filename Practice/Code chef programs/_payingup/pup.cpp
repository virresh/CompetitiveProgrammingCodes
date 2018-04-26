#include <iostream>
#include <algorithm>
using namespace std;
int calc(int k,int val[],int n)
{
    sort(val,val+n);
    int memo[k+1];
    memo[0]=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;val[j]<=k;j++)
        {
            if(val[j]>k){memo[i]=memo[i-1];}
            else {memo[i]=max(memo[i-1]+val[j], memo[k-val[j]]+memo[val[j]]);}
        }
    }
    return memo[k];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        if(calc(k,a,n)==k){cout<<"YES\n";}
        else {cout<<"NO\n";}
    }
    return 0;
}
