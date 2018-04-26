#include <bits/stdc++.h>
using namespace std;

#define sz 100005

char x[sz];
int main(){
	int t=0;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		scanf("%s",x);
		priority_queue<int> oStrings;
		priority_queue<int> zStrings;
		int d=0;
		for(int j=0; j<=n; j++){
			cout<<x[j]<<"_";
		}
		cout<<"\n";
		for(int j=0; j<=n-1; j++){
			int cnt=1;
			while(x[j+1]==x[j]){
				j++;
				cnt++;
			}
			if(x[j]=='1'){
				oStrings.push(cnt);
			}
			else{
				zStrings.push(cnt);
			}
		}
		cout<<"\n"<<(!oStrings.empty() && !zStrings.empty())<<" - HERE\n";
		//cout<<oStrings.top()<<" "<<zStrings.top()<<"\n";
		while(( (!oStrings.empty()) && (!zStrings.empty()) )) {
			cout<<"Here\n";
			int x = oStrings.top();
			int y = zStrings.top();
			if(x>=y){
				if(x%2==0 && x>2){
					k--;
					oStrings.pop();
					oStrings.push(x/2);
				}
				else if(x>2){
					k--;
					oStrings.pop();
					oStrings.push(x/2);
					oStrings.push(x/2);
				}
			}
			else {
				if(y%2==0 && y>2){
					k--;
					zStrings.pop();
					zStrings.push(y/2);
				}
				else if(y>2){
					k--;
					zStrings.pop();
					zStrings.push(y/2);
					zStrings.push(y/2);
				}
			}

			if(oStrings.top() <=2 && zStrings.top() <=2){
				break;
			}
		}

		cout<<"here";

		while(k>=2 && oStrings.top()>=2 && zStrings.top()>=2 && !oStrings.empty() && !zStrings.empty()){
			k-=2;
			oStrings.pop();
			zStrings.pop();
		}
		//cout<<" "<<oStrings.top()<<" "<<zStrings.top()<<"\n";

		cout<<max(oStrings.top(),zStrings.top())<<"\n";
	}
	return 0;
}