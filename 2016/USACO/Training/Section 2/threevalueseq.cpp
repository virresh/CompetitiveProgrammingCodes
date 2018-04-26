#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1005
/*
ID: virresh1
PROG: sort3
LANG: C++
*/
int a[sz],freq[3+1];
void show(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    int n,cp=0,ans=0;
    cin>>n;
    memset(freq,0,sizeof(freq));
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        freq[a[i]]++;
    }
    /*for(int i=0;i<n;i++)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    cerr<<freq[1]<<" "<<freq[2]<<" "<<freq[3]<<"\n";
    show(n);*/
    for(int i=freq[1];i<n;i++)
    {
        if(a[i]==1)
        {
            int temp=i;
            for(int j=0;j<freq[1];j++)
            {
                if(a[j]==2)
                {
                    temp=j;
                    break;
                }
                else if(a[j]==3)
                {
                    temp=j;
                }
            }
            swap(a[temp],a[i]);
            //show(n);
            ans++;
        }
    }
    for(int i=freq[1]+freq[2]; i<n;i++)
    {
        if(a[i]==2)
        {
            int j,temp=i;
            for(j=0; j<freq[1]+freq[2];j++)
            {
                if(a[j]==3)
                {
                    temp=j;
                    break;
                }
            }
            swap(a[temp],a[i]);
            ans++;
            //show(n);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
