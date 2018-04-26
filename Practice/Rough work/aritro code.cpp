#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
    string menu[3]={"Start","Options","Exit"};
    int pointer=0;
    while (true)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        cout<<"*************************MAIN MENU***********************************"<<endl<<endl;

        for(int i=0;i<3;i++)
        {
            if(i==pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                cout<<menu[i]<<endl;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                cout<<menu[i]<<endl;
            }
        }
        while (true)
        {
            if(GetAsyncKeyState(VK_UP)!=0)
            {
                pointer-=1;
                if(pointer==-1)
                    pointer=2;
                break;
            }
            else if(GetAsyncKeyState(VK_DOWN)!=0)
            {
                pointer+=1;
                if(pointer==3)
                    pointer=0;
                break;
            }
            else if(GetAsyncKeyState(VK_RETURN)!=0)
            {
                cout<<"I havent built the insides yet!"<<endl;
                Sleep(1000);
            }
        }
        Sleep(150);
    }

}
