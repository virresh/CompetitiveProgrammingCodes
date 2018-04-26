#include <iostream>
#include <conio.h>
using namespace std;
unsigned long long int isprime(unsigned long long int num)
{
         unsigned long long int i=3,l=2;
         if((num%2==0)&&(num!=2)){return 2;}
         for(i=3;i<=num/l;i++)
         {
                              if(num%i==0){return i;}
                              else if(isprime(i)){l=i;} //recursion
         }
         return num;         
}

int main()
{
    unsigned long long int prev=1,curr=0,now;  //x=600851475143
    cout<<"\n\n\tEnter the number to be checked : \t";
    cin>>now;    
    cout<<"\tThe smallest divisor is (except 1) :\t"<<isprime(now)<<"\n";
    while(now>1)
    {
                curr=isprime(now);
                cout<<curr<<"\n";
                now/=curr;
    }
    _getch();
    return 0;
}
