#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 505
ll a[sz][sz];


void printDiagonalELE(int rmax,int cmax)
{
	int i,j,k,tELE,tempR,tempC;
	tELE = rmax*cmax;
	tempR=tempC=0;
	i=j=0;
	int flag=-1;
	for(k=0;k<tELE;k++)	// loop exactly the no of times elements present in the matrix
	{	
		//cout<<a[i][j]<<" ";
		printf("%lld ",a[i][j]);
		i++;
		j--;
		if(!((i>=0 && i < rmax) && (j>=0 && j<cmax)))
		{
			if(tempC < cmax-1)
			{
				tempC++;
				j=tempC;
				i=tempR;
			}
			else
			{
				tempR++;
				i=tempR;
				j=tempC;
			}
		}
		
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
    int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,i,j;
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%lld ",&a[i][j]);
				//cin>>a[i][j];
			}
		}
		
		printDiagonalELE(n,m);
		printf("\n");
	}
    return 0;
}
