#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int arr[105];
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}

	//count forwards
	int forward=-1;
	for(int i=m+1; i<=n; i++){
		if(arr[i]<=k && arr[i]!=0){
			forward = i;
			break;
		}
	}
	int backward = -1;
	for(int i=m-1; i>=1; i--){
		if(arr[i]<=k && arr[i]!=0){
			backward = i;
			break;
		}
	}
	int ans = -1;
	if(forward-m < m-backward && forward !=-1 && backward !=-1){
		ans = forward-m;
	}
	else {
		ans = m-backward;
	}

	cout<<ans*10<<"\n"<<backward<<" " <<forward<<"\n";
	return 0;
}