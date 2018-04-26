#include <iostream>
#include <cstdio>
using namespace std;
unsigned long long int a[100002],inv[100002],l;
/*void printra(unsigned long int arr[],unsigned long int l) //Print reversed array
{
     int test=1;
     for(;test<=l;test++)
     {cout<<arr[test];}
     cout<<"\n";
}
unsigned long long int searche(unsigned long long int num)
{
         for(unsigned long long int i=0;i<=l;i++)
         { if(a[i]==num){return i;}}
}*/
void amb()
{
     for(unsigned long long int i=1;i<=l;i++)
     {
             if(inv[i]!=a[i]){cout<<"not ambiguous"<<"\n"; return;}
     }   
     cout<<"ambiguous"<<"\n";
     return;
}
int  main()
{
     freopen("in.txt","r",stdin);
     freopen("out.txt","w",stdout);
     while(1)
     {
           unsigned long long int i=0,n,t;
           scanf("%llu",&n); 
           if(n==0){break;}
           l=n;
           for(t=1;t<=n;t++)
           {scanf("%llu ",&a[t]);}
           for(i=1;i<=n;i++)
           {inv[a[i]]=i;}      
           amb();      
     }
     return 0;  
}
