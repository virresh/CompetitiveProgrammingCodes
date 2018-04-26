#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	for(int u=0; u<t; u++)
	{
		int n;
		vector<ll> listA,listB;
		cin>>n;
		for(int i=0; i<n; i++)
		{
			ll x;
			cin>>x;
			if(i%2==0)
			{
				listA.push_back(x);
			}
			else
			{
				listB.push_back(x);
			}
		}

		sort(listA.begin(),listA.end());
		sort(listB.begin(),listB.end());

		vector<ll> finalList;
		int i=0,j=0,k=0;
		while(j<listA.size() || k<listB.size())
		{
			if(i%2==0)
				finalList.push_back(listA[j++]);
			else
				finalList.push_back(listB[k++]);
			i++;
		}
		int anomalyIndex = -1;
		// for(int v=0; v<finalList.size(); v++)
		// {
		// 	cout<<finalList[v]<<" ";
		// }
		// cout<<"\n";
		for(int temp=1; temp<i; temp++)
		{
			if(finalList[temp] < finalList[temp-1])
			{
				anomalyIndex = temp-1;
				break;
			}
		}
		cout<<"Case #"<<u+1<<": ";
		if(anomalyIndex == -1)
		{
			cout<<"OK\n";
		}
		else{
			cout<<anomalyIndex<<"\n";
		}
	}
	return 0;
}
