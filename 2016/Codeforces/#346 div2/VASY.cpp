#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int n,a,b,res=0;
	cin>>n>>a>>b;
	res=a+b;
	if(res<0)
	{
		while(res<0)
		{
			res+=n;
		}
	}
	else
	{
		res = res%n;
	}
	
	if(res==0)
	{
		res=n;
	}
	cout<<res<<"\n";
    return 0;
}
