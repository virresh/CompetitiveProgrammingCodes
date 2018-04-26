#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int n,k,idlen;
vector <ll> person[304];
vector <int> aList[304];
bool rel[304][304]={false};
void printg()
{
    for(ll i=0;i<n;i++)
    {
        cout<<"Neigbours of "<<i<<"\n";
        for(int j=0;j<aList[i].size();j++)
        {
            cout<<aList[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool related(ll i,ll j) // O(m+n) operation
{
    ll n1,n2,cnt=0;
    n1=person[i].size();
    n2=person[j].size();
    for(int x=0,y=0;x<n1 && y<n2;)
    {
        if(person[i][x]==person[j][y])
        {
            cnt++;
            if(cnt>=k){return true;}
            x++; y++;
        }
        else if(person[i][x]<person[j][y])
        {
            x++;
        }
        else
        {
            y++;
        }
        /*for(int y=0;y<n2;y++)
        {
            if(person[i][x]==person[j][y])
            {
                cnt++;
                if(cnt>=k){return true;}
            }
        }*/
    }
    return false;
}
void makeGraph()
{
    for(int i=0;i<n;i++)        // O(n^2) operation
    {
        for(int j=i+1;j<n;j++)
        {
            if(!rel[i][j])
            if(related(i,j))
            {
                aList[i].pb(j);
                aList[j].pb(i);
                rel[i][j]=rel[j][i];
            }
        }
    }
    //printg();
}
ll bfs(ll start)
{
    bool visited[304]={false};
    visited[start]=true;
    queue <ll>stk;
    stk.push(start);
    ll result=1;
    while(!stk.empty())
    {
        ll o=stk.front();
        stk.pop();
        int n1=aList[o].size();
        for(int t=0;t<n1;t++)
        {
            ll u=aList[o][t];
            if(!visited[u])
            {
                visited[u]=true;
                result++;
                stk.push(u);
            }
        }
    }
    return result;
}
int main()
{
    //freopen("1.in","r",stdin);
    ll p;
    scanf("%d %d",&n,&k);
    // Index of president in the vector is always 0
    //--> we need to get the size of the component with president in it
    // Using bfs for this
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&p);
        for(ll j=0;j<p;j++)
        {
            ll temp;
            scanf("%lld",&temp);
            person[i].pb(temp); //ith person has this number in his in his id
        }
        sort(person[i].begin(),person[i].end());
    }
    makeGraph();
    printf("%lld\n",bfs(0));
    return 0;
}
