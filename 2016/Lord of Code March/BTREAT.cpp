#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100005
int a[sz];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i;
		ll sum=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum +=a[i];
		}
		if(sum%n!=0)
		{
			cout<<"No Treat\n";
		}
		else
		{
			int tcandy = sum / n;	// tcandy is the no of chocolates is each bag
			ll ans=0;
			for(i=0;i<n;i++)
			{
				ans+= abs(tcandy-a[i]); // get the sum of deviations from mean
			}
			ans = ans / 2 ; // this should be the minimum no of candies to transfer
			cout<<ans<<"\n";
		}
	}
    return 0;
}
