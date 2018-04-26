#include <iostream>
#include <cstdio>
using namespace std;

int aw[102],capacity[102],pies=0,temp=0,track;

void save(int n[],int a)
{
     int x=0;
     while(a--)
     {
               cin>>n[x];
               x++;          
     }
     return;    
}

void print(int n[],int l)
{
     int x=0;
     while(l--)
     {
               cout<<n[x]<<" ";
               x++;
     }
     cout<<"\n";
     return;
}
int getlargest(int c[],int n)
{
    temp=0;
    while(n--)
    {
              if(c[n]>temp){temp=c[n]; track=n;}  
    }
    c[track]=0;
    return temp;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //cout<<"Enter number of test case: \n";
    int t; cin>>t;
    while(t--)
    {
              int n,t2;
              cin>>n;
              pies=0; t2=n;
              save(aw,n);
              save(capacity,n);
              while(t2--)
              {
                         int l1=getlargest(aw,n),l2=getlargest(capacity,n);
                         //print(aw,n);
                         //cout<<"\n";
                         //print (capacity,n);
                         if(l2>=l1){pies++;}
                         else
                         {
                             capacity[track]=temp;
                         }
                         
              }
              cout<<pies<<"\n";
    }

    return 0;   
    
}
