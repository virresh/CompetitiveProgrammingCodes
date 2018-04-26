#include <bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
    int i,n=2,ctr=1,flag=0;
    while(n!=0)
    {
        ctr=1; flag=0;
        stack <int> s;
        cin>>n; if(n==0){break;}
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;)
        {
            if(a[i]==ctr){ctr++; i++;}
            else if(s.empty()){s.push(a[i]); i++;}
            else if(s.top()==ctr)
            {
                s.pop(); ctr++;
            }
            else if(i<n){s.push(a[i]); i++;}
            else {flag=1; break;}
        }
        while(!s.empty())
        {
            if(s.top()==ctr)
            {s.pop(); ctr++;}
            else {flag=1; break;}
        }
        if(flag==1){cout<<"no\n";}
        else{cout<<"yes\n";}
    }
}
