#include <bits/stdc++.h>
using namespace std;
#define ll long long
void printarr(int *a, int n){
	for(int i=1; i<=n; i++){
		cout<<a[i];
	}
	cout<<"\n";
}
int main(){
	int t;
	scanf("%d\n",&t);
	while(t--){
		ll a[100005],n=0,nextOne[100005],cost[100005],b[100005];
		char s[100005];
		memset(cost,0,sizeof(cost));
		memset(b,0,sizeof(b));
		memset(nextOne,0,sizeof(nextOne));
		scanf("%s",s);
		for (int i = 0; s[i] !='\0'; ++i)
		{
			a[i+1]= (s[i]=='1')?1:0;
			n++;
		}
		// for(int j=1; j<=n; j++){
		// 	cout<<a[j]<<" ";
		// }
		ll tempC=0, nO = n+1;
		for(int k=n; k>=1; k--){
			b[k]=tempC;
			nextOne[k]=nO;
			if(a[k]==1){
				tempC++;
				nO = k;
			}
		}

		for(int i=n; i>=1; i--){
			if(a[i]==1){
				int x = nextOne[i]-i;
				if(x<=1){
					x=0;
				}
				cost[i]=cost[nextOne[i]] + x;
			}
		}

		ll ans=0;
		for(int i=1; i<=n; i++){
			ans+=cost[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}