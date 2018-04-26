#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long a,b,c,total,sit,stand;
    freopen("sitin.txt","r",stdin);
    freopen("sitout.txt","w",stdout);
    cin>>a>>b>>c;
    total=a*b;
    if(c<=total){sit =c; stand =0;}
    else
    {
        sit=total; stand= c-total;
    }
    cout<<sit<<" "<<stand;
    return 0;
}
