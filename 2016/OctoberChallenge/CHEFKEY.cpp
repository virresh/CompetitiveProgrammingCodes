#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,c;
		cin>>n>>m>>c;
		int i=1,ans=0;
		for(;i<=n;i++){
			if(c%i == 0 && c/i <= m){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}