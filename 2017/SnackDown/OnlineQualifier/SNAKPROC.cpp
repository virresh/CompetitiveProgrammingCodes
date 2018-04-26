#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	int t;
	cin>>t;
	while(t--){
		int r,lastB=-1,numH=0,numT=0; // 0-> head 1-> tail
		char x,y;
		bool isValid = true;
		cin>>r;
		for(int i=0; i<r; i++){
			cin>>x;
			if(lastB==-1){
				y=x;
				if(x=='T'){
					isValid = false;
					lastB = 1;
					numT++;
				}
				else if(x=='H'){
					lastB = 0;
					numH++;
				}
			}
			else{
				if(x=='H'){
					numH++;
					if(lastB == 0){
						isValid = false;
					}
					else{
						lastB = 0;
					}
				}
				else if(x=='T'){
					numT++;
					if(lastB == 1){
						isValid = false;
					}
					else{
						lastB = 1;
					}
				}
				else if(x=='.'){

				}
			}
		}
		if(isValid && numT==numH){
			cout<<"Valid\n";
		}
		else{
			cout<<"Invalid\n";
		}
	}
	return 0;
}