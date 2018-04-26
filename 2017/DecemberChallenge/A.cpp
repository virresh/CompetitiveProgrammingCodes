#include <bits/stdc++.h>
using namespace std;

int getCost(char a, char b){
	//cost of replacing a -> b
	if(a == b){
		return 0;
	}
	else if(a == 'R'){
		return 5;
	}
	else{
		return 3;
	}
}

int main()
{
	int t;
	char cake[105][105];
	// cost of R-> G = 5
	// G -> R = 3
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0; i<n; i++){
			scanf("%s",cake[i]);
		}
		char t = 'R';
		int ans1 = 0, ans2 = 0;
		for(int i=0; i<n; i++){
			if(i%2 == 0){
				t = 'R';
			}
			else{
				t = 'G';
			}

			for(int j=0; j<m; j++){
				//cout<<t<<" ";
				ans1 = ans1 + getCost(cake[i][j],t);
				t = (t=='R')?'G':'R';
			}
			//cout<<"\n";
		}

		for(int i=0; i<n; i++){
			if(i%2 == 0){
				t = 'G';
			}
			else{
				t = 'R';
			}

			for(int j=0; j<m; j++){
				//cout<<t<<" ";
				ans2 = ans2 + getCost(cake[i][j],t);
				t = (t=='R')?'G':'R';
			}
			//cout<<"\n";
		}
		cout<<min(ans1,ans2)<<"\n";
	}
	return 0;
}
