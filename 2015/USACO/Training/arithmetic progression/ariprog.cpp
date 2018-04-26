#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 130000
/*
ID: virresh1
PROG: ariprog
LANG: C++
*/

int bset[sz],nmax,n,m,pi=0;
//vector <pair <int,int> > v;  // first stores difference and second stores starting value
pair<int,int> v[1005];

bool solution_exist(int a,int d)
{
    int cnt=0;
    for(int i=a;cnt<n;i+=d,cnt++)
    {
        if(i>=nmax){return false;}
        if(bset[i]==-1){return false;}
    }
    return true;
}

void solve()
{
    int i,j;
    for(i=0;i<nmax;i++)
    {
        if(bset[i]!=-1)
        {
            for(j=bset[i];j<nmax&& j!=0;j=bset[j])
            {
                //cout<<i<<":"<<j<<" ";
                if(solution_exist(i,j-i))
                {
                    v[pi].first=j-i;
                    v[pi].second=i;
                    pi++;
                }
            }
            i=bset[i]-1;
        }
        if(bset[i]==0){break;}
    }
}


int main()
{
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    //fin>>n>>m;
    scanf("%d %d",&n,&m);
    memset(bset,-1,sizeof(bset));
    int p=0;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=m;j++)
        {
            bset[i*i+j*j]=0;
        }
    }
    p=m*m*2;
    for(int q=p-1;q>=0;q--)
    {
        if(bset[q]!=-1)
        {
            bset[q]=p;
            p=q;
        }
    }
    nmax=m*m*2+1;
    /*for(int k=0;k<nmax;k++)
    {
        if(bset[k]!=-1){cout<<k<<":"<<bset[k]<<" ";}
    }
    cout<<"\n";*/
    solve();
    if(pi==0){//fout<<"NONE\n";
        printf("NONE\n");
    }
    else
    {
        sort(v,v+pi);
        for(int i=0;i<pi;i++)
        {
            //fout<<v[i].second<<" "<<v[i].first<<"\n";
            printf("%d %d\n",v[i].second,v[i].first);
        }
    }
    //fout.close();
    //fin.close();
    return 0;
}
