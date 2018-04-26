#include <iostream.h>
#include <conio.h>
char* menu_items[] = {"Item 1","Item 2","Item 3","This is useless"};
int n=4;
int main()
{
    char ch; int current=0;
    window(10,5,50,11);
    textbackground(7);
    clrscr();
    _setcursortype(_NOCURSOR);
    while(ch!=13)
    {
        clrscr();
        for(int i=0;i<n;i++)
        {
            textcolor(4);
            gotoxy(5,i+3);
            if(i==current){textcolor(3);}
            cprintf("         ");
            cprintf("%d  %s",i+1,menu_items[i]);
        }
        ch=getch();
        if(ch==0)
        {
            ch=getch();
            if(ch==80)
            {
                current++;
                if(current==n){current =0;}
            }
            else if(ch==72)
            {
                current--;
                if(current==-1){current=n-1;}
            }
        }
    }
}
