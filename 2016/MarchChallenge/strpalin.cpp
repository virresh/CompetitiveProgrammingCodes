#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		bool possible=false;
		int i,j;
		for(i=0;i<a.length();i++)
		{
			for(j=0;j<b.length();j++)
			{
				if(a[i]==b[j])
				{
					possible=true;
					break;
				}
			}
			if(possible)
			{
				break;
			}
		}
		
		if(possible)
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
    return 0;
}
