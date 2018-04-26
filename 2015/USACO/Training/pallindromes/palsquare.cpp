#include <bits/stdc++.h>
using namespace std;
/*
ID: virresh1
PROG: palsquare
LANG: C++
*/
char getX(int n)
{
    switch(n)
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
        case 10: return 'A';
        case 11: return 'B';
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
        case 16: return 'G';
        case 17: return 'H';
        case 18: return 'I';
        case 19: return 'J';
        case 20: return 'K';
        case 21: return 'L';
        case 22: return 'M';
        case 23: return 'N';
        case 24: return 'O';
        case 25: return 'P';
        case 26: return 'Q';
        case 27: return 'R';
        case 28: return 'S';
        case 29: return 'T';
        case 30: return 'U';
        case 31: return 'V';
        case 32: return 'W';
        case 33: return 'X';
        case 34: return 'Y';
        case 35: return 'Z';
        default : return '*';
    }
}
int num[25],numinit[25];
void print(int *x,int n)
{
    for(int j=n-1; j>=0;j--)
    {
        cout<<getX(x[j]);
    }
}
bool isPallin(int b,int n,int &i,int &k)
{
    int sqr=n*n,t=n;
    for(k=0;t>0;k++)
    {
        numinit[k]=t%b; t/=b;
    }
    for(i=0; sqr>0;i++)
    {
        num[i]=sqr%b; sqr/=b;
    }
    for(int j=i-1; j>=i/2;j--)
    {
        if(num[j]!=num[i-1-j]){return false;}
    }
    cerr<<i<<"\n";
    return true;
}
void printinb(int b)
{
    cerr<<"Program Started\n";
    int n,in,ib,i;
    for(i=1;i<=300;i++)
    {
        if(isPallin(b,i,ib,in))
        {
            print(numinit,in); cout<<" "; print(num,ib);
            cout<<"\n";
        }
    }
}
int main()
{
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    int x;
    cin>>x;
    printinb(x);
    return 0;
}
