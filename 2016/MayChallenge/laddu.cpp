#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int t;
	cin>>t;
	while(t--)
	{
		int n,laddus=0;
		string s,origin;
		cin>>n>>origin;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			if(s=="CONTEST_WON")
			{
				int p;
				cin>>p;
				laddus=(laddus + 300 )+ ((p<20)?(20-p):0) ;
			}
			else if(s=="BUG_FOUND")
			{
				int p;
				cin>>p;
				laddus+=p;
			}
			else if(s=="TOP_CONTRIBUTOR")
			{
				laddus+=300;
			}
			else if(s=="CONTEST_HOSTED")
			{
				laddus+=50;
			}
			//cout<<laddus<<"\n";
		}
		if(origin=="INDIAN")
		{
			cout<<(laddus/200)<<"\n";
		}
		else
		{
			cout<<(laddus/400)<<"\n";
		}
	}
    return 0;
}
