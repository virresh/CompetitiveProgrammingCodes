#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100005
ll id[sz],pre[sz];

int main()
{
    ll n,k,lbar=-1,ans;
	cin>>n>>k;
	pre[0]=0;
	for(ll i=1;i<=n;i++)
	{
		cin>>id[i];
		if(i!=0)
		{
			pre[i]=pre[i-1]+i;
			if(pre[i]>k && lbar==-1)
			{
				lbar=i-1;
			}
			else if(pre[i]==k && lbar==-1)
			{
				lbar=i;
			}
		}
	}
	ans=k-pre[lbar];
	if(ans!=0)
	{
		cout<<id[ans]<<"\n";	
	}
	else
	{
		cout<<id[lbar]<<"\n";
	}
    return 0;
}
