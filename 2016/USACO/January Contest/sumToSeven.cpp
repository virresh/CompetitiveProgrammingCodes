#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 50005
int a[sz];	// id's of all cows
int main()
{
    ofstream fout ("div7.out");
	ifstream fin ("div7.in");
	int n;
	fin>>n;
	for(int i=0;i<n;i++)
	{
		fin>>a[i];
	}
	// brute force O(n^2)
	int i,j,maxCows=0;
	ll sum,gsum;
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=i;j<n;j++)
		{
			sum+=a[j];
			if(sum%7==0) //this is a valid sequence
			{
				if((j-i+1) > maxCows)
				{
					maxCows=j-i+1;
				}
			}
		}
	}
	fout<<maxCows<<"\n";
    return 0;
}
