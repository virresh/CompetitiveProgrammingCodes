#include <iostream>
#include <cstdio>
using namespace std;
void printa(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    cout<<" ";
}
int getsm(int *a,int n,int l=0)
{
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[res])
            {
                if((l==1)&&(a[i]==0)){}
                else {res=i;}
            }
    }
    return res;
}
int getla(int *a,int n)
{
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]>=a[res]){res=i;}
    }
    return res;
}
void tweak(long long int n)
{
    int a[15],i,j=0,small,large,temp,f1=0;
    long long int c=n;
    for(;c>0;c/=10)
    {
        a[j]=c%10;
        j++;
    }
    for(i=0;i<j/2;i++){temp=a[i]; a[i]=a[j-i-1]; a[j-i-1]=temp;}
    if(j==0){cout<<n<<" "<<n; return;}
    else if(j==1){cout<<n<<" "<<n; return;}
    else if((j==2)&&(n%10==0)){cout<<n<<" "<<n; return;}
    small=getsm(a,j);
    large=getla(a,j);
    if((small!=0)&&(a[small]!=0))
        {
            temp=a[0];
            a[0]=a[small];
            a[small]=temp;
            printa(a,j);
            temp=a[0];
            a[0]=a[small];
            a[small]=temp;
        }
    else
    {
        f1=0; small=getsm(a,j,1);
        while((small==f1)&&(small<j))
        {
            f1++;
            small=f1+getsm(a+f1,j-f1);
        }
        if(small==f1){cout<<n<<" ";}
        else
        {
            temp=a[f1];
            a[f1]=a[small];
            a[small]=temp;
            printa(a,j);
            temp=a[f1];
            a[f1]=a[small];
            a[small]=temp;
        }
    }

    if(large!=0)
        {
            temp=a[0];
            a[0]=a[large];
            a[large]=temp;
            printa(a,j);
            temp=a[0];
            a[0]=a[large];
            a[large]=temp;
        }
    else
        {
            f1=0; large=getla(a,j);
            while((large==f1)&&(large<j))
            {
                f1++;
                large=f1+getla(a+f1,j-f1);
            }
            temp=a[0];
            a[0]=a[large];
            a[large]=temp;
            printa(a,j);
            temp=a[0];
            a[0]=a[large];
            a[large]=temp;
        }
}
int main()
{
    freopen("cooking_the_books.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,i;
    long long int n;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        cout<<"Case #"<<i+1<<": ";
        tweak(n);
        cout<<"\n";
    }
    return 0;
}
