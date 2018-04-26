#include <iostream>
#include <cstdio>
using namespace std;
class snt
{
    public:
    int words=0,len=0;
    char s[100];

    void tolower();
    void getblock(int &a);
    void print();
};
void snt::print()
{
    for(int i=0;i<=len;i++)
    { cout<<s[i]; }
    cout<<"\n";
}
void snt::tolower()
{
    int i;
    for(i=0;s[i]!='\0';i++)
    {
        if((s[i]>='A')&&(s[i]<='Z')){s[i]+=32;}
    }
}
void snt::getblock(int &a)
{
    for(;;)
    {
        if((s[a]<'a')||(s[a]>'z')||(a==len)){return;}
        a++;
    }
}
int main()
{
    snt a;
    char ch; int k=0;
    do
    {
        scanf("%c",&ch);
        if(ch!='\n')
        {a.s[k]=ch; k++;}
    }while(ch!='\n');
    a.len=k-1;
    a.tolower();
    a.print();
    cout<<a.len<<"\n";

    int l=0,m=0;
    for(;l<=a.len;l++)
    {
        if(m>=a.len){break;}
        a.getblock(m);
        for(int i=l;i<=m;i++)
        {
            cout<<a.s[i];
        }
        cout<<"\n";
        l=m;
        m++;
    }
    return 0;
}
