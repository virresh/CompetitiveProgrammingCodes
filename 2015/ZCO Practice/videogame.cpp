#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100002

vector <ll> a;
/* Crane Manual
    1 : Move left
    2 : Move right
    3 : Pick up box
    4 : Drop box
    0 : Quit
*/
int main()
{
    ll n,h,i,x,c=0,busy=0;
    cin>>n>>h;
    for(i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    x=1;  //any random value;
    while(x!=0)
    {
        cin>>x;
        switch(x)
        {
        case 1:     if(c==0){}
                    else {c--;}
                    break;

        case 2:     if(c==n-1){}
                    else {c++;}
                    break;

        case 3:     if(a[c]==0 || busy==1){}
                    else{a[c]--; busy=1;}
                    break;

        case 4:     if(a[c]==h || busy==0){}
                    else{a[c]++; busy=0;}
                    break;

        case 0:     break;
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
