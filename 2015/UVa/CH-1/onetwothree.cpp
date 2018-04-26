#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    char a[]="one",b[]="two",c[10],ca,cb;
    int t;
    cin>>t;
    cin.ignore(1);
    for(int j=0;j<t;j++)
    {
        cin.getline(c,10);
        ca=cb=0;
        if(strlen(c)==5){cout<<"3\n";}
        else
        {
            for(int i=0;i<3;i++)
            {
                if(a[i]==c[i]){ca++;}
                else if(b[i]==c[i]){cb++;}
            }
            if(ca>=2){cout<<"1\n";}
            else if(cb>=2){cout<<"2\n";}
        }
    }
    return 0;
}
