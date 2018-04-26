#include <bits/stdc++.h>
using namespace std;
#define sz 105
int a[sz];
int ascendingCount[11];
vector<int>condense;
vector<int>num;

int f(int x)
{
    if(x<=7)
    {
        return x;
    }
    else
    {
        return (7 - (x-7));
    }
}

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        memset(ascendingCount,0,sizeof(ascendingCount));
        condense.clear();
        num.clear();
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int curCount=1;
        for(int i=1; i<n; i++)
        {
            if(a[i]==a[i-1])
            {
                curCount ++;
            }
            else
            {
                condense.push_back(curCount);
                num.push_back(a[i-1]);
                curCount = 1;
            }
        }
        condense.push_back(curCount);
        num.push_back(a[n-1]);

        bool isRainbow=true;
        if(num.size()!=13){
            isRainbow = false;
        }
        for(int i=0; i<num.size(); i++)
        {
            int j = f(i+1);
            if(j<0 || j>=num.size()){
                isRainbow=false;
                break;
            }
            if(num[i] !=j)
            {
                isRainbow=false;
                break;
            }
        }
        for(int i=0; i<num.size(); i++)
        {
            //cout<<num[i]<<" " <<condense[i]<<"\n";
            if(condense[i] != condense[condense.size()-i-1]){
                isRainbow=false;
                break;
            }
        }

        if(isRainbow)
        {
            cout<<"yes\n";
        }
        else
        {
            cout<<"no\n";
        }

    }
	return 0;
}
