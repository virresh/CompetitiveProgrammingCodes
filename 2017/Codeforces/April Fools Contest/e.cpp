#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<(  ((a|b) & (c^d)) | ((b&c) ^ (a|d)) ) <<"\n";
}