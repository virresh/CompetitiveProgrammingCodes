#include <iostream>
#include <cstdio>
using namespace std;
int a[1000],len=0;
void clr()
{
    for(int i=0;i<1000;i++)
    {
        a[i]=1;
    }
    len=0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,m,temp,helper=0;
    cin>>t;
    while(t--)
    {
        clr(); helper=0;
        cin>>len>>m;
        for(int i=0;i<m;i++)
        {
            cin>>temp;
            a[temp-1]=0;
        }
        for(int j=0;j<len;j++)
        {
            if(a[j]==1)
            {
              if(helper==1){a[j]=2; helper--;}
              else {helper++;}
            }
        }
        for(int j=0;j<len;j++)
        {
            if(a[j]==1){cout<<j+1<<" ";}
        }
        cout<<"\n";
        for(int j=0;j<len;j++)
        {
            if(a[j]==2){cout<<j+1<<" ";}
        }
        cout<<"\n";
    }
    return 0;
}
