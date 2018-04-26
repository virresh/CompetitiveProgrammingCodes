#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100005
ll n,sum,q1,q2,q3,q4;
ll a[sz];
bool isBan(ll i)
{
	switch(i)
	{
		case q1:
		case q2:
		case q3:
		case q4: return true;
		default: return false;
	}
}

int main()
{
    int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>q1>>q2>>q3>>q4;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sum=a[0];
		// sliding window algorithm
		int left=0,right=0,tempsum=0;
		while(right<n && left<right)
		{
			if(left==right)	// only one element
			{
				right++;
				if(isBan(a[right]))
				{
					left= ++right;
				}
			}
		}
	}
    return 0;
}
