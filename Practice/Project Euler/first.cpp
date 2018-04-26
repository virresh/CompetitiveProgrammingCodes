#include <iostream>
using namespace std;

int main()
{
    long int sum=0,sum1=0,sum2=0,sum3=0;
    for(int i=3;i<=1000;i+=3)
    {sum1+=i;}
    for(int j=5;j<=1000;j+=5)
    {sum2+=j;}
    for(int k=15;k<=1000;k+=15)
    {sum3+=k;}
    sum=sum1+sum2-sum3;
    cout<<"sum is "<<sum<<"\n"<<sum1<<"\n"<<sum2<<"\n"<<sum3<<"\n";
    system("pause");
    return 0;   
}
