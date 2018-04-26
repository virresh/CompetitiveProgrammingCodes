#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 10003
char a[sz];

int main()
{
    int t,lside,rside,i,y;
    bool x;
    cin>>t;
    while(t--)
    {
        lside=rside=0;
        x=false;
        scanf("%s",a);
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='B')
            {
                if(x){lside++;}
                else {rside++;}
            }
            else
            {
                x=true;
            }
        }
        /*if((lside%2==0 && rside%2==0)||(lside%2!=0 && rside%2!=0))
        {
            cout<<"Chef\n";
        }
        else
        {
            cout<<"Aleksa\n";
        }*/
        if(lside==rside)
        {
            if(lside%2==0){cout<<"Chef\n";}
            else {cout<<"Aleksa\n";}
        }
        else
        {
            y=max(lside,rside);
            if(y%2==0)
            {
                cout<<"Chef\n";
            }
            else
            {
                cout<<"Aleksa\n";
            }
        }
    }
    return 0;
}
