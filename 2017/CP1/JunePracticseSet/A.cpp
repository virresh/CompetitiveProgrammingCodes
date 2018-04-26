#include <bits/stdc++.h>
using namespace std;

#define sz 100005

vector<int> adjList[sz];
int color[sz], numVertex[2];
bool visited[sz];
queue<int> bQ;


bool colorFrom(int source)
{
    bool isBipartite = true;
    bQ.push(source);
    color[source] = 0;
    numVertex[color[source]]++;
    while(!bQ.empty())
    {
        int t= bQ.front();
        visited[t] = true;
        bQ.pop();
        for(int j=0; j<adjList[t].size(); j++)
        {
            int k = adjList[t][j];
            if(!visited[k]){
                bQ.push(k);
            }
            if(color[k]==-1){
                color[k] = color[t] ^ 1; // this will toggle the color
                numVertex[color[k]]++;
            }
            else
            {
                if(color[k]==color[t])
                {
                    //collision, the graph isn't bipartite
                    isBipartite = false;
                }
            }
        }
    }
    return isBipartite;
}


int main()
{
    memset(color,-1,sizeof(color));
    memset(visited,false,sizeof(visited));
    memset(numVertex,0,sizeof(numVertex));
	int N,M;
	cin>>N>>M;
	for(int i=0; i<M; i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int source = 1;
    bool res=true;
    for(int i=1; i<=N; i++)
    {
        if(visited[i]==false){
            res = res & colorFrom(i);
        }
        if(res==false){
            break;
        }
    }

    if(res){
        for(int i=0; i<2; i++)
        {
            cout<<numVertex[i]<<"\n";
            for(int j=1; j<=N; j++)
            {
                if(color[j] == i)
                {
                    cout<<j<<" ";
                }
            }
            cout<<"\n";
        }
    }
    else{
        cout<<"-1\n";
    }

	return 0;
}
