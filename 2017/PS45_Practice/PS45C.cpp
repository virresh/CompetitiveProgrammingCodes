#include <bits/stdc++.h>

using namespace std;
#define sz 100005
#define ll long long

char s[sz];
ll x[sz];
ll y[sz];

int X(char c){
	switch(c){
		case 'N': return 0;
		case 'E': return 1;
		case 'S': return 0;
		case 'W': return -1;
		default: return 0;
	}
}


int Y(char c){
	switch(c){
		case 'N': return 1;
		case 'E': return 0;
		case 'S': return -1;
		case 'W': return 0;
		default: return 0;
	}
}

int main(){
	ll n,q,xSum=0,ySum=0;
	scanf("%lld %lld",&n,&q);
	scanf("%s",s);
	for(int i=0; i<n; i++){
		x[i] = X(s[i]) + i==0?0:x[i-1];
		y[i] = Y(s[i]) + i==0?0:y[i-1];
	}
	xSum = x[n-1]; ySum = y[n-1];
	for(int j =0; j<q; j++){
		ll xc,yc;
		scanf("%lld %lld",&xc,&yc);
		bool target = false;
		for(int i=n-1; i>=0; i++){
			ll tempx = x[i],tempy = y[i];
			if(x[n-1] != 0 && y[n-1] !=0){
				bool a,b,c;
				a = (xc-tempx)%xSum == 0;
				b = (yc - tempy)%ySum ==0;
				c = 

			} 
			else if(x[n-1] == 0 && y[n-1] !=0){

			}
			else if(x[n-1] != 0 && y[n-1] ==0){

			}
			else{

			}
		}
	}
	return 0;
}