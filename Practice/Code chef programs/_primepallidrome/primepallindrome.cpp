#include <iostream>
#include <cstdio>
using namespace std;
bool prime(unsigned long int i)
{
    long int j=1,k;
    while (j*j<=i)
    {j++;}
    if((i!=2)&&(i%2==0)){return false;}
    for(k=3;k<=j;k+=2)
    {
            if(i%k==0){return false;}
    }
    return true;
}
bool palindrome(unsigned long int x)
{
     unsigned long int r=0,original=x;
     for(;;)
     {
       r=(r*10)+(x%10);
       if(x/10==0){break;}
       x/=10;
     }
     if(r==original){return true;}
     else{return false;}
}
int main()
{
    //unsigned long int n;
    int n,b;
    scanf("%d %d",&n,&b);
    for(;n<b;)
    {
           if(palindrome(n))
           { if(prime(n))
             {
              printf("%d\n",n);
             }
           }
           n++;
    }
    return 0;
}


