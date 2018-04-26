#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 10005
struct time{
	int h,m;
	
}

set <time> a;
set<time>::iterator it;
int main()
{
int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		time t;
		for(int i=0;i<n;i++)
		{
			cin>>t.h>>t.m;
			a.insert(t);
		}
		
		for(it=a.begin(), it++; it!=a.end() ; it++)
		{
			
		}
	}
    return 0;
}
