#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll t;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>s;
		for (int i = 0; i < s.size()/2; i+=2)
		{
			cout<<s[i];
		}
		cout<<"\n";
	}
	return 0;
}