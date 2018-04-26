#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MOD 1000000007
int A[2][2] = {
	{1,-1},
	{1,0}
};

void multiply(int a[2][2], int b[2][2], int c[2][2]){
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			c[i][j]=0;
			for(int k=0;k<2; k++){
				c[i][j]= (c[i][j] + a[i][k]*b[k][j]);
			}
		}
	}
}

void powE(int n, int res[2][2]){
	//Returns A^n where A is a matrix

	if(n==0){
		int c[2][2] = { 
			{1,0},
			{0,1}
		};
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++){
				res[i][j]=c[i][j];
			}
		} 
	}
	else if(n==1){
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++){
				res[i][j]=A[i][j];
			}
		}
	}
	else{
		if(n%2==0){
			int c[2][2];
			int d[2][2];
			powE(n/2,d);
			multiply(d,d,c);
			for(int i=0; i<2; i++){
				for(int j=0; j<2; j++){
					res[i][j]=c[i][j];
				}
			}
		}
		else{
			int c[2][2], e[2][2];
			int d[2][2];
			powE(n/2,d);
			multiply(d,d,c);
			multiply(A,c,e);
			for(int i=0; i<2; i++){
				for(int j=0; j<2; j++){
					res[i][j]=e[i][j];
				}
			}
		}
	}

}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,A,B;
		cin>>A>>B>>n;
		int q[2][2];
		powE(n-2,q);
		ll p = (q[0][0] * B + q[0][1]*A);
		while(p<0){
			p = p+MOD;
		}
		p = p%MOD;

		cout<<p<<"\n";
	}
	// int a[2][2]= {{1,-1},{1,0}}, b[2][2]={{2,1},{1,2}}, c[2][2];
	// powE(3,c);
	// for(int i=0; i<2; i++){
	// 	for(int j=0; j<2; j++){
	// 		cout<<c[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	return 0;
}