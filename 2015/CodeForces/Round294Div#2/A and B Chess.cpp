#include <iostream>
using namespace std;
int getwt(char a)
{
    switch (a)
    {
    case 'Q':
    case 'q': return 9;
    case 'B':
    case 'b': return 3;
    case 'R':
    case 'r': return 5;
    case 'n':
    case 'N': return 3;
    case 'P':
    case 'p': return 1;
    default : return 0;
    }
}
int main()
{
    char ch=' ';
    int wta=0,wtb=0;
    for(int i=0;i<64;i++)
    {
        cin>>ch;
        if(ch!='.' &&  ch!='k' && ch!='K')
        {
            if(ch>='A'&& ch<='Z')
            {
                wta+=getwt(ch);
            }
            else if(ch>='a'&& ch<='z')
            {
                wtb+=getwt(ch);
            }
        }
    }
    if(wta>wtb){cout<<"White\n";}
    else if(wta<wtb){cout<<"Black\n";}
    else{cout<<"Draw\n";}
    return 0;
}
