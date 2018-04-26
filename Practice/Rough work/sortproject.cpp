#include <iostream.h>
#include <conio.h>
int a[100],n=0,flag=0;
void savea()
{
    cout<<"Enter the number of elements :\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"\n";
    return;
}
void printa()
{
    for(int k=0;k<n;k++)
    {
        cout<<a[k]<<" ";
    }
    cout<<"\n";
    return;
}
void isort()
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0&&key<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        printa();
    }
    cout<<"\nSorting Compelete\n";
}
void ssort()
{
    for(int k=0;k<n;k++)
    {
        int imin=k;
        for(int i=k;i<n;i++)
        {
            if(a[imin]>a[i]){imin=i;}
        }
        int temp=a[k];
        a[k]=a[imin];
        a[imin]=temp;
        printa();
    }
}
void bsort()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        printa();
    }
}
void main()
{
    char ch;
    do
    {
        clrscr();
        cout<<"What do you want to do?\n1.Enter/Modify elements\n2.Display elements\n3.Insertion sort\n4.Selection Sort\n5.Bubble sort\n";
        cin>>ch;
        switch(ch)
        {
            case '1' : savea(); flag=1; break;
            case '2' :if(flag==0){cout<<"Enter elements first..\n";}
                      else {printa();} break;
            case '3' :if(flag==0){cout<<"Enter elements first..\n";}
                      else {isort();} break;
            case '4' :if(flag==0){cout<<"Enter elements first..\n";}
                      else {ssort();}  break;
            case '5' :if(flag==0){cout<<"Enter elements first..\n";}
                      else {bsort();} break;
            default : cout<<"Wrong  Choice\n"; break;
        }
        cout<<"Do you want to continue (y/n) ?\n";
        cin>>ch;
    }while(ch!='n');
}
