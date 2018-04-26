#include <iostream>
#include <algorithm>
using namespace std;
int numa[1000],len=0;
void toasc(char arr[])
{
     for(int i=0;arr[i]!='\0';i++)
     {
             numa[i]=(int)(arr[i]); len++;
     }
}
void toch(char arr[])
{
     for(int i=0;i<=len;i++)
     {
             arr[i]=(char)(numa[i]);
     }
}
int main()
{
    char s[5000];
    cin>>s;
    toasc(s);
    sort(numa,numa+len);
    toch(s);
    for(int i=0;i<=len;i++)
    { cout<<s[i];}
    cout<<"\n";
    system("pause");
}
