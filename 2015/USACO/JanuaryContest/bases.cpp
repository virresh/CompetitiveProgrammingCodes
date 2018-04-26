#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
unsigned long long int x,y,i,n,m,z;
int x1,x2,x3,y1,y2,y3;
int main()
{
    freopen("whatbase.in","r",stdin);
    freopen("whatbase.out","w",stdout);
    int k,flag;
    scanf("%d\n",&k);
    while(k--)
    {
        scanf("%c%c%c %c%c%c\n",&x1,&x2,&x3,&y1,&y2,&y3);
        x1-=48; x2-=48; x3-=48; y1-=48; y2-=48; y3-=48;
        int ma[]={x1,x2,x3,y1,y2,y3};
        z=*max_element(ma,ma+6);
        if(x1*100+x2*10+x3 < y1*100+y2*10+y3)
        {
        for(i=z;i<15000;i++)
        {
            x=i; flag=0;
            for(y=0;y<=x;y++)
            {
                if(x1*x*x+x2*x+x3 == y1*y*y +y2*y+ y3)
                {
                    flag=1;
                    break;
                }
                //else cout<<x1*x*x<<"\n";
            }
            if(flag==1){break;}
        }
        }
        else
        {
            for(i=z;i<15000;i++)
        {
            y=i; flag=0;
            for(x=0;x<=y;x++)
            {
                if(x1*x*x+x2*x+x3 == y1*y*y +y2*y+y3)
                {
                    flag=1;
                    break;
                }
                //else cout<<x1*x*x<<"\n";
            }
            if(flag==1){break;}
        }
        }
        cout<<x<<" "<<y<<"\n";
    }
    return 0;
}
