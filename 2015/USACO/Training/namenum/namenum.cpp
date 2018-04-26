#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
ID: virresh1
PROG: namenum
LANG: C++
*/
char p(char c)
{
    switch (c)
    {
    case 'A':
    case 'B':
    case 'C': return '2';
    case 'D':
    case 'E':
    case 'F': return '3';
    case 'G':
    case 'H':
    case 'I': return '4';
    case 'J':
    case 'K':
    case 'L': return '5';
    case 'M':
    case 'N':
    case 'O': return '6';
    case 'P':
    case 'R':
    case 'S': return '7';
    case 'T':
    case 'U':
    case 'V': return '8';
    case 'W':
    case 'X':
    case 'Y': return '9';
    default : return '0';
    }
}
bool hashOf(string a,string b)
{
    if(b.length()!=a.length()){return false;}
    string y;
    for(int i=0;i<a.length(); i++)
    {
        y+=p(a[i]);
    }
    return (y.compare(b)==0)?1:0;
}
int main()
{
    string word,x;
    int i=0;
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream d("dict.txt");
    fin>>x;
    while(!d.eof())
    {
        d>>word;
        if(hashOf(word,x))
        {
            i=1;
            fout<<word<<"\n";
        }
    }
    if(i==0){fout<<"NONE\n";}
    return 0;
}
