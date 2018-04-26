#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define md 1000000007
int p(int n, int r){ // c must be less than n, then nPr is returned
	ll res=1;
	for(int i=n-r+1; i<=n; i++){
		res= (res * i)%md ;
	}
	return (int)res;
}
int main()
{
    
    return 0;
}
