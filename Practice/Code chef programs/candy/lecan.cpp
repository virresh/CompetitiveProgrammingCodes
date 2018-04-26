#include <iostream>

using namespace std;
int a[1000];
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
          int n,c,flag=0,sum=0;
          cin>>n>>c;
          for(int x=0;x<n;x++)
          {
                  cin>>a[x];
          }
          for(int y=0;y<n;y++)
          {
                  sum+=a[y];
          }
          if(sum>c){cout<<"No"<<"\n";}
          else{cout<<"Yes"<<"\n";}
    }
    return 0;
}
