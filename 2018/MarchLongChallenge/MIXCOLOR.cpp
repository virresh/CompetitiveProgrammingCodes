#include <bits/stdc++.h>
using namespace std;

#define sz 100005

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		map<int,int> hMap;
		int n;
		cin>>n;
		for(int i=0; i<n; i++)
		{
			int x;
			cin>>x;
			if(hMap.find(x) == hMap.end()){
				hMap[x] = 1;
			}
			else{
				hMap[x] +=1;
			}
		}
		map<int,int>::iterator it;
		int ans=0;
		for(it = hMap.begin(); it!=hMap.end(); it++)
		{
			ans = ans + it->second-1;
		}			
		cout<<ans<<"\n";
	}
	return 0;
}
