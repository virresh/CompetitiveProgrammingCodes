#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define ss 141
long powers[ss]={0};
bool isPyth(long a,long b,long &c)
{
    long x,y;
    x=a*a; y=b*b;
    if(sqrt(x+y)==(int)(sqrt(x+y))){c=sqrt(x+y); return true;}
    return false;
}
int main()
{
    long a=2,b=2,c=2;
        for(a=2;a<1000;a++)
        {
            for(b=a+1;b<1000;b++)
            {
//                if(a<ss)
//                {if(powers[a]==0){powers[a]=a*a;}}
//                if(b<ss)
//                {
//                    if(powers[b]==0){powers[b]=b*b;}
//                }
                if(isPyth(a,b,c)){if(a+b+c==1000){cout<<a<<" "<<b<<" "<<c<<" "<<a+b+c<<"\n";} if(a+b+c>1000){break;}}
            }
        }
        cout<<a<<" "<<b<<" "<<c<<" "<<a+b+c<<"\n";
    return 0;
}
