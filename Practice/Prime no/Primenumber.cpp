#include <iostream.h>
#include <conio.h>
void main()
{
    clrscr();
    cout<<"Enter a number : ";
    int a,b=0; cin>>a;
    cout<<"The number is divisible by : 1\n";
    for(int i=2;i<a;i++)
    {
        if(a%i==0)
        {
            b+=1;
            cout<<"The number is divisible by : "<<i<<"\n";
        }
    }
    cout<<"The number is divisible by : "<<a<<"\n";
    if (b>0)
    {
        cout<<"The number is divisible by "<< 2+b <<" numbers.";
    }
    else if(b==0)
    {
        cout<<"The number is prime.";
    }
    getch();
}
