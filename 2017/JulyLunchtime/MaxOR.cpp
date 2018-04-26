#include <bits/stdc++.h>
using namespace std;
#define sz 1000005
#define ll long long

int a[sz], freq[sz];

int main()
{
    ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
    {
        memset(freq,0,sizeof(freq));
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            freq[a[i]]++;
        }
        ll ans=0;
        for(int j=0; j<sz; j++)
        {
            if(freq[j]>=1)
            {
                stack<int> s;
                ll k = 0;
                int temp=0;
                int num=j, pushNum=0;
                while(num>0)
                {
                    int r = num%2;
                    num = num/2;
                    if(r==1)
                    {
                        pushNum = pushNum | (1<<temp);
                        s.push(pushNum);
                    }
                    temp++;
                }
                while(!s.empty())
                {
                    if(s.top() != j)
                        k += freq[s.top()];
                    s.pop();
                }
                ans += freq[j] * k;
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}
