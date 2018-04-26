#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int sumA=0,sumB=0;
		for(int i=0; i<n; i++)
		{
			int a,b;
			cin>>a>>b;
			sumA +=a;
			sumB +=b;
		}
		cout<<(sumA-sumB)<<"\n";
	}
	return 0;
}
