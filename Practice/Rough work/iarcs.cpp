#include <iostream>
#include <cstdio>
using namespace std;
class snt
{
    public:
    char s[2][100]; int len=0;
    void print();
    void printm();
    void markblocks();
    void tolower();
    void save();
    char getsmall(int &m);
    snt();
};
//***********************
int main()
{
    snt a;
    int m;
    a.save();
    a.tolower();
    a.markblocks();
    a.printm();
    for(int i=0;i<=a.len;i++)
    {
        if(a.s[1][i]==(char)(1)){cout<<a.s[0][i];}
        else {cout<<"\n";}
    }
    return 0;
}
//***********************
char snt::getsmall(int &m)
{
    char c=(char)(1);
    for(int i=0;i<=len;i++)
    {
        if(s[1][i]!=(char)(1)){ if(s[0][i-1]>c){c=s[0][i-1]; m=i;}}
    }
    return c;
}
void snt::save()
{
    int i;
    for(i=0;;i++)
    {
        char ch;
        scanf("%c",&ch);
        if(ch=='\n'){break;}
        s[0][i]=ch;
    }
    len=i-1;
    return;
}
snt::snt() //constructor
{
    for(int i=0;i<=99;i++)
    {s[1][i]=(char)(1);}
}
void snt::print()
{
    for(int i=0;i<=len;i++)
    {
        cout<<s[0][i];
    }
    cout<<"\n";
    return;
}
void snt::markblocks()
{
    int i;
    char m=(char)(48);
    for(i=0;i<=len;i++)
    {
        char ch1=s[0][i];
        if((ch1<'a')||(ch1>'z')){s[1][i]=m; m++;}
    }
    return;
}
void snt::tolower()
{
    for(int i=0;i<=len;i++)
    {
        char ch=s[0][i];
        if((ch>='A')&&(ch<='Z')){s[0][i]+=32;}
    }
    return;
}
void snt::printm()
{
    for(int i=0;i<=len;i++)
    {cout<<s[1][i];}
    cout<<"\n";
}
