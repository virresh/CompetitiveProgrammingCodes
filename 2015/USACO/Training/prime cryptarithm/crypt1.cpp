#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
ID: virresh1
PROG: crypt1
LANG: C++
*/
set <int> digit;
set<int>::iterator it;
bool isValid(int x)
{
    int temp=x;
    while(temp>0)
    {
        it=digit.find(temp%10);
        if(!(it!=digit.end()))
        {
            return false;
        }
        temp/=10;
    }
    //cout<<x<<"\n";
    return true;
}
int main()
{
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    int num1,num2,product,i,j,n,ans=0;
    fin>>n;
    for(i=0;i<n;i++)
    {
        fin>>j;
        digit.insert(j);
    }
    for(i=100;i<=999;i++)
    {
        for(j=10;j<=99;j++)
        {
            if(((i*(j%10))/1000 ==0 && (i *((j/10)%10))/1000 ==0)&&((i*(j%10))/99)>0 && (i *((j/10)%10))/99 >0)
            {
                if(isValid((i*(j%10)))&& isValid(i*((j/10)%10)))
                {
                    num1=i; num2=j; product= num1*num2;
                    if(isValid(num1)&& isValid(num2)&&isValid(product))
                    {
                        ans++;
                    }
                }
            }
        }
    }
    fout<<ans<<"\n";
    return 0;
}
