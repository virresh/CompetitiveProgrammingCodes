#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{	
	int i,t,a[1000000];
	scanf("%d",&t);
	for(i=0;i<t;i++)
		scanf("%d",&a[i]);
	sort(a,a+t);
	for(i=0;i<t;i++)
		printf("%d\n",a[i]);
	return 0;
}
