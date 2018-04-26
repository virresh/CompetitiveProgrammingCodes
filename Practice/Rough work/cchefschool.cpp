#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
char a[100000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unsigned long int i,j,flag=0;
        cin>>a;
        for(i=0;a[i]!='\0';i++)
        {}
        for(j=0;a[j]!='\0';j++)
        {
            if(a[j]!=a[i-j-1]){flag=1; break;}
        }
        if(flag==1){cout<<"2\n";}
        else{cout<<"1\n";}
    }
    return 0;
}
