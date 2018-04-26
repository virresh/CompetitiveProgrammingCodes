#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
	ll n,t;
	
	cin>>t;
	while(t--){
		cin>>n;
		char mood;
		cin>>mood;
		
		int res = 0; // assume always optimistic
		if(n%2 == 1){
			//o ends in o
			res = 0;
		}
		else{
			res = 1; // o ended in p
		}
		
		if (mood == 'P'){
			res = res==0?1:0;
		}
		if(res == 0){
			cout<<"He likes me.\n";
		}
		else{
			cout<<"He likes me not.\n";
		}
		
	}
	
	return 0;
}
