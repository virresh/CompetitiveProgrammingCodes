#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100005

int a[sz];

int main()
{
    int t;
	cin>>t;
	while(t--){
		bool one=false,two=false;
		int n,l=-1,b=-1;
		cin>>n;
		for(int i=0; i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		if(n<=3){
		}
		else{
			for(int i=n-2; i>=0; i--){
				if(a[i]==a[i+1]){
					if(l==-1){
						l=a[i];
					}
					else{
						b=a[i];
						break;
					}
					i--;
				}
			}
		}
		if(l==-1 || b==-1){
			cout<<"-1\n";
		}
		else{
			cout<<l*b<<"\n";
		}
	}
    return 0;
}
