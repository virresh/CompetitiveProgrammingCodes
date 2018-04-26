#include<iostream>
using namespace std;
unsigned long long int zerocounter(unsigned long long int num)
{
     unsigned long long int pw=5,zeroes=0;
     while(num>=pw)
     {
          zeroes+=num/pw;
          pw*=5;
     }
     return zeroes;
}
int main ()
{
    unsigned long long int t;
    cin>>t;
    while(t--)
    {
         unsigned long long int a;
         cin>>a;
         cout<<zerocounter(a)<<endl;
    }
    return 0;
}
