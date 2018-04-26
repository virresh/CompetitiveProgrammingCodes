#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,m,i,num;
	priority_queue <int> pq;
	cin>>n>>m;
	for(i=0;i<m+n;i++)
	{
		cin>>num;
		if(num==-1)
		{
			cout<<pq.top()<<"\n";
			pq.pop();
		}
		else
		{
			pq.push(num);
		}
	}
	return 0;
}