#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,n,numOnes=0;
	cin>>t;
	while(t--){
		cin>>n;
		numOnes = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int x;
				cin>>x;
				if(x==1){
					numOnes ++;
				}
			}
		}
		int b = 0;
		int low=0,high=n;
		while(b<=n){
			if( 0<=numOnes && numOnes<=high){
				break;
			}
			b++;
			low = high+1;
			high = high + 2 * (n-b);
		}
		cout<<b<<"\n";
	}
	return 0;
}