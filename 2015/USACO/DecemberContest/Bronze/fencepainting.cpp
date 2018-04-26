#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ofstream fout ("paint.out");
    ifstream fin ("paint.in");
    int a,b,c,d,len;
    fin>>a>>b>>c>>d;
    if(c<=b && d>=a)
    {
        len=max(d,b)-min(a,c);
    }
    else
    {
        len=d-c+b-a;
    }
    fout<<len<<"\n";
    return 0;
}
