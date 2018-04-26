#include <bits/stdc++.h>
using namespace std;
#define sz 1000005

//vector < pair<int,int> > adjL[sz];

vector < pair<int , pair<int,int> > > edges;

int parent[sz]; // disjoint set structure

int findParent(int x)
{
    if(parent[x]<0)
    {
        return x;
    }
    else{
        int q = findParent(parent[x]);
        parent[x] = q;
        return q;
    }
}

void doUnion(int a, int b)
{
    int p = findParent(a), q = findParent(b);
    if(p!=q)
    {
        parent[a] = q;
        parent[p] = q;
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        //adjL[x].push_back(make_pair(y,c));
        //adjL[y].push_back(make_pair(x,c));
        edges.push_back(make_pair(c,make_pair(x,y)));
    }

    sort(edges.begin(),edges.end());
    memset(parent,-1,sizeof(parent));

    int ans=0;
    //for(vector<pair<int, pair<int,int> > >::iterator it = edges.begin(); it!=edges.end(); it++)
    for(int i = 0; i <edges.size(); i++)
    {
        int j=i;
        while(edges[j].first == edges[i].first){
            j++;
        }
        // process all edges with same weight together
        for(int k=i; k<j; k++){
            int u = edges[k].second.first;
            int v = edges[k].second.second;

            int pU = findParent(u);
            int pV = findParent(v);
            if(pU==pV)
            {
                ans++;
            }
        }

        for(int k=i; k<j; k++)
        {
            doUnion(edges[k].second.first, edges[k].second.second);
        }
        i=j-1;
    }
    cout<<ans<<"\n";
    return 0;
}
/*
5 7
1 2 2
2 5 1
2 3 1
3 4 1
4 5 1
3 5 1
1 5 3
*/
