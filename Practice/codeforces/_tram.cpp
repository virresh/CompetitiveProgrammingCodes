#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[1002];
int main()
{
	int t,i=0;
	ll a,b,res=0;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		res=res-a+b;
		arr[i]=res;
		i++;
	}
	cout<<*max_element(arr,arr+i);
	return 0;
}