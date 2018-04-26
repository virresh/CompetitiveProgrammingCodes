#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100005

int a[sz];
int main()
{
	/*int n,p,ans;
	cin>>n;
	for(int i=0; i<n;i++)
	{
		cin>>a[i];
		p=a[i];
		if(i==0)
		{
			ans=p;
		}
		else
		{
			ans= ans & p;
		}
		//cout <<ans<<" ";
	}
	//cout<<"\n";
	int x=0,y=0;
	for(int j=0;j<n;j++)
	{
		y=0;
		for(int i=j+1;i<n;i++)
		{
			y+=a[i];
		}
		x=y^a[j];
	}
	cout<<ans<<"\n"<<x<<"\n";
	*/
	cout<< (1^2 + 1^3 + 1^4 + 1^5) <<"\n";
	cout<< (1^(2+3+4+5))<<"\n";
    return 0;
}
