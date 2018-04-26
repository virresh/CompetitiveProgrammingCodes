#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 10005

int main()
{
    int t;
	float a[sz];
	cin>>t;
	while(t--)
	{
		int n,k,i;
		float sum=0,avg;
		cin>>n>>k;
		int t= n-2*k;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		for(i=k; i<= (n-1-k) ; i++)
		{
			sum+=a[i];
		}
		avg= sum / t;
		printf("%0.6f\n",avg);
	}
    return 0;
}
