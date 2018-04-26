/* *******************************************************
   SUPER PROGRAM PROJECT BY VIRESH GUPTA FOR LEARNING
   PURPOSE ONLY.
******************************************************* */
#include <iostream>
#include <conio.h>
#include <cstdlib.h>
#include <windows.h>
#include <fstream.h>
#include <string.h>
#include <process.h>
#include "susupport.cpp"
using namespace std;
char name[100],pass[100];

void main()
{
    //********************Entry Animation****************///
    cout<<"\n\n\n\t\tLoading  ";
    for(int i=1;i<=14;i++)
    {
        if(i%5!=0){cout<<". "; Sleep(500);}
        else{ cout<<"\b\b\b\b\b\b\b\t\b\b\b\b\b\b\b"; Sleep(500);}

    }
    clrscr();
    cout<<"\n\n\n\n";
    cout<<"\t \\\\                //  \n";
    cout<<"\t  \\\\              //   \n";
    cout<<"\t   \\\\            //    \n";
    cout<<"\t    \\\\          //     \n";
    cout<<"\t     \\\\        //      \n";
    cout<<"\t      \\\\      //       \n";
    cout<<"\t       \\\\    //        \n";
    cout<<"\t        \\\\--//         \n";
    cout<<"\n\tWelcome To the Super Program ";
    Sleep(1000);
    clrscr();

    //***********************END OF ENTRY ANIMATION******************************//
    //*********************Password Management***********************************//
    clrscr();
    cout<<"Enter User Name :\t";
    int l=0;
    cin>>name;
    cout<<"Enter Password :\t";
    for(;;)
    {
        char n;
        n=getch();
        if((l!=0)&&(n=='\b')){cout<<"\b \b";l--;pass[l]='\0';}
        else if(n==32){break;}
        else if(n==13){break;}
        else if(n!='\b'){pass[l]=n; pass[l+1]='\0'; cout<<"*"; l++;}
    }
    if(strcmp(pass,"admin")==0){cout<<"\nWelcome "<<name<<".\n";Sleep(500);}
    else{cout<<"\nWrong Password Try later. Exitting..."; getch();exit(0);}
    /* ***************************   MAIN MENU   *********************************** */
menu:
    clrscr();
    cout<<"What do you want to do ?";
    cout<<"\n1. Go to Calculator\n2. Go for Database management\n";
    char ab;
    cin>>ab;
    switch(ab)
    {
        case '1':  goto calc;
        case '2': goto database;
        default : cout<<"Wrong choice"; getch(); goto menu;
    }

calc:
    clrscr();
    cout<<"Choose an option : \n0.Clear Result File\n1.Find Factorial\n2.Check for Prime Number\n3.Prime Factorize a number\n";
    cin>>ab;
    switch(ab)
    {
        case '0': goto clearres;
        case '1': goto findfactorial;
        case '2': goto checkprime;
        case '3': goto factorize;
        default : cout<<"Wrong choice. Returning to main menu."; getch(); goto menu;
    }


    /* *************************** Calculator Menu functions ******************************** */
clearres:
    remove("Result.txt");
    cout<<"\nFile Cleared\n";
    goto endofp;
findfactorial:
    clrscr();
    cout<<"Enter a number : ";
    int n;
    suarray number;
    cin>>n;
    number=factorial(n);
    number.printra(name);
    cout<<"\n\nDo You want to save this result ?  (n for no)\n";
    char ch;
    cin>>ch;
    if(ch=='y')
        {
            number.printra(name,n);
            cout<<"\nResult saved\n";
        }
    goto endofp;
checkprime:
    clrscr();
    cout<<"Enter a number : ";
    unsigned long int num;
    cin>>num;
    if(sdiv(num)==num){cout<<"Number is prime.\n";}
    else{cout<<"Number is not prime.\n";}
    goto endofp;
factorize:
    clrscr();
    cout<<"Enter a number :\n";
    unsigned long int numb,dup;
    cin>>numb;
    dup=numb;
    while(numb>1)
    {
        unsigned long int x=sdiv(numb);
        cout<<x<<" * ";
        numb/=x;
    }
    cout<<"1\nDo You Wish to save this result ?";
    cin>>ab;
    if(ab=='y')
    {
        fstream file1;
        file1.open("Result.txt",ios::app|ios::ate);
        file1<<"\n"<<dup<<" = ";
        while(dup>1)
        {
            unsigned long int y=sdiv(dup);
            file1<<y<<" * ";
            dup/=y;
        }
        file1<<"1\nSaved by "<<name<<"\n";
        file1.close();
    }
    goto endofp;
/* ****************   End of calculator Menu functions ********************* */
/* **************** Database Management **************************** */
database:
// To be built//

/* **************** End of Database manager ************************ */
endofp:
    cout<<"\n\nDo you  wish to continue ?\n";
    cin>>ch;
    if(ch=='y'){goto menu;}
}
