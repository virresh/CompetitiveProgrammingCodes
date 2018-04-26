#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	int s,n,h[1005],maxIndex=-1;
	cin>>s;
	while(s--){
		cin>>n;
		maxIndex = 0;
		for(int i=0; i<n; i++){
			cin>>h[i];
			if(h[i]>h[maxIndex]){
				maxIndex = i;
			}
		}

		bool valid = true;

		if(maxIndex != n/2 || n%2!=1){
			valid = false;
		}
		else{
			for(int i=0; i<n; i++){
				if(i==0 && h[i]!=1){
					valid = false;
				}
				else if(h[i] == h[i-1]){
					valid = false;
				}
				else if(h[i] == h[i-1]+1 && i <= maxIndex){
					// valid = false;
				}
				else if(h[i] == h[i-1]-1 && i >= maxIndex){
					// valid = false;
				}
				else{
					valid = false;
				}
			}

		}


		if(valid == false){
			cout<<"no\n";
		}
		else{
			cout<<"yes\n";
		}
	}
	return 0;
}