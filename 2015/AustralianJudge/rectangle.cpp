#include <cstdio>
#include <iostream>
using namespace std;
class rectangle
{
public:
    long botlx,botly,toprx,topry,area;
    void input()
    {
        cin>>botlx>>botly>>toprx>>topry;
    }
    void calcarea()
    {
        if(botlx<toprx && topry>botly)
        {area=(toprx-botlx)*(topry-botly);}
        else {area =0;}
    }
    void cintersect(rectangle r1,rectangle &r2)
    {
        if(r1.toprx< toprx){r2.toprx=r1.toprx;}
        else r2.toprx=toprx;
        if(r1.topry<topry){r2.topry=r1.topry;}
        else r2.topry=topry;

        if(r1.botlx> botlx){r2.botlx=r1.botlx;}
        else r2.botlx=botlx;
        if(r1.botly>botly){r2.botly=r1.botly;}
        else r2.botly=botly;

        if(r2.validate()){r2.calcarea();}
        else{r2.area=0;}
    }
    bool validate()
    {
        if(toprx>botlx && topry>botly){return true;}
        return false;
    }
    void out()
    {
        cout<<"("<<botlx<<","<<botly<<")"<<"  "<<"("<<toprx<<","<<topry<<")\n";
    }
};
int main()
{
    freopen("bendin.txt","r",stdin);
    freopen("bendout.txt","w",stdout);
    rectangle r1,r2,r3;
    r1.input(); r1.calcarea();
    r2.input(); r2.calcarea();
    r1.cintersect(r2,r3);
    cout<<r1.area+r2.area-r3.area<<"\n";
    return 0;
}
