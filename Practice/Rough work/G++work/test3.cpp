#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
int getlen(char m[200])
{
    int z;
    for(z=0; m[z]!='\0' ;z++);
    return z;
}

int main()
{
    char stri[100];
    int t;
    cin>>t;
    for(int a=0;a<=t;a++)
    {
    int holes=0;
    gets(stri);
    int z=getlen(stri);
    for(int i=0;i<=z ; i++)
    {
            if(stri[i]=='B'){holes+=2;}
            else if((stri[i]=='A')||(stri[i]=='D')||(stri[i]=='O')||(stri[i]=='P')||(stri[i]=='Q')||(stri[i]=='R'))
            {holes+=1;}
    }
    cout<<holes<<"\n";
    }
    return 0;
}
