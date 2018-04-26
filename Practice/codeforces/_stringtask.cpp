#include <iostream>
#include <cstdio>
using namespace std;
bool isVowel(char a)
{
    switch (a)
    {
    case 'Y':
    case 'y':
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':return true;
    default: return false;
    }
}
int main()
{
    char a[102],res[204];
    scanf("%s",a);
    int i=0,j=0;
    for(i=0;a[i]!='\0';i++)
    {
        if(isVowel(a[i]))
        {}
        else if(isalpha(a[i]))
        {
            res[j]='.'; j++;
            if(a[i]>='A'&&a[i]<='Z')
            {
                a[i]=a[i]+'a'-'A';
            }
            res[j]=a[i];
            j++;
        }
        else{res[j]=a[i]; j++;}
    }
    res[j]='\0';
    printf("%s",res);
    return 0;
}
