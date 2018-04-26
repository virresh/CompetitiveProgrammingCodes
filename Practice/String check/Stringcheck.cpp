#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
void main()
{
    clrscr();
    cout<<"Enter a sentence(max. 30 words) :\n";
    char sen[30];
    gets (sen);
    int a=0,c,var1='a',var2='z',var3='A',var4='Z',var5='0',var6='9';
    int vowels=0,consonants=0,digits=0,otherc=0,spaces=0;
    for (a=0;sen[a]!='\0';a++)
    {
        c=sen[a];
       if (((c>=var1)&&(c<=var2))||((c>=var3)&&(c<=var4)))
       {
           if ((sen[a]=='a')||(sen[a]=='e')||(sen[a]=='i')||(sen[a]=='o')||(sen[a]=='u')||(sen[a]=='A')||(sen[a]=='E')||(sen[a]=='I')||(sen[a]=='O')||(sen[a]=='U'))
           {
               vowels+=1;
           }
           else
           {
               consonants+=1;
           }
       }
       else if ((c>=var5)&&(c<=var6))
       {
           digits+=1;
       }
       else if (c==32)
       {
           spaces+=1;
       }
       else
       {
           otherc+=1;
       }

    }
    int b=0,d,upperc=0,lowerc=0;
    for (b=0;sen[b]!='\0';b++)
    {
        d=sen[b];
        if ((d>=var1)&&(d<=var2))
        {
            lowerc+=1;
        }
        else if ((d>=var3)&&(d<=var4))
        {
            upperc+=1;
        }
    }
    cout<<"\nDigits : "<<digits<<"\nVowels : " <<vowels<<"\nConsonants : "<<consonants<<"\nSpaces : "<<spaces<<"\nOther characters : "<<otherc;
    cout<<"\nUpper case characters : "<<upperc<<"\nLower case characters : "<<lowerc;
    getch();
}
