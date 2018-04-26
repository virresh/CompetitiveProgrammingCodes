#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define md 20011
int R,C,D;
int maze[305][305],sol[305][305][305][2];
// sol[i][j][p][d] -> ways of reaching (i,j) by p consec. paths and along the direction d
/*void print()
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
}*/
int main()
{
    cin>>R>>C>>D;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>maze[i][j];
        }
    }
    memset(sol,0,sizeof(sol));
    for(int p=0;p<D;p++)
    {
        sol[R][C][p][0]=sol[R][C][p][1]=1; // ways of reaching last point from itself
    }

    for(int r=R; r>0; r--)
    {

        for(int c=R; c>0 c--)
        {
            if(c==C && r==R) continue;
            sol[r][c][D]
            if(maze[r][c])  // road is not blocked 0-> down 1-> right
            {

                sol[r][c][D][0] = sol[r][c+1][1][1]; // turn down
                sol[r][c][D][1] = sol[r+1][c][1][0]; // turn right
                for(int p=0;p<D;p++)
                {
                    sol[r][c][p][0] = (sol[r+1][c][p][0]+ sol[r][c][p][1])%md ;
                }
            }
        }
    }
    return 0;
}
