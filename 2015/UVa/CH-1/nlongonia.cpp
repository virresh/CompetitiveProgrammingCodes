#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    int k,dx,dy,x,y,i;
    do
    {
        cin>>k;
        if(k==0){break;}
        cin>>dx>>dy;
        for(i=0;i<k;i++)
        {
            cin>>x>>y;
            if(x>dx && y>dy){cout<<"NE\n";}
            else if(x<dx && y>dy){cout<<"NO\n";}
            else if(x<dx && y<dy){cout<<"SO\n";}
            else if(x>dx && y<dy){cout<<"SE\n";}
            else {cout<<"divisa\n";}
        }
    }while(k!=0);
    return 0;
}
