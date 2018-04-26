#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 10005
/*
ID: virresh1
PROG: pprime
LANG: C++
*/
int PRIME[sz];
bool prime(long int i)
{
    long int j=1,k;
    if(i<sz)
    {
         if(PRIME[i]!=-1){return PRIME[i]==1 ? true: false;}
    }
    if((i!=2)&&(i%2==0)){return false;}
    for(k=3;k<=i/k;k+=2)
    {
            if(i%k==0){return false;}
    }
    if(i<sz){PRIME[i]=1;}
    for(long p=2*i;p<sz;p+=i)
    {
        PRIME[p]=0;
    }
    return true;
}
bool palindrome(long int x)
{
     long int r=0,original=x;
     for(;;)
     {
       r=(r*10)+(x%10);
       if(x/10==0){break;}
       x/=10;
     }
     if(r==original){return true;}
     else{return false;}
}
int main()
{
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    memset(PRIME,-1,sizeof(PRIME));
    PRIME[0]=0; PRIME[1]=0; PRIME[2]=1;
    int a,b;
    fin>>a>>b;
    for(;a<=b;)
    {
        if(palindrome(a))
        {
            //cout<<a<<"\n";
            if(prime(a))
            {
                fout<<a<<"\n";
            }
        }
        a++;
    }
    return 0;
}
