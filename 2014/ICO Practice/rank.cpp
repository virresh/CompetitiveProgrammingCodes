#include <iostream>
using namespace std;
long long int n,a[46000],i,j,key,temp=0;
int main()
{

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"1\n";
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0&&key>a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        cout<<j+2<<"\n";
    }

    return 0;
}
