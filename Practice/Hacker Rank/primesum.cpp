#include <iostream>

using namespace std;
unsigned long long int no[300];
 bool prime(unsigned long long int i)
{
    unsigned long long int j=1,k;
    while (j*j<=i)
    {j++;}
    if((i!=2)&&(i%2==0)){return false;}
    for(k=3;k<=j;k+=2)
    {
            if(i%k==0){return false;}
    }
    return true;
}
int getlargest(int n)
{
    int temp=0;
    while(n--)
    {
              if(no[n]>temp){temp=no[n];}  
    }
    return temp;
}
int main() 
{

    unsigned long long int n,sum=2,flag=0,i,l=0;
    cin>>n;
    for(i=3;i<=n;i+=2)
        {
            if(prime(i)){sum+=i;flag++;}
            if(prime(sum)&&sum<=n){no[l]=sum ; l++;}
            if(sum>n){break;}
        }
    
    cout<<getlargest(l)<<" "<<flag<<"\n";
    system("pause");
    return 0;
}
