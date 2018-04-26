#include <iostream>
using namespace std;
typedef long ll;
ll f(ll x)
{
    ll c=x,res=0;
    while(c>0){res+=c%10; c/=10;}
    if(res/10==0){return res;}
    else{return f(res);}
}
void printans(ll x)
{
    switch (x)
    {
         case 0: cout<<"red\n"; break;
         case 1: cout<<"blue\n"; break;
         case 2: cout<<"pink\n"; break;
         case 3: cout<<"white\n"; break;
         case 4: cout<<"black\n"; break;
         case 5: cout<<"violet\n"; break;
         case 6: cout<<"cyan\n"; break;
         case 7: cout<<"yellow\n"; break;
         case 8: cout<<"green\n"; break;
         case 9: cout<<"brown\n"; break;
         default : break;
    }
}
int main()
{
    ll n,t,a,result=0;
    cin>>t;
    while(t--)
    {
        result=0;
        cin>>n;
        while(n--)
        {
            cin>>a;
            if(f(a)>result){result=f(a);}
        }
        printans(result);

    }
    return 0;
}
