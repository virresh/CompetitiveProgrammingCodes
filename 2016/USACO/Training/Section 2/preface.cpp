#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
ID: virresh1
PROG: preface
LANG: C++
*/

/*
    I- 1   L- 50     M- 1000
    V- 5   C- 100
    X- 10  D- 500
*/
int c[7+2]={0};
string ToRoman(int n)
{
    if(n==0){return "";}
    else if(n<10)
    {
        if(n==1){return "I";}
        if(n==2){return "II";}
        if(n==3){return "III";}
        if(n==4){return "IV";}
        if(n==5){return "V";}
        if(n==6){return "VI";}
        if(n==7){return "VII";}
        if(n==8){return "VIII";}
        if(n==9){return "IX";}
    }
    else if(n<100)
    {
        if(n/10==1){return "X"+ToRoman(n%10);}
        if(n/10==2){return "XX"+ToRoman(n%10);}
        if(n/10==3){return "XXX"+ToRoman(n%10);}
        if(n/10==4){return "XL"+ToRoman(n%10);}
        if(n/10==5){return "L"+ToRoman(n%10);}
        if(n/10==6){return "LX"+ToRoman(n%10);}
        if(n/10==7){return "LXX"+ToRoman(n%10);}
        if(n/10==8){return "LXXX"+ToRoman(n%10);}
        if(n/10==9){return "XC"+ToRoman(n%10);}
    }
    else if(n<1000)
    {
        if(n/100==1){return "C"+ToRoman(n%100);}
        if(n/100==2){return "CC"+ToRoman(n%100);}
        if(n/100==3){return "CCC"+ToRoman(n%100);}
        if(n/100==4){return "CD"+ToRoman(n%100);}
        if(n/100==5){return "D"+ToRoman(n%100);}
        if(n/100==6){return "DC"+ToRoman(n%100);}
        if(n/100==7){return "DCC"+ToRoman(n%100);}
        if(n/100==8){return "DCCC"+ToRoman(n%100);}
        if(n/100==9){return "CM"+ToRoman(n%100);}
    }
    else if(n<10000)
    {
        if(n/1000==1){return "M"+ToRoman(n%1000);}
        if(n/1000==2){return "MM"+ToRoman(n%1000);}
        if(n/1000==3){return "MMM"+ToRoman(n%1000);}
    }
    return "";
}

int func(char a)
{
    switch(a)
    {
    case 'I': return 0;
    case 'V': return 1;
    case 'X': return 2;
    case 'L': return 3;
    case 'C': return 4;
    case 'D': return 5;
    case 'M': return 6;
    default : return 7;
    }
}
char func2(int i)
{
    switch(i)
    {
        case 0: return 'I';
        case 1: return 'V';
        case 2: return 'X';
        case 3: return 'L';
        case 4: return 'C';
        case 5: return 'D';
        case 6: return 'M';
        case 7: return '-';
    }
}
void calculate (int n)
{
    string r=ToRoman(n);
    for(int i=0;i<r.length();i++)
    {
        c[func(r[i])]++;
    }
}

int main()
{
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        calculate(i);
    }
    for(int i=0;i<7;i++)
    {
        if(c[i])
            cout<<func2(i)<<" "<<c[i]<<"\n";
    }
    return 0;
}
