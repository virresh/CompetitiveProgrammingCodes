#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,in=0,fo=0;
        char ch[1002];
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ch[i];
            if(ch[i]=='I'){in++;}
            else if(ch[i]=='Y'){fo++;}
        }
        if(in>fo){cout<<"INDIAN\n";}
        else if(in<fo){cout<<"NOT INDIAN\n";}
        else if(fo==in){cout<<"NOT SURE\n";}
        else {cout<<"\n";}
    }
    return 0;
}
