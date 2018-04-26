#include <bits/stdc++.h>

using namespace std;

int bucket[1005],n,k,bSize,b[100005],a[100005];

int query(int l, int r){
	// int bS = sqrt(n);
	int res = -1;
	if(l<=r){
		while(l<r && l%bSize!=0 && l!=0){
			res = max(res, b[l]);
			l++;
		}

		while(l+bSize <=r){
			res = max(res,bucket[l/bSize]);
			l+=bSize;
		}

		while(l<=r){
			res = max(res,b[l]);
			l++;
		}
		return res;
	}
	else{
		return max(query(l,n-1),query(0,r));
	}
	// l = l%n; 
	// r = r%n;
	// int ans  = b[r];
	// for(int i=l; i!=r; i= (i+1)%n){
	// 	ans = max(ans, b[i]);
	// }
	// return ans;
}


int main(){
	int p;
	cin>>n>>k>>p;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	// index b[i] will store the answer for frame i to i+k-1
	int start = 0, end = min(k-1,n-1), result=0;
	int i=start;
	while(i<=end){
		if(a[i]==1){
			result ++;
		}
		i++;
	}
	b[start]=result;
	while(start <=n){
		int sInd = start % n;
		int eInd = (end+1)%n;
		if(a[sInd]==1){
			result--;
		}
		if(a[eInd]==1){
			result++;
		}
		start++;
		end ++;
		b[start]=result;
	}

	//apply square root decomposition on b

	int temp=0; //bucket array
	bSize = sqrt(n);
	int bi = 0;
	bucket[0]=b[0];
	while(temp<n){
		bucket[bi]=max(bucket[bi],b[temp]);
		temp++;
		if(temp%bSize==0){
			bi++;
			bucket[bi]=b[temp];
		}
	}

	// int numBuckets = ceil(n/(float)bi);
	// for(int j=0; j<n; j++){
	// 	cout<<b[j]<<" ";
	// }
	// cout<<numBuckets<<"\n";
	// for(int j=0; j<numBuckets; j++){
	// 	cout<<bucket[j]<<" ";
	// }
	string s;
	cin>>s;
	int shift = 0;
	for(int i=0; i<p; i++){
		if(s[i]=='!'){
			shift= (shift+1)%n;
		}
		else if(s[i]=='?'){
			int start = (0-shift+n)%n;
			// cout<<start<<" "<<end<<" "<<query(start,end)<<"\n";
			cout<<query(start,((start-min(k,n-1)+n))%n)<<"\n";
		}
	}
	return 0;
}