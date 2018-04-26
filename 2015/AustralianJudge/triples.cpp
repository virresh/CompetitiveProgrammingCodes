#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("tripin.txt","r",stdin);
    freopen("tripout.txt","w",stdout);
    vector<int> vi;
    int n,i,x;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x%3==0){vi.push_back(i);}
    }
    if(vi.empty()){cout<<"Nothing here!\n";}
    else
    {
        cout<<vi.size()<<"\n";
        for(i=0;i<vi.size();i++)
        {
            cout<<vi[i]<<" ";
        }
    }
    return 0;
}
