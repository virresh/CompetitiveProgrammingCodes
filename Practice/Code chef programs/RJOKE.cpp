#include <iostream>
using namespace std;
class point
{
    int x,y;
public:
    void in(){cin>>x>>y;}
};
int main()
{
    int t,n,y;
    cin>>t;
    while(t--)
    {
        cin>>n;
        point p;
        y=n;
        while(n--)
        {
            p.in();
            y=y^n;
        }
        cout<<y<<"\n";
    }
    return 0;
}
