#include <iostream>
using namespace std;
int a[200],len=0;
/*int lon(int x)
{
    int b=x,c=0;
    for(int i=10; b%i>=0 ;c++)
    { b/=10;}
    return c;
}*/
void savea(int x) //save number to an array
{
     int i=0;
     for(i=0;;i++)
     {
      a[i]=x%10; x/=10;
      if(x==0){break;}
     }
     len=i;
     
}
void printa()  //print an array straightforward
{
     int i=0;
     for(i=0;i<=len;i++)
     {cout<<a[i]<<"  ";}
}
void multiply(int num2)  //multiply within the array
{
     int carryover=0,j=0,b=0;
     for(j=0;j<=len;j++)
     {
                       b=(a[j]*num2)+carryover ;
                       a[j]=b%10;
                       carryover=b/10;
     }
     //for(j+=1;carryover>0;++j)
     while(carryover)
     {
                     a[j]=carryover%10; 
                     carryover/=10; 
                     len++;
                     j++;
     }
}
void printra() //Print reversed array
{
     int test=len;
     for(;test>=0;test--)
     {cout<<a[test];}
     cout<<"\n";
}
int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
    int num1;
    cin>>num1;
    savea(num1);
    while (--num1)
    {
      multiply(num1);
      if(num1==1){break;}
    }
    printra();
   }
    return 0;    
}
