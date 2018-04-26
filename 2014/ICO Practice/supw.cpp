#include<iostream>
using namespace std;

long long int a[200010],curr=0,len=0,i=0,j,day=0,minutes=0,temp=0,x;
int main()
{
    cin>>len;
    for(i=0;i<len;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<len;i+=2)
    {
        temp=a[i+2]; x=2;
        for(j=i;j<=i+2;j++)
        {
            if(a[j]<temp){temp=a[j]; x=i-j;}
        }
        minutes+=temp;
        cout<<"loop\n";
    }
    cout<<minutes<<"\n";
    return 0;
}
