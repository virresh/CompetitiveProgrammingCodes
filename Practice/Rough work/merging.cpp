#include <iostream.h>
#include <conio.h>
void printa(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
int* mix(int *a,int la,int *b,int lb)
{
    int lc=la+lb,fp=0,bp=lc-1;
    static int c[200];
    for(int i=0;i<la;i++)
    {
        if(a[i]%2==0){c[fp]=a[i]; fp++;}
        else {c[bp]=a[i]; bp--;}
    }
    for(int j=0;j<lb;j++)
    {
        if(b[j]%2==0){c[fp]=b[j]; fp++;}
        else{c[bp]=b[j]; bp--;}
    }
    return c;
}
void main()
{
    clrscr();
    cout<<"Enter 1st array's length then elements :\n";
    int a[100],b[100],la,lb;
    int *c;
    cin>>la;
    for(int i=0;i<la;i++)
    { cin>>a[i];}
    cout<<"Enter 2nd array's length then elements :\n";
    cin>>lb;
    for(int i=0;i<lb;i++)
    { cin>>b[i];}
    c=mix(a,la,b,lb);
    for(int m=0;m<la+lb;m++)
    {
        cout<<*(c+m)<<" ";
    }
    getch();
}
