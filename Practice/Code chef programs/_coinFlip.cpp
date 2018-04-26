#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int t,g,n,i,j,q; // i--> initial state 1=> heads q--> needs to guess 1=>heads
    cin>>t;
    while(t--)
    {
        cin>>g;
        for(j=0;j<g;j++)
        {
            cin>>i>>n>>q;
            if(q==1)//count heads
            {
                if(i==1) //initial state is head
                {
                    cout<<n/2<<"\n";
                }
                else    // initial state is tail
                {
                    if(n%2==0)
                    {
                        cout<<n/2<<"\n";
                    }
                    else
                    {
                        cout<<(n/2)+1<<"\n";
                    }
                }
            }
            else    //count tails
            {
                if(i==1)
                {
                    if(n%2==0)
                    {
                        cout<<n/2<<"\n";
                    }
                    else
                    {
                        cout<<(n/2)+1<<"\n";
                    }
                }
                else
                {
                    cout<<n/2<<"\n";
                }
            }
        }
    }
    return 0;
}
