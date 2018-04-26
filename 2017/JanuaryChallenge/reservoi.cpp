#include <bits/stdc++.h>

#define ll long long
#define sz 1005
using namespace std;

int main(){

	int t;
	char a[sz][sz];
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0; j<m; j++){
				cin>>a[i][j];
			}
		}

		bool canChange = false;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(a[i][j]=='W'){
					//check if the block below or on it's sides is air or not
					if(( j-1>=0 && a[i][j-1] == 'A') || ( j+1<m && a[i][j+1] == 'A')){
						canChange = true;
						break;
					}
					if( i+1 < n && a[i+1][j] == 'A'){
						canChange = true;
						break;
					}
					if(j==0 || j==m-1){
						canChange = true;
						break;
					}
				}
				else if(a[i][j]=='A'){
					//check if any brick exists above 
					if( i-1 >=0 && a[i-1][j] == 'B'){
						canChange = true;
						break;
					}
				}
				else if(a[i][j]=='B'){
					//check if any air or water exists below
					if( i+1<n && a[i+1][j] == 'A'){
						canChange = true;
						break;
					}
					if( i+1<n && a[i+1][j] == 'W'){
						canChange = true;
						break;
					}
				}
			}
		}

		if(canChange){
			cout<<"no\n";
		}
		else{
			cout<<"yes\n";
		}
	}
	return 0;
}