#include <iostream>

using namespace std;
unsigned long int local(int* a,int n)
{
    unsigned long int linv=0;
    for(int i=0;i<=n-2;i++)
    {
        if(a[i]>a[i+1]){linv++;}
    }
    return linv;
}
unsigned long int glob(int* a,int n)
{
    unsigned long int ginv=0;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            if(a[i]>a[j]){ginv++;}
        }
    }
    return ginv;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,arr[102];
        unsigned long int m,l;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
            m=local(arr,n);
            l=glob(arr,n);
            if(m==l){cout<<"YES\n";}
            else{cout<<"NO\n";}
    }
    return 0;
}
