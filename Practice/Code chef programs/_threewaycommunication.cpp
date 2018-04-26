#include <iostream>
using namespace std;
typedef long long ll;

class point{
public:
    ll x,y;
    point()
    {
        x=0; y=0;
    }
    point(ll a,ll b)
    {
        x=a; y=b;
    }
    bool inRange(ll r,point c)
    {
        ll d;
        d= (x-(c.x))*(x-(c.x)) + (y-(c.y))*(y-(c.y));
        if(d<= r*r){return true;}
        else {return false;}
    }
    void pointin(){cin>>x; cin>>y;}

};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll r;
        point p1,p2,p3;
        cin>>r;
        p1.pointin();
        p2.pointin();
        p3.pointin();
        int i=0;
        if(p1.inRange(r,p2)){i++;}
        if(p2.inRange(r,p3)){i++;}
        if(p3.inRange(r,p1)){i++;}
        if(i>=2){cout<<"yes\n";}
        else {cout<<"no\n";}
    }
}
