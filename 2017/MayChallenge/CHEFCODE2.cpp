#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll a[35],k,ans;
double b[35],logK,A[20],B[20],X[100005],Y[100005];
// bool visit[35];
int n;


void calcSums(double arr[], int s_a, double sumarr[],int constant=0){
	ll i;
	for(i=0; i<(1<<s_a); i++){
		double localSum=0;
		for(int j=0; j<s_a; j++){
			if(i & (1<<j)){
				localSum+=arr[j];
			}
		}
		sumarr[i] = localSum;
		// if(localSum<=logK){
		// 	ans++;
		// }
	}
}


void solve(double a1[], int n1, double a2[], int n2){
	sort(a2, a2+n2);
	for(int i=0; i<n1; i++){
		if(a1[i]<=logK){
			int p = lower_bound(a2,a2+n2, logK-a1[i]) - a2;

			if(p==n2 || a2[p]!=(logK-a1[i])){
				p--;
			}

			ans+=(p+1);
		}
	}
}


int main(){
	cin>>n>>k;
	ans=0;
	logK = log(k);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0; i<n; i++){
		b[i]=log(a[i]);
		// b[i]=a[i];
	}

	for(int i=0; i<n/2 ; i++){
		A[i]=b[i];
	}

	for(int i=n/2; i<n; i++){
		B[i-n/2] = b[i];
	}

	calcSums(A,n/2,X,0);
	calcSums(B,n-n/2,Y,n/2);

	ll sizX = 1<<n/2 ;
	ll sizY = 1<<(n-n/2);

	solve(X,sizX,Y,sizY);
	cout<<ans-1<<"\n";

	// for(int i=0; i<sizX; i++){
	// 	cout<<X[i]<<" ";
	// }
	// cout<<"\n";
	// for(int j=0; j<sizY; j++){
	// 	cout<<Y[j]<<" ";
	// }
	// cout<<"\n"<<logK<<"\n";

	return 0;
}