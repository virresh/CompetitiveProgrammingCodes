#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 13
/*
ID: virresh1
PROG: wormhole
LANG: C++
*/
ll n,X[sz],Y[sz],partner[sz],next[sz];

bool cycle_exists()
{

    ll i,j,pos;
    for(i=1;i<=n;i++)
    {
        pos=i;
        int cnt=0;
        for(;cnt<n;cnt++)
        {
            //cout<<pos<<" ";
            pos=next[partner[pos]];
        }
        //cout<<"\n";
        if(pos!=0){return true;}
    }
    return false;
    //return true;
}

int solve()
{
    ll i,j,total=0;
    for(i=1;i<=n;i++)       //first unpaired partner
    {
        if(partner[i]==0){
            break;
        }
    }

    if(i>n)     // if no one is unpaired
    {
        if(cycle_exists())
        {
/*            for(int i=1;i<=n;i++)
            {
                cout<<X[i]<<":"<<Y[i]<<"  "<<X[partner[i]]<<":"<<Y[partner[i]]<<"   ";
            }
            cout<<"\n"; */
            return 1;
        }
        return 0;
    }

    // try to pair with all other unpaired

    for(j=i+1; j<=n;j++)
    {
        if(partner[j]==0) //found one
        {
            partner[i]=j;
            partner[j]=i;
            total+=solve();         //make other pairings
            partner[i]=partner[j]=0; // rollback
        }
    }
    return total;
}
int main()
{
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>X[i]>>Y[i];
    }
    memset(partner,0,sizeof(partner));
    memset(next,0,sizeof(next));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(Y[i]==Y[j]&& (X[i]<X[j]))
            {
                if(next[i]==0 || ((X[j]-X[i])<(X[next[i]]-X[i])))
                {
                    next[i]=j;
                }
            }
        }
    }
    /*for(int i=0; i<=n;i++)
    {
        cout<<next[i]<<" ";
    }
    cout<<"\n";*/
    fout<<solve()<<"\n";
    fout.close();
    fin.close();
    return 0;
}
