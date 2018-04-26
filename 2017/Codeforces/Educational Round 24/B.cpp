#include <bits/stdc++.h>
using namespace std;
#define sz 10005

int a[sz];
int countS[sz];

int main()
{
    int n,m;
    cin>>n>>m;
    bool possible=true;
    memset(a,0,sizeof(a));
    int s=0;
    cin>>s;
    for(int i=1; i<m; i++)
    {
        int t;
        cin >>t;
        int newIndex = ( t - s + n )%n;
        if(newIndex == 0)
        {
            newIndex = n;
        }
        if(a[s]==0)
        {
            a[s] = newIndex;
        }
        else if(a[s] != newIndex)
        {
            possible = false;
        }
        s = t;
    }

    for(int i=1; i<=n; i++)
    {
        if(a[i]==0){
            continue;
        }
        countS[a[i]]++;
        if(countS[a[i]] > 1)
        {
            possible = false;
        }
    }

    if(possible)
    {
        for(int i=1; i<=n; i++)
        {
            if(a[i]==0)
            {
                int j;
                for(j=1; j<=n; j++)
                {
                    if(countS[j]==0)
                    {
                        countS[j]++;
                        break;
                    }
                }
                a[i]= j;
            }
        }

        for(int i=1; i<=n; i++)
        {
            cout<<a[i]<<" ";
        }
    }
    else{
        cout<<"-1";
    }

    cout<<"\n";
    return 0;
}
