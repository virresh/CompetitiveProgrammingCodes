#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		int a[3],ans=0;
		a[0]=a[1]=a[2]=0;
		cin>>n;
		cin>>s;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='R')
			{
				a[0]++;
			}
			else if(s[i]=='G')
			{
				a[1]++;
			}
			else
			{
				a[2]++;
			}
		}
		ans=max(max(a[0],a[1]),a[2]);
		ans = n-ans;
		cout<<ans<<"\n";
	}
    return 0;
}
