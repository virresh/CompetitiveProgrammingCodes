#include <iostream>
#include <cstdio>
using namespace std;
#define asize 100000
typedef long long ll;
char itoa(int i);
int atoi (char i);
void nextpallin();
char a[asize]={'0'}; ll n=0;
int main()
{
    int t;
    char ch;
    cin>>t;
    cin.get(ch);
    while(t--)
    {
        ll i=0;
        for(i=0;i<asize;i++)
        {
            cin.get(ch);
            if(ch=='\n'){a[i]='\0'; n=i; break;}
            else {a[i]=ch;}
        }
        nextpallin();
        puts(a);
    }
    return 0;
}
char itoa(int i)
{
    switch (i)
    {
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        default : return '0';
    }
}
int atoi (char i)
{
    switch (i)
    {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default : return 0;
    }
}

void nextpallin()
{
    for(ll j=0;j<n/2;j++)
    {
        if(a[j]==a[n-1-j]){}
        else if(atoi(a[j])>atoi(a[n-1-j])){a[n-1-j]=a[j];}
        else if(atoi(a[j])<atoi(a[n-1-j])){a[n-1-j]=a[j]; a[n-2-j]=itoa(atoi(a[n-2-j]+1));}
    }
}
