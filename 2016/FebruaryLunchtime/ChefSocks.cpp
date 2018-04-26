#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int jacketCost,sockCost,money,noOfSocks;
	cin>>jacketCost>>sockCost>>money;
	noOfSocks=(money-jacketCost)/sockCost ;
	if(noOfSocks%2==0){
		cout<<"Lucky Chef\n";
	}
	else
	{
		cout<<"Unlucky Chef\n";
	}
    return 0;
}
