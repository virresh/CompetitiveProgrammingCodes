#include <bits/stdc++.h>

using namespace std;
#define ll long long
int f(string s){
	if(s=="Icosahedron"){
		return 20;
	}
	else if(s=="Dodecahedron"){
		return 12;
	}
	else if(s=="Octahedron"){
		return 8;
	}
	else if(s=="Cube"){
		return 6;
	}
	else if(s=="Tetrahedron"){
		return 4;
	}
	else{
		return 0;
	}
}

int main(){
	int n;
	ll ans=0;
	cin >>n;
	for(int i=0; i<n ; i++){
		string s;
		cin>>s;
		ans+=f(s);
	}
	cout<<ans<<"\n";
	return 0;
}