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
		a[i]%=7; //take modulo here only so that the sum will not exceed int and sliding 
		//window will become applicable
	}
	// brute force O(n^2)
	// sliding window O(n)
	int i,j,maxCows=0,left,right,sum;
	left=right=0;
	sum=a[0];
	while(left<=right && left<n && right <n)
	{
		/*if(sum%7 ==0)// a valid sequence
		{
			if(right-left+1 > maxCows)
			{
				maxCows=right-left+1;
			}
		}*/
		
		if(sum<7){
			right++; 
			if(right<n)
			sum=sum+a[right];
		}
		else if(sum>=7)	//time to contract this window
		{
			if(right-left+1 > maxCows && sum==7)
			{
				maxCows=right-left+1;
			}
			sum= sum-a[left];
			left++;
		}
	}
	fout<<maxCows<<"\n";
    return 0;
}
