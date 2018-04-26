#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s,t;
		char a[100005];
		bool possible = true;
		int cC=0,eC=0,sC=0;
		cin>>s;
		t = s;
		sort(t.begin(), t.end());
		if(t==s){
			possible = true;
		}
		else{
			possible = false;
		}
		
		if(possible){
			cout<<"yes\n";
		}
		else{
			cout<<"no\n";
		}
	}
	return 0;
}