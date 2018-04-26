#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("cowroute.in","r",stdin);
    freopen("cowroute.out","w",stdout);
    int t,c1,c2,currcost,ac1,ac2,x,result,bestcost=10001,n,flag=0;
    cin>>c1>>c2>>t;
    while(t--) //route description
    {
        result=0; flag=0; ac1=-1; ac2=-1;
        cin>>currcost>>n;
        for(int i=0;i<n;i++)    //path specification
        {
            cin>>x;
            if(x==c1){ac1=i;}
            else if(x==c2){ac2=i;}
        }
        if((ac1<ac2)&&(ac1!=-1)&&(ac2!=-1)){flag=1;}
        if(flag!=0 && currcost<bestcost){bestcost=currcost;}
    }
    if(bestcost==10001){cout<<"-1";}
    else {cout<<bestcost;}
    return 0;
}
