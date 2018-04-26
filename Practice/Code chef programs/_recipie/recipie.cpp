#include <iostream>
using namespace std;
int a[60];
int main()
{
    a[0]=1004;
    int t;
    cin>>t;
    while(t--)
    {
              int n,smallest,track,gcd,flag=0;
              cin>>n;
              for(int i=1; i<=n;i++)
              { cin>>a[i]; if(a[i]<a[i-1]){smallest=a[i]; track=i;}}
              for(int i=smallest;i>=1;i--)
              { 
                      flag=0;
                      for(int j=1;j<=n;j++)
                      { if(a[j]%i==0){flag+=1;} }
                      if(flag==n){gcd=i; break;}
              }
              for(int k=1;k<=n;k++)
              {
                      cout<<a[k]/gcd<<" ";
              }
              cout<<"\n";
    }
    return 0;
}
