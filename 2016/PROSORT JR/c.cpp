#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define sz 505

int maze[sz][sz]; 	// n rows and m columns
int n,m;

ll solve(int i,int j,ll h,int e){ // h -> happiness e -> energy
	cout<< i <<" " << j<<" " <<h<< " "<<e<<"\n";
	if(i==n-1 and j==m-1){  cout<<" base case ";  return h+maze[i][j]; }
	if(e==0){return -1;}
	
	if(i+1<n and j+1<m){
		//move down and move right
		ll p = max(solve(i+1,j,h+maze[i][j],e+1),solve(i,j+1,h+maze[i][j],e-1));
		return h+p;
	}
}

int main()
{
	cin>>n>>m;
	for (int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			cin>>maze[i][j];
		}
	}
	
	cout<<solve(n-1,m-2,0,1)<<"\n";
	return 0;
}
