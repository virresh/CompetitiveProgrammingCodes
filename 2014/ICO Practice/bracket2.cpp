#include<iostream>
#include<cstdio>
using namespace std;
class ar
{
public:
    int a[100000],b[100000];
    long long int ac,bc,res,r;
    ar()
    {
        ac=0; bc=0;res=0; r=0;
    }
}s1,s2;
long long int alt=1,n,i,altd=0;
int temp=0;
int main()
{
    freopen("in.txt","r",stdin);
    int flag=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        if((flag==1)&&(temp==3)){alt++;}
        else if((flag==2)&&(temp==1)){alt++;}
        if(temp==1)
        {
            s1.a[s1.ac]=temp;
            s1.ac++;
            flag=1;
        }
        else if(temp==2)
        {
            s1.b[s1.bc]=temp;
            s1.bc++;
        }
        else if(temp==3)
        {
            s2.a[s1.ac]=temp;
            s2.ac++;
            flag=2;
        }
        else if(temp==4)
        {
            s2.b[s2.bc]=temp;
            s2.bc++;
        }

        if(s1.ac>s1.bc){s1.res++;}
        else if(s1.ac==s1.bc)
            {
                if(s1.res>s1.r){s1.r=s1.res;}
                s1.res=0;
            }
        if(s2.ac>s2.bc){s2.res++;}
        else if(s2.ac==s2.bc)
            {
                if(s2.res>s2.r){s2.r=s2.res;}
                s2.res=0;
            }

        if(((s1.ac==s1.bc)||(s2.ac==s2.bc)))
            {
                if(alt>altd)
                    {altd=alt;}
                alt=1;
                flag=0;
            }
    }
    cout<<altd<<" "<<s1.r+1<<" "<<s2.r+1<<"\n";
    return 0;
}
