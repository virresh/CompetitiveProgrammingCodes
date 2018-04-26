#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000005

vector <int> arr,a2;
int main()
{
    int m,n,i,x,j;
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>x;
        arr.push_back(x);
    }
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        x--;
        for(j=0;j<a2.size();j++)
        {
            if(a2[j]<=x){x++;}
        }
        cout<<arr[x]<<"\n";
        a2.push_back(x);
        sort(a2.begin(),a2.end());
    }
    return 0;
}
