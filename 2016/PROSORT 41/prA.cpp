#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n=0;
	ll a=0,l1=0,l2=0,msum=0;
	cin>>n;
	for(ll i=1; i<=n; i++){
		cin>>a;
		if(i==1){
            l1=a;
		}
		else{
            if(l1+a > msum){
                msum= l1+a;
            }
            l1=a;
		}
	}
	cout<<msum<<"\n";
    return 0;
}
