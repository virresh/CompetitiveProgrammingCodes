#include <iostream>
#include <cstdio>
using namespace std;
void isD(char *a)
{
    int flag=0;
    for(int i=1;a[i]!='\0';i++)
    {
        if(a[i]==a[i-1])
        {
            int j=1;
            while(a[i]==a[i-1]){i++; j++;}
            if(j>=7){cout<<"YES"; flag=1; break;}
        }
    }
    if(flag==0)
    cout<<"NO";
}
int main()
{
    char a[101];
    scanf("%s",a);
    isD(a);
    return 0;
}
