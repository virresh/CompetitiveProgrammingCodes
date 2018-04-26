#include <bits/stdc++.h>
using namespace std;

#define sz 100005

char x[sz];
int main(){
	int t=0;
	cin>>t;
	while(t--){
		int n,k,p,q;
		cin>>n>>k;
		scanf("%s",x);
		priority_queue<int> oStrings;
		priority_queue<int> zStrings;
//		for(int j=0; j<=n; j++){
//			cout<<x[j]<<"_";
//		}
//		cout<<"\n";
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

		p = oStrings.empty() ? 0 : oStrings.top();
		q = zStrings.empty() ? 0 : zStrings.top();

		while( k>0 && ( p>=2 || q>=2 )){
            //until there are consecutive strings of length more than one and there are possible moves still left
            if(p>q){
                //max length is of one Strings
                oStrings.pop();
                k--;
                if(p%2==0){
                    oStrings.push(p/2);
                }
                else{
                    oStrings.push(p/2);
                    oStrings.push(p/2);
                }
            }
            else{
                //length of zero Strings dominate
                zStrings.pop();
                k--;
                if(q%2==0){
                    zStrings.push(q/2);
                }
                else{
                    zStrings.push(q/2);
                    zStrings.push(q/2);
                }
            }
            p = oStrings.empty() ? 0 : oStrings.top();
            q = zStrings.empty() ? 0 : zStrings.top();
		}

		while(p>=2 && q>=2 && k>=2){
            k-=2;
            oStrings.pop();
            zStrings.pop();
            p = oStrings.empty() ? 0 : oStrings.top();
            q = zStrings.empty() ? 0 : zStrings.top();
		}
		cout<<max(p,q) <<"\n";
	}
	return 0;
}
