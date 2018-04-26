#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
ID: virresh1
PROG: combo
LANG: C++
*/
int n;
struct lock{
    int num1,num2,num3;
    void print()
    {
        cerr<<num1<<" "<<num2<<" "<<num3<<"\n";
    }
}master,john;

bool validate(lock &a,lock &b)
{
    bool x,y,z;
    x=y=z=false;
    int diff1,diff2,diff3;
    diff1=max(a.num1,b.num1)-min(a.num1,b.num1);
    diff2=max(a.num2,b.num2)-min(a.num2,b.num2);
    diff3=max(a.num3,b.num3)-min(a.num3,b.num3);
    if(diff1 <=2 || diff1>= (n-2)){x=true;}
    if(diff2 <=2 || diff2>= (n-2)){y=true;}
    if(diff3 <=2 || diff3>= (n-2)){z=true;}
    if(x && y && z){return true;}
    return false;
}

int main()
{
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    int i,j,k,ans=0;
    fin>>n;
    fin>>john.num1>>john.num2>>john.num3;
    fin>>master.num1>>master.num2>>master.num3;
    lock x={2,2,3};
    //cerr<<validate(x,master)<<" "<<validate(x,john)<<"\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                x.num1=i;
                x.num2=j;
                x.num3=k;
                if(validate(x,master) || validate(x,john))
                {
                    //x.print();
                    ans++;
                }
            }
        }
    }
    fout<<ans<<"\n";
    return 0;
}
