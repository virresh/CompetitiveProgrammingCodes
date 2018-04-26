#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
	cin>>t;
	while(t--)
	{
		ll f=0;
		int r,g,b,k;
		cin>>r>>g>>b>>k;
		
		int s=0;
		if(r<k-1)
		{
			s= s+ k-1-r;
		}
		if(g<k-1)
		{
			s= s+ k-1-g;
		}
		if(b<k-1)
		{
			s= s+ k-1-b;
		}
		
		f= 1+ 3*(k-1) - s;
		/*for(int i=1;i<=k;i++)
		{
			if(i==1)
			{
				f=1;
			}
			else
			{
				int temp=0;
				if(r<i-1){temp++;}
				if(g<i-1){temp++;}
				if(b<i-1){temp++;}
				f= f + 3 - temp;
			}
		}*/
		cout<<f<<"\n";
	}
    return 0;
}
