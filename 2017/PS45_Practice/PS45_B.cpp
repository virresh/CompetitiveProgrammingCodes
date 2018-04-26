#include <bits/stdc++.h>

using namespace std;
#define sz 100005

int a[sz],freq[sz];
int main(){
	//fails in cases where answer should be zero
	int n, x,ans=0;
	cin>>n>>x;
	memset(freq,0,sizeof(freq));
	for(int i=0; i<n; i++){
		cin>>a[i];
		freq[a[i]]++;
	}
	int j=0,res=0;

	if(freq[x]==0){
		//the element doesn't exist, add it
		ans++;
	}
	int l=x-1,r=x+1,leftEle=0,rightEle=0;
	while(l >0){
		leftEle +=freq[l];
		//cout<<"inside left\n";
		l--;
	}

	while(r<sz){
		rightEle += freq[r];
		//cout<<"inside right\n";
		r++;
	}
	//cout<<rightEle<< " " << leftEle<<"\n";

	if(leftEle < n/2 && leftEle+freq[x] > n/2){
		//it is already the median. No need to do anything.
	}
	else{
		if(freq[x]>1){
			if(rightEle > leftEle){
				leftEle += freq[x]-1;
			}
			else{
				rightEle += freq[x]-1;
			}
		}

		if(leftEle >= rightEle){
			ans = ans + leftEle - rightEle ;
		}
		else {
			ans = ans + rightEle - leftEle -1;
		}
	}

	cout<<ans<<"\n";
	return 0;
}