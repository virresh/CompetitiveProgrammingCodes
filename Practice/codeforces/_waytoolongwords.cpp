#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char a[102],abbv[13];
        int tmp[10];
        scanf("%s",a);
        int i=0,j=0,k=0,n;
        for(i=0;a[i]!='\0';i++);
        n=i;
        if(i>10)
        {
            i-=2;
            abbv[0]=a[0]; j=0;
            while(i>0)
            {
                tmp[j]=i%10+48;
                i/=10;
                j++;
            }
            for(k=1;k<=j;k++)
            {
                abbv[k]=tmp[j-k];
            }
            abbv[k]=a[n-1];
            abbv[k+1]='\0';
            printf("%s\n",abbv);
        }
        else{printf("%s\n",a);}
    }
    return 0;
}
