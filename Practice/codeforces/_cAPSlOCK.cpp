#include <iostream>
#include <cstdio>
using namespace std;
bool isUpper(char a)
{
    if(a>='A' && a<='Z')
        {return true;}
    return false;
}
bool isLower(char a)
{
    if(a>='a' && a<='z')
        {return true;}
    return false;
}
void applycaps(char *a)
{
    for(int i=0; a[i]!='\0';i++)
    {
        if(isLower(a[i]))
        {
            a[i]=a[i]-('a'-'A');
        }
        else if(isUpper(a[i]))
        {
            a[i]=a[i]+('a'-'A');
        }
    }
}
int main()
{
    char a[101];
    scanf("%s",a);
    bool cond2=true;
    for(int i=1;a[i]!='\0';i++)
    {
        if(isLower(a[i])){cond2=false; break;}
    }
    if(cond2==true){applycaps(a);}
    printf("%s \n",a);
    return 0;
}
