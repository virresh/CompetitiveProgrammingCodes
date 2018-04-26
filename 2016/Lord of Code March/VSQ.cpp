#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000005
ll a[sz];

int main()
{
    int n,q,i,a,b;
	ll x;
	vector <int> v;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	vector <int> ::iterator low,high;
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>a>>b;
		low = lower_bound(v.begin(),v.end(),a);
		high = upper_bound(v.begin(),v.end(),b);
		cout<< high - low<<"\n";
	}
    return 0;
}
