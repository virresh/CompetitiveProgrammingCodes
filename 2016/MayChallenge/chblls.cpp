#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
	naive method, use pan 4 times and get weight of 4 color types - 49%
		-->	exactly 4 pans
	comparision based		- 80%
		--> atmost two pans
	comparision 2 			- 100%
		--> exactly one pan
*/
int main()
{
	int ans=-1;
	cout<<"1\n";
	cout<<"3 1 1 2\n";
	cout<<"3 3 3 4\n";
	fflush(stdout);
	int res1;
	cin>>res1;
	if(res1==0)
	{
		ans=5;
	}
	else if(res1==1){
		ans=2;
	}
	else if(res1==2){
		ans=1;
	}
	else if(res1==-1){
		ans=4;
	}
	else if(res1==-2){
		ans=3;
	}
	cout<<"2\n";	
	cout<<ans<<"\n";
	//fflush(stdout);
    return 0;
}
