#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string a[4],b[4];
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		cin>>b[0]>>b[1]>>b[2]>>b[3];
		int matches=0;
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(a[i]==b[j]){
					matches++;
				}
			}
		}
		if(matches<=1){
			cout<<"dissimilar\n";
		}
		else{
			cout<<"similar\n";
		}
	}
	return 0;
}