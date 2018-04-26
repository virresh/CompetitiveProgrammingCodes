#include <iostream>
using namespace std;
int a[100+4];
int main() {
	int n,i=1,ans=1,res=0,odd=0,even=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
	    cin>>a[i];
	    if((a[i]&1)==0) // even number
	    {
	        even++;
	    }
	    else
	    {
	        odd++;
	    }
	}
	if(odd<even)
	{
	    res=1;
	}
	for(i=1;i<=n;i++)
	{
	    if((a[i]&1)==res)
	    {
	        ans=i;
	        break;
	    }
	}
	cout<<ans<<"\n";
	return 0;
}
