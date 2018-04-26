#include <iostream>
using namespace std;
int arr[100];
void savea(int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    return;
}
int gmax(int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>ans){ans=arr[i];}
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,maxa,sum=0;
        cin>>n>>m;
        savea(n);
        maxa=gmax(n);
        for(int i=0;i<n;i++)
        {
            sum+=maxa-arr[i];
        }
        if(sum==m){cout<<"Yes\n";}
        else if((sum<m)&&((m-sum)%n==0)){cout<<"Yes\n";}
        else {cout<<"No\n";}
    }
    return 0;
}
