#include<bits/stdc++.h>

using namespace std;

#define sz 100005

vector<int> graph[sz];
int N,M;
int cost[sz];

int main()
{
    cin>>N>>M;
    int x = 0,maxCost=0,numS=1;
    for(int i=1; i<=N; i++)
    {
        cin>>cost[i];
        if(cost[i]>cost[maxCost]){
            maxCost = i;
        }
        x+=cost[i];
    }

    for(int i=1; i<=M; i++)
    {
        int X,Y;
        cin>>X>>Y;
        graph[X].push_back(Y);
        graph[Y].push_back(X);
    }
    bool selected[sz];
    memset(selected,false,sizeof(selected));

    selected[maxCost] = true;

    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(cost[maxCost],maxCost));
    while(!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();

        for(int i=0; i<graph[v].size(); i++){
            int adjV = graph[v][i];
            if(selected[adjV] == false)
            {
                bool cycle = false;
                // this is not a selected vertex. add it as a candidate
                for(int j=0; j<graph[adjV].size(); j++){
                    if(selected[graph[adjV][j]]==true && graph[adjV][j]!=v)
                    {
                        cycle = true;
                        break;
                    }
                }
                if(!cycle){
                    selected[adjV]=true;
                    numS++;
                    pq.push(make_pair(cost[adjV],adjV));
                }
            }
        }
    }

    cout<<N-numS<<"\n";
    for(int i=N; i>=1; i--){
        if(selected[i]==false){
            cout<<i<<" ";
        }
    }
    return 0;
}
