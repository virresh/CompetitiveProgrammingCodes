#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
ID: virresh1
PROG: frac1
LANG: C++
*/
bool table[170][170];
void reduce(int &x,int &y)
{
    int z=1;
    if(y!=0){z=__gcd(x,y);}
    x/=z;
    y/=z;
}
struct fraction{
    int num,den;
    fraction (int u=0,int d=1)
    {
        int y=1;
        if(d!=0)
        {
            y=__gcd(u,d);
        }
        u/=y;
        d/=y;
        num=u; den=d;
    }
    bool operator <(fraction const &f)const
    {
        return ((num*f.den)<(den * f.num));
    }
    bool operator ==(fraction const &f)const
    {
        if((num!=f.num)&&(den!=f.den)){return false;}
        return true;
    }
    friend ostream& operator <<(ostream &a,const fraction &f)
    {
        a<<f.num<<"/"<<f.den;
        return a;
    }
    void show()
    {
        cout<<num<<"/"<<den<<" ";
    }
};
int n;
set<fraction> s;
set<fraction>::iterator it;
void solve(int u,int d)
{
    //cout<<u<<" "<<d<<"\n";
    int a=u,b=d;
    if(d>n){return;}
    if(u>d){return;}
    if(table[u][d]){return;}
    else
    {
        table[u][d]=true;
    }
    fraction f1(u,d);
        s.insert(f1);
        //cerr<<f1<<" ";
    solve(u+1,d);
    solve(u,d+1);
    solve(u+1,d+1);
    //if(u==7){cerr<<u<<d<<"\n";}
}
int main()
{
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    memset(table,false,sizeof(table));
    cin>>n;
    solve(0,1);
    for(it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<"\n";
    }
    return 0;
}
