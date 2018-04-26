#include <iostream>
#include <cstdio>
using namespace std;
int arr[100000];
unsigned long int rdis(int x1,int y1,int x2,int y2)
{
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
bool isright(int x1,int x2,int x3,int y1,int y2,int y3)
{
    unsigned long int d1,d2,d3;
    d1=rdis(x1,y1,x2,y2);
    d2=rdis(x2,y2,x3,y3);
    d3=rdis(x1,y1,x3,y3);
    if((d1>d2)&&(d1>d3)){if (d1==d2+d3){return true;}}
    else if((d2>d1)&&(d2>d3)){if(d2==d1+d3){return true;}}
    else if ((d3>d1)&&(d3>d2)){if(d3==d1+d2){return true;}}
    return false;
}
int main()
{
    freopen("in.txt","r",stdin);
    int t,n=0;
    cin>>t;
    while(t--)
    {
        int x1,x2,x3,y1,y2,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        if(isright(x1,x2,x3,y1,y2,y3)){n++;}
    }
    cout<<n;
    return 0;
}
