#include <bits/stdc++.h>
using namespace std;

#define sz 100005
#define ll long long
int a[sz];
int maxP[sz];
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    maxP[n-1]=a[n-1];
    for(int i=n-2; i>=0; i--)
    {
        if(a[i]>maxP[i+1])
        {
            maxP[i]=a[i];
        }
        else
        {
            maxP[i] = maxP[i+1];
        }
    }
    ll maxProfit=0,tempBuy=0, nBuy=0;
    for(int i=0; i<n; i++)
    {
        //cout<<maxP[i]<<" ";
        if(maxP[i]>a[i])
        {
            tempBuy+=a[i];
            nBuy +=1;
        }
        else
        {
            maxProfit+= maxP[i]*nBuy - tempBuy;
            tempBuy =0;
            nBuy = 0;
        }
    }
    cout<<maxProfit<<"\n";
	return 0;
}
