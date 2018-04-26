#include <iostream>
using namespace std;
unsigned long long int npow(long a,int b)
{
    unsigned long long int p=1;
    int r=1;
    for (r<b;r<=b;)
          {
              p*=a;
              r=r+1;
          }
    return p;
}

int findpow(unsigned long long int num)
{
    int i=0;
    while(npow(2,i)<=num){i++;}
    return i-1;
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
    unsigned long long int p;
    cin>>p;
    int t,counter=0;
    while(p>0)
    {
              t=findpow(p); 
              if(t>=12){p-=npow(2,11); counter++;}
              else{p-=npow(2,t); counter++;}
    }
    cout<<counter<<"\n";
    }
    return 0;   
}
