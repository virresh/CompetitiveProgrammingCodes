#include <iostream>
#include <cstdio>
using namespace std;
void execute(int &x,char *a)
{
    int add=0,sub=0;
    for(int i=0;i<=2;i++)
    {
        if(a[i]=='+'){add++;}
        if(a[i]=='-'){sub++;}
    }
    if(add==2)
    {
        x++;
    }
    else if(sub==2)
    {
        x--;
    }
}
int main()
{
    int t,x=0;
    char a[4];
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%s",a);
        execute(x,a);
    }
    cout<<x<<"\n";
    return 0;
}
