#include <iostream>
#include <cstdio>
using namespace std;
long long int i,m,n,temp,j,sum=0;
class rack
{
public:
    long long int a[2][1000000],len;
    void getele(long long int m);
    rack();
    void disp();
}r1;
rack::rack()
{
    for(i=0;i<1000000;i++){a[1][i]=0;}
}

void rack::getele(long long int m)
{
    for(i=0;i<m;i++)
    {
        scanf("%lld",&a[0][i]);
        a[1][i]=1;
    }
    len=m;
}
void rack::disp()
{
    for(i=0;i<len;i++){printf("%lld ",a[0][i]);}
}
int main()
{
    scanf("%lld\n",&m);
    r1.getele(m);
    scanf("%lld\n",&n);
    for(i=0;i<n;i++)
    {
        sum=0;
        scanf("%lld",&temp);
        for(j=0;sum!=temp;j++)
        {
            sum+=r1.a[1][j];
        }
        r1.a[1][j-1]=0;
        printf("%lld \n",r1.a[0][j-1]);
    }
    return 0;
}
