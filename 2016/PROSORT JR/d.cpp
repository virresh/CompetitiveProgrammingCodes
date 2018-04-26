#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define sz 10005

struct bead{
	int x,y,col;
};

bool byX(bead a, bead b){
	if(a.x < b.x){
		return true;
	}
	else{
		return false;
	}
}

bool byY(bead a, bead b){
	if(a.y < b.y){
		return true;
	}
	else{
		return false;
	}
}

bead a[sz];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].col;
	}
	sort(a,a+n,byX);
	bool possible = false;
	int temp=1;
	for(int i=1; i<n;i++){			//try by x coordinates
		if(a[i].col==a[i-1].col){
			temp++;
			if(temp>2){
				possible = true;
				break;
			}
		}
		else{
			temp=1;
		}
	}
	
	if(!possible){				//try by y coordinates
		sort(a,a+n,byY);
		int temp=1;
		for(int i=1; i<n;i++){
			if(a[i].col==a[i-1].col){
				temp++;
				if(temp>2){
					possible = true;
					break;
				}
			}
			else{
				temp=1;
			}
		}
	}
	
	if(possible){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
	
}
