#include <iostream.h>
#include <conio.h>
char c[]="o";
void s1(int n)
{
    for(int i=0;i<n/2;i++)
    {
        for(int k=0;k<i;k++)
        {
            cout<<" ";
        }
        for(int j=i;j<n;j++)
        {
            cout<<c<<" ";
        }
        cout<<"\n";
    }
    for(int i=n/2;i>=0;i--)
    {
        for(int k=0;k<i;k++)
        {
            cout<<" ";
        }
        for(int j=n;j>i;j--)
        {
            cout<<c<<" ";
        }
        cout<<"\n";
    }
}
void s2(int n) //   **************** Triangle **************** //
{
    for(int i=0;i<n;i++)
    {
        for(int j=n;j>i;j--){cout<<" ";}
        for(int k=0;k<i;k++){cout<<c<<" ";}
        cout<<"\n";
    }
}
void s3(int n) //****************** Hollow triangle*************//
{
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)
        {
        for(int j=n-1;j>i;j--){cout<<" ";}
        for(int k=0;k<=i-1;k++)
        {
            if((k==0)||(k==i-1)){cout<<c<<" ";}
            else{cout<<"  ";}
        }
        }
        else
        {
            for(int l=0;l<i;l++){cout<<c<<" ";}
        }
        cout<<"\n";
    }
}
void main()
{
    int n=10;
    s1(n);
    s2(n);
    s3(n);
}
