#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define sz 1000005

ll a[sz],nextGreater[sz],nextSmaller[sz];

int main(){
	int n,q;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	stack <ll>  stk;
	stk.push(0);
	// compute next greater elements in O(n)
	for(int i=1; i<n; i++){
		if(!stk.empty()){
			int indx = stk.top();
			stk.pop();

			while(a[indx]<a[i]){
				nextGreater[indx] = i;
				if(stk.empty()){
					break;
				}
				indx = stk.top();
				stk.pop();
			}

			if(a[indx]>=a[i]){
				stk.push(indx);
			}
			stk.push(i);
		}
	}

	while(!stk.empty()){
		int indx = stk.top();
		stk.pop();
		nextGreater[indx] = -1;
	}

	//compute nextSmaller elements in O(n)
	stk.push(0);
	for(int i=1; i<n; i++){
		if(!stk.empty()){
			int indx = stk.top();
			stk.pop();

			while(a[indx]>a[i]){
				nextSmaller[indx] = i;
				if(stk.empty()){
					break;
				}
				indx = stk.top();
				stk.pop();
			}

			if(a[indx]<=a[i]){
				stk.push(indx);
			}
			stk.push(i);
		}
	}

	while(!stk.empty()){
		int indx = stk.top();
		stk.pop();
		nextSmaller[indx] = -1;
	}

	// for(int i=0; i<n; i++){
	// 	cout<<a[i]<<" "<<nextSmaller[i]<<" "<<nextGreater[i]<<"\n";
	// }

	int score=0;
	for(int i=0; i<n; i++){
		if(nextGreater[i]==-1){
			score+=15;
		}
		else{
			if(nextSmaller[nextGreater[i]] == -1){
				score +=10;
			}
			else{
				score +=5;
			}
		}
	}
	cout<<score<<"\n";
	return 0;
}