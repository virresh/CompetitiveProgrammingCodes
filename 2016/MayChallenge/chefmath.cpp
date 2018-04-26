#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 55
#define md 10000000007
ll ways[sz],chnx[sz];

ll f(ll x)	// only first 55 fibonacci numbers are sufficient
{
	if(x>=sz){
		return (f(x-1)+f(x-2))%md;
	}
	else{
		return chnx[x];
	}
}
int main()
{
    chnx[0]=0;
	chnx[1]=1;
	chnx[2]=2;
	for(int i=3;i<46;i++)
	{
		chnx[i]=(chnx[i-1]+chnx[i-2])%md;
	}
	
	int q;
	cin>>q;
	while(q--)
	{
		int x,k;
		cin>>x>>k;
		
	}
	cout<<"finished\n";
    return 0;
}
