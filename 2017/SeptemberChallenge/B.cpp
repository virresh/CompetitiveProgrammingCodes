#include <bits/stdc++.h>
using namespace std;

#define sz 100005

int a[sz];

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            a[i] = i+1;
        }
        for(int i=0; i<n; i+=2){
            if(i+1 < n){
                int t = a[i];
                a[i] = a[i+1];
                a[i+1]= t;
            }
        }
        if(n%2==1){
            int l = a[n-2];
            a[n-2] = a[n-1];
            a[n-1] = l;
        }
        for(int i=0; i<n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
