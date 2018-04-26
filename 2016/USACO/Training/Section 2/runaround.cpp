#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
ID: virresh1
PROG: runround
LANG: C++                  
*/
int a[11];
ll num,num2;
bool isRunaround(ll n)
{
	bool b[11]={false}; // whether an index has been yet visited
	bool repeat[11]={false}; // whether a digit is repeated or not
	int an[11];
	ll x=n,k=0;
	int i=0,j;
	while(x>0)
	{
		a[i]=x%10;
		if(repeat[a[i]]==true){return false;}
		repeat[a[i]]=true;
		x/=10;
		i++;
	}
	for(j=i-1; j>=0;j--)		// number converted to array
	{
		an[j]=a[i-j-1];
	}
	for(j=0;j<i;j++)	// runaround test
	{
		k=(an[k]+k)%i;
		if(b[k]==true){return false;}
		b[k]=true;
	}
	return true;
}
void solve()
{
	num2=num+1;
	while(!isRunaround(num2))
	{
		num2++;
	}
}
int main()
{
	//cout<<isRunaround(81362)<<"\n";
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
	int i=0,j;
    cin>>num;
	solve();
	cout<<num2<<"\n";
    return 0;
}
