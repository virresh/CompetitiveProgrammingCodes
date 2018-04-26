#include <bits/stdc++.h>
using namespace std;
#define sz 15
#define INF 10005
int panic[sz][sz], finalPanic[sz][sz];
int timef[sz][sz], finalTime[sz][sz];
bool visited[sz][sz];

int directions[4][2]= { {1,0},
                        {0,1},
                        {-1,0},
                        {0,-1}
                      };

struct node{
    int panicF, timeF;
    int xc,yc;
};

bool operator<(const node &a, const node &b)
{
    if(a.panicF == b.panicF)
    {
        return a.timeF < b.timeF;
    }
    return a.panicF < b.panicF;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,M;
        cin>>N>>M;
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=M; j++)
            {
                cin>>panic[i][j];
                finalPanic[i][j] = INF;
                finalTime[i][j] = INF;
                visited[i][j]= false;
            }
        }

        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=M; j++)
            {
                cin>>timef[i][j];
            }
        }

        priority_queue <node> pq;
        node a;
        a.xc = 1, a.yc = 1;
        a.panicF = panic[1][1];
        a.timeF = timef[1][1];

        pq.push(a);
        finalPanic[1][1]=panic[1][1];
        finalTime[1][1] = timef[1][1];
        while(!pq.empty())
        {
//        for(int i=1; i<=N; i++)
//        {
//            for(int k=1; k<=M; k++)
//            {
//                cout<<(finalPanic[i][k]!=INF?finalPanic[i][k]:0)<<" ";
//            }
//            cout<<"\n";
//        }
//        cout<<"\n";

            node b = pq.top();
            pq.pop();
            if(finalPanic[b.xc][b.yc] < b.panicF)
            {
                continue;
            }
            else if(finalPanic[b.xc][b.yc] == b.panicF && finalTime[b.xc][b.yc] < b.timeF)
            {
                continue;
            }
            //cout<<" X-C and Y-C "<<b.xc<<" " <<b.yc<<" Cost = "<<b.panicF<<"\n";
            //visit all the side adjacent vertices
            for(int i=0; i<4; i++)
            {
                int nX = b.xc + directions[i][0];
                int nY = b.yc + directions[i][1];
                //cout<<"Exploring Vertex "<<nX<<","<<nY<<"\n";
                if(!((nX>=1 && nX <=N)&&(nY >=1 && nY <=M)))
                {
                    //cout<<"Invalid\n";
                    continue;
                }
                if(finalPanic[nX][nY] > b.panicF+panic[nX][nY])
                {
                    node l; l.xc=nX, l.yc= nY;
                    finalPanic[nX][nY] = b.panicF+panic[nX][nY];
                    finalTime[nX][nY] = b.timeF+timef[nX][nY];
                    l.panicF = finalPanic[nX][nY];
                    l.timeF = finalTime[nX][nY];
                    //cout<<"Adding vertex "<<nX<<","<<nY<<"\n";
                    pq.push(l);
                }
                else if((finalPanic[nX][nY] == b.panicF+panic[nX][nY]) && (finalTime[nX][nY] > b.timeF + timef[nX][nY] ))
                {
                    node f;
                    f.xc=nX; f.yc=nY;
                    finalTime[nX][nY] = b.timeF+timef[nX][nY];
                    f.panicF = finalPanic[nX][nY];
                    f.timeF = finalTime[nX][nY];
                    //cout<<"Adding vertex "<<nX<<","<<nY<<"\n";
                    pq.push(f);
                }
            }

        }

//        for(int i=1; i<=N; i++)
//        {
//            for(int k=1; k<=M; k++)
//            {
//                cout<<finalTime[i][k]<<" ";
//            }
//            cout<<"\n";
//        }

        cout<<finalPanic[N][M]<<" "<<finalTime[N][M]<<"\n";
    }
	return 0;
}
