#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int h1,h2,cpos=0,a,b,k,hrs=0,cur_time=0; //in 24hr format
	cin>>h1>>h2>>a>>b;
	cpos=h1
	while(cpos<h2) // will compute total no of hrs taken
	{
		hrs++;
		if(cur_time >=10  && cur_time <=22) // day time
		{
			cpos+=a;
		}
		else
		{
			cpos-=b;
		}
		cur_time = ( cur_time + 1) % 24 ;
	}
	
    return 0;
}
