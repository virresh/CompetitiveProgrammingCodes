#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int n;
	cin>>n;
	int d,r,maxhol=0,minhol=0;
	d=n/7;
	maxhol=minhol=d*2;
	r=n%7;
	if(r!=0)
	{
		if(r<=2){maxhol+=r;}
		else{maxhol+=2;}
		
		if(r>5){minhol+=1;}
	}
	cout<<minhol<<" "<<maxhol<<"\n";
    return 0;
}
