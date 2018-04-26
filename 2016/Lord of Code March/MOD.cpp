#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000005

ll a[sz];
int main()
{
    int n,i;
	cin>>n;
	ll l1=0,l2=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i==0)
		{
			l1=a[i];
		}
		else
		{
			if(a[i]>l1)
			{
				l2=l1;
				l1=a[i];
			}
			else if(a[i] > l2 && a[i]!=l1)
			{
				l2=a[i];
			}
		}
	}
	if(n==1)
	{
		cout<<"0\n";
	}
	else
	{
		cout<< l2%l1<<"\n";
	}
    return 0;
}
