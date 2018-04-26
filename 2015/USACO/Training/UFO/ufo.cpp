/*
ID: virresh1
PROG: ride
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int f(char x){return x-'A'+1;}
int main()
{
    char s1[10],s2[10];
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    fin>>s1>>s2;
    int a=1,b=1,i;
    for(i=0;s1[i]!='\0';i++)
    {
        a=(a*f(s1[i]))%47 ;
    }
    for(i=0;s2[i]!='\0'; i++)
    {
        b=(b*f(s2[i]))%47;
    }
    if(a==b){fout<<"GO\n";}
    else
    {
        fout<<"STAY\n";
    }
    return 0;
}
