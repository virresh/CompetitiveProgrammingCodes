
#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
double npow(double a,int b)
{
    double p=1;
    int r=1;
    for (r<b;r<=b;)
          {
              p*=a;
              r=r+1;
          }
    return p;
}
double nrt(double z,int e)
{
    double x,y;
    x=0;
    y=0;
    for(; x<=z ; )
    {
        y=y+0.00001;
        x= npow(y,e);
    }
    return y;
}
int main()
{
    clrscr();
    cout<<"What do you want to do ?\n1. Find the nth power of a number\n2. Find the nth root of a number\n";
    int l,e;
    double number,res;
    l=getch();
    if (l=='1')
    {
        clrscr();
        cout<<"Enter the number :\t"; cin>>number;
        cout<<"\nEnter exponent :\t"; cin>>e;
        res=npow(number,e);
        cout<<"\n"<<number<<" raised to power "<<e<<" is "<<res;
        getch();
    }
    else if (l=='2')
    {
        clrscr();
        cout<<"Enter the number :\t"; cin>>number;
        cout<<"\nEnter base :\t"; cin>>e;
        res=nrt(number,e);
        cout<<"\n"<<e<<"th root of "<<number<<" is : "<<setprecision(5)<<res;
        getch();
    }
    else
    {
        cout<<"\nInvalid choice";
        getch();
    }
    getch();
}
