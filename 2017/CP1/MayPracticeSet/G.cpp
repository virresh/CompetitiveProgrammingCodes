#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define sz 1000005

ll a[sz], sum[sz];

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin>>n;
		for(ll i=0; i<n; i++){
			cin>>a[i];
		}
		// preprocess the sum to find sum of l to r in O(1)
		for(ll i=0; i<n; i++){
			sum[i] = ((i==0)?a[i]:(sum[i-1]+a[i]));
		}		

		multiset <ll> s;
		multiset <ll> :: iterator it;
		ll tSum = sum[n-1];
		s.insert(tSum);
		// cout<<tSum<<"\n";
		for(ll i=0; i<n; i++){
			// take in the queries
			ll o;
			cin>>o;
			o--;
			ll leftBound=o, rightBound=o;
			while(leftBound>=0 && a[leftBound]!=-1){
				leftBound--;
			}
			while(rightBound<n && a[rightBound]!=-1){
				rightBound++;
			}
			leftBound++;
			rightBound--;

			// cout<<"left - "<<leftBound<< " right - "<<rightBound<<"\n"<<"Sum Segment "<<sum[rightBound]<<" "<<sum[leftBound]<<" "<<((leftBound==0)?0:sum[leftBound-1])<<"\n";
			ll segment_sum = (sum[rightBound] - ((leftBound==0)?0:sum[leftBound-1]));
			ll leftSegSum = ((((o-1)>=0)?sum[o-1]:0) -((leftBound==0)?0:sum[leftBound-1]));
			ll rightSegSum = segment_sum - a[o] - leftSegSum;
			// cout<<"Segment Sum - "<<segment_sum<<" Left Sum "<<leftSegSum<<" Right Sum"<<rightSegSum<<"\n";
			s.erase(segment_sum);
			s.insert(leftSegSum);
			s.insert(rightSegSum);
			it = s.end();
			it--;
			cout<<*it<<"\n";

			a[o]=-1;
		}
		// for(int i=0; i<n; i++){
		// 	  cout<<a[i]<<" ";
		// }
	}
	return 0;
}