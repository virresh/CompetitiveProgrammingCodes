#include <bits/stdc++.h>
using namespace std;

#define sz 100005

int leftT[sz];
int rightT[sz];
int a[sz];
int finalTime[sz];

int main()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    leftT[0]=0;

    for(int i=1; i<=n; i++)
    {
        leftT[i] = min(leftT[i-1]+1,a[i]);
    }
    rightT[n+1]=0;
    for(int i=n; i>=1; i--)
    {
        rightT[i] = min(rightT[i+1]+1,a[i]);
    }

    for(int i=1; i<=n; i++)
    {
        finalTime[i] = min(leftT[i],rightT[i]);
    }
    int ans = finalTime[1];
    for(int i=2; i<=n; i++)
    {
        ans = max(ans,finalTime[i]);
    }
    cout<<ans<<"\n";
	return 0;
}
