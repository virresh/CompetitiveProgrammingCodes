#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100
ll v,sum;
int c,d[sz],s[sz];
int main()
{
    int t,nd,i,res,ns,pd;
    cin>>t;
    while(t--)
    {
        sum=0; ns=0; pd=0;
        scanf("%d %d %lld",&c,&nd,&v);
        for(i=0;i<nd;i++)
        {
            cin>>d[i];
        }
        sort(d,d+nd); i=1;
        while(sum<v)
        {
            if(sum<i)
            {
                if(d[pd]!=i)
                {

                    s[ns]=i; ns++;
                    sum = sum + i*c;
                }
                else
                {
                    s[ns]=d[pd]; ns++; pd++;
                    sum+= d[pd]*c;
                }
            }
            else{i++;}
        }
        cout<<ns-nd<<"\n";
    }
    return 0;
}
