#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000+5
int a[sz],n;

void build()
{
    for(int i=n-1;i>0;i--)
    {
        a[i]=a[(i<<1)] + a[i<<1|1];
        //cout<<i<<" = "<< (i<<1) << " + "<<(i<<1)+1<<"   "<<a[i]<<"\n";
    }
    //cout<<"\n";
}
void print()
{
    for(int i=0;i<2*n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
int query(int l,int r)
{
    int ans=0;
    for(l+=n,r+=n; l<r ; l>>=1,r>>=1)
    {
        if(l&1)
        {
            ans+=a[l++];
        }
        if(r&1)
        {
            ans+=a[--r];
        }
        //cout<<l<<" "<<r<<" "<<ans<<"\n";
    }
    //cout<<l<<" "<<r<<" "<<ans<<"\n";
    return ans;
}

void modify(int pos,int val)
{
    // invalid location
    int p=pos+n,temp;
    temp=a[p];
    for(;p>0;p>>=1)
    {
        a[p]=a[p]-temp+val;
    }
}
int main()
{
    cin>>n;
    for(int i=n;i<2*n;i++)
    {
        cin>>a[i];
    }
    build();
    print();
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cout<<"Enter left then right \n";
        int l=1,r=3;
        cin>>l>>r;
        cout<<query(l,r)<<"\n";

        /*cout<<"Enter position and then new value of that node\n";
        cin>>l>>r;
        modify(l,r);*/
    }
    return 0;
}
