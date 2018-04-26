#include <bits/stdc++.h>

using namespace std;
#define ll long long


// ll l[100005],f[100005];
// f[i] == preprocessed value of i snakes

bool isHorizontal(pair<ll,ll> A, pair<ll,ll> B){
	if(A.second == B.second){
		return true;
	}
	else{
		return false;
	}
}

bool isVertical(pair<ll,ll> A, pair<ll,ll> B){
	if(A.first == B.first){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		pair <ll,ll> a_start, a_end, b_start, b_end;
		// first -> x, second -> y

		cin >> a_start.first >> a_start.second >> a_end.first >> a_end.second;
		cin >> b_start.first >> b_start.second >> b_end.first >> b_end.second;

		if(a_start > a_end){
			swap(a_start,a_end);
		}

		if(b_start > b_end){
			swap(b_start,b_end);
		}

		// cout<<" Snake A : ("<<a_start.first<<","<<a_start.second<<") to ("<<a_end.first<<","<<a_end.second<<")\n";
		// cout<<" Snake B : ("<<b_start.first<<","<<b_start.second<<") to ("<<b_end.first<<","<<b_end.second<<")\n";	
		// check for intersection in ranges [a_s_x,a_e_x] & [b_s_x , b_e_x] if a lies horizontally

		bool a_h,b_h,a_v,b_v;
		a_h = isHorizontal(a_start,a_end);
		a_v = isVertical(a_start,a_end);
		b_h = isHorizontal(b_start,b_end);
		b_v = isVertical(b_start,b_end);

		// cout<<a_h<<" "<<b_h<<"- isHorizontal \n"<<a_v<<" "<<b_v<<" - isVertical\n";

		bool ans = false;

		if(a_h && b_h){
			if(a_start.second == b_start.second){
				// ensure both are at same y
				if(max(a_start.first,b_start.first) <= min(a_end.first, b_end.first)){
					ans = true;
				}
			}
		}
		else if(a_v && b_v){
			if(a_start.first == b_start.first){
				// ensure both are at same x
				if(max(a_start.second,b_start.second) <= min(a_end.second, b_end.second)){
					ans = true;
				}
			}	
		}
		else {
			// if((a_h && b_v) || (a_v && b_h))a
			if((a_start == b_start) || (a_start==b_end) || (a_end == b_start) || (a_end == b_end) ){
				ans = true;
			}
		}

		if(ans==true){
			cout<<"yes\n";
		}
		else{
			cout<<"no\n";
		}
	}
	return 0;
}