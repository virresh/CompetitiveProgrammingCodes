#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
    {
        ll m;
        cin>>m;
        ll p = m%3;
        ll d = m/3;
        ll xS = d, yS = 2*d;
        if(p==1)
        {
            xS +=1;
        }
        else if(p!=0)
        {
            xS+=1;
            yS+=(p-1);
        }
        cout<<xS<<" "<<yS<<"\n";
    }
	return 0;
}
