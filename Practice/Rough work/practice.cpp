#include <iostream.h>
#include <conio.h>

void main()
{
    char choice;
    do
    {
        clrscr();
        char ch;
        cout<<"What do you want to do ?\n1.Pyramid\n2.Hollow pyramid\n3.Prime number\n";
        cin>>ch;
        switch (ch)
        {
            case '1': goto pyramid;
            case '2': goto hpyramid;
            case '3': goto prime;
            default : goto ending;
        }

        pyramid:
            clrscr();
            cout<<"Enter the number of lines and the character to be used :\n";
            int n; char a;
            cin>>n>>a; clrscr();
            for(int i=1;i<=n;i++)
            {
                for(int j=n;j>=i;j--)
                {
                    cout<<" ";
                }
                for(int k=1;k<=i;k++)
                {
                    cout<<a<<" ";
                }
                cout<<"\n";
            }
            getch();
            goto ending;
        hpyramid:
            clrscr();
            cout<<"Enter the number of line and the character to be used :\n";
            int n2; char a2;
            cin>>n2>>a2;
            for(int i=1; i<=n2;i++)
            {
                for(int j=n2;j>=i;j--)
                {
                    cout<<" ";
                }
                for(int k=1;k<=i;k++)
                {
                    if(i==1){cout<<a2;}
                    else if(i==n2){cout<<a2<<" ";}
                    else if((k==1)||(k==i)){cout<<a2<<" ";}
                    else {cout<<"  ";}
                }
                cout<<"\n";
            }
            getch();
            goto ending;
        prime:
            clrscr();
            cout<<"Enter a number to check for prime :\n";
            unsigned long int num; cin>>num;
            if((num%2==0)&&(num!=2)){cout<<"\nNot a Prime\n"; getch(); goto ending;}
            for(unsigned long int x=3;x<num;x+=2)
            {
                if(x==num){break;}
                if(num%x==0){cout<<"\nNot a prime\n"; getch(); goto ending;}
            }
            cout<<"\nIt is a prime\n"; getch();
        ending:
            clrscr();
            cout<<"Do you want to continue ?\n";
            cin>>choice;
    }while (choice!='n');
    cout<<"Press any key to exit ";
    getch();
}
