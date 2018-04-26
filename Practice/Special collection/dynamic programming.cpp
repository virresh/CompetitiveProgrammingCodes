#include <iostream>
using namespace std;
class ar
{
public:
    int a[10000];
    ar();
    void print(int n);
};
ar::ar()
{
    a[1]=0;
    for(int i=2;i<10000;i++){a[i]=10000;}
}
void ar::print(int n){for(int i=0;i<n;i++){cout<<a[i]<<" ";} cout<<"\n";}
int main()
{
    ar w,m;
    int s,i,j,k,coins=0;
    cin>>s;
    for(i=0;i<s;i++)
    {
        cin>>w.a[i];
    }
    cin>>k;
    for(i=0;i<=k;i++)
    {
        for(j=0;j<s;j++)
        {
            if(w.a[j]<i&& i-w.a[j]+1<m.a[i]){m.a[i]=m.a[i-w.a[j]]+1;}
        }
    }
    cout<<m.a[k]<<"\n";
    //m.print(k);
    return 0;
}
