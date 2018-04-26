#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1005
bool possible;
bool isLucky(int p)
{
	int x;
	while(p>0)
	{
		x=p%10;
		if(!(x==7 || x==4))
		{
			return false;//not a lucky number
		}
		p/=10;
	}
	return true;
}
void solve(int p)
{
	if(isLucky(p))
	{
		possible=true;
		return;
	}
	for(int i=4;i<=777;i++)
	{
		if(p%i == 0)
		{
			if(isLucky(i))
			{
				possible=true;
				return;
			}
		}
	}
}
int main()
{
	int n;
	possible=false;
	cin>>n;
	solve(n);
	if(possible)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
    return 0;
}
