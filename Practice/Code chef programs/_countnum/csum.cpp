#include <iostream>
//#include <cstdio>
using namespace std;
unsigned long int a[100];

int getf(int i)
{
    int l=0,freq=0,track;
    for(;l<=i;l++)
    {
                  if(a[l]==a[i]){freq+=1;}
    }
    return freq;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
              int n,l=0,v,c=0;
              cin>>n;
              while(n--)
              {cin>>a[l]; l++;}
              for(int j=0;j<=l-1;j++)
              { 
                      int x=getf(j);
                      if((x>c)||((x==c)&&(a[j]<v))){c=x;v=a[j];}
              }
              cout<<v<<" "<<c<<"\n";
    }
    return 0;   
}
