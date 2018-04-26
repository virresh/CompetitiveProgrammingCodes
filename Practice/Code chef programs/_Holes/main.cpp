#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
int z,flag=0;
void getlen(char m[])
{    for(z=0; m[z]!='\0' ;z++);   }

int main()
{
    char stri[100];
    int t;
    cin>>t;
    for(int a=0;a<=t;a++)
    {
    int holes=0,i=0;
    gets(stri);
    getlen(stri);
    do
    { 
            if(stri[i]=='B'){holes+=2;}
            else if((stri[i]=='A')||(stri[i]=='D')||(stri[i]=='O')||(stri[i]=='P')||(stri[i]=='Q')||(stri[i]=='R'))
            {holes+=1;}
            i++;
    }while(i<=z);
    if(flag==0){flag++;}
    else {cout<<holes<<"\n";    }
    }
    return 0;
}
