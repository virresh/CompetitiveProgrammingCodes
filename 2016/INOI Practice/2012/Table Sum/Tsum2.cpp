#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 400010
int a[sz],n;
// s stores the segment tree

void modify(int pos,int val) // this will modify the value at position pos in the tree
{
    int p=pos+n;
    a[p]=val;
    p>>=1;
    for(;p>0;p>>=1)
    {
        a[p]=max(a[p<<1],a[(p<<1)+1]);
    }
}
void print()
{
    for(int i=1;i<=2*n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    cin>>n;
    for(int i=n+1;i<=2*n;i++)
    {
        cin>>a[i];
        a[i]+=i-n;
    }
    for(int i=n;i>0;i--)        // builds the segment tree
    {
        a[i]=max(a[(i<<1)],a[((i<<1) +1)]);
       // cout<<i<<" "<<(i<<1)<<" "<<((i<<1) +1)<<"\n";
    }
    //print();
    cout<<a[1]<<" "; // answer for the first pass
    for(int i=2; i<=n; i++) // i th pass , i>1
    {
        modify(n+2-i,a[n+2-i]-n);
        //print();
        cout<<a[1]+i-1<<" ";
    }

    return 0;
}
