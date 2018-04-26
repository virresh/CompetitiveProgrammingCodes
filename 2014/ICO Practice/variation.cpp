#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long int a[1000000],k=0,n,i=0,res=0,j=0,key,x,temp;
int main()
{
    freopen("subtask2_5.in","r",stdin);
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=n-1;i>=0;i--)
    {
        j=0;
        while(a[i]-a[j]>=k){res++; j++;}
    }
    cout<<res<<"\n";
    return 0;
}
