#include<iostream>
#include<cstdio>
using namespace std;
int a[100000],b[100000];
long long int n,i,depth=0,length=0,ap=0,bp=0,cp=0,pos1=0,pos2=0;
int main()
{
    //freopen("in.txt","r",stdin);
    cin>>n; int x;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(x==1)
        {
            a[ap]=x; ap++;
        }
        else
        {
            b[bp]=x; bp++;
        }
        if(ap>bp){length++;}
        else if((ap==bp)&&(cp<length))
            {
                cp=length+1; pos2=ap+bp-length; length=0;
            }
        else if(ap==bp){length=0;}
        if(ap-bp>depth){depth=ap-bp; pos1=ap+bp;}
    }
    cout<<depth<<" "<<pos1<<" "<<cp<<" "<<pos2<<" \n";
    return 0;
}
