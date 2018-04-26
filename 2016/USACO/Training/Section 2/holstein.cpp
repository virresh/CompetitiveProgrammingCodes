#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define imax 32769
/*
ID: virresh1
PROG: holstein
LANG: C++
*/
int v,g,va[25+3][15+3],requirement[25+3],ans[15+3],res=0,no_of_feeds=0;

//  rows -> store info about one type of feed =>v
//  cols -> store info about the qty of vitamin =>g
//  SET stores the set of vitamins selected viz 1...15
//
bool satisfies(int s) // set satisfies all constraints
{
    int cnt=0;
    memset(ans,0,sizeof(ans));
    for(int k=1;k<=imax;k<<=1,cnt++)
    {
        if(s&k)         // feed type cnt is selected
        {
            //cout<<cnt<<" ";
            for(int i=0;i<v;i++)
            {
                ans[i]+=va[cnt][i];
            }
        }
    }
    //cout<<"\n";
    for(int i=0;i<v;i++)
    {
        if(ans[i]<requirement[i]){return false;}
    }
    return true;
}
void solve(int SET) //BFS
{
    //cout<<SET<<" "<<depth<<"\n";
    queue<int> q;
    int p;
    q.push(SET);
    while(!q.empty())
    {
        if(res==0) //answer not found yet
        {
          p=q.front();
          //cout<<p<<" ";
          q.pop();
          if(satisfies(p))
          {
            res=p;
            return;
          }
          for(int x=1; x<=imax;x<<=1)
          {
              if(!(p & x))
              {
                  q.push(p|x);
              }
          }
        }
        else
        {
            return;
        }
    }
}

 /*   //DFS Approach
void solve(int SET,int depth)
{
    if(res!=0 || depth>15){return;}
    if(satisfies(SET))
    {
        res=SET;
        no_of_feeds=depth;
        return;
    }
    for(int x=1; x<=imax;x<<=1)
    {
        if(!(SET & x))
        {
            solve(SET|x, depth+1);
        }
    }
}
*/
int main()
{
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    cin>>v;
    for(int i=0;i<v;i++)
    {
        cin>>requirement[i];
    }
    cin>>g;
    for(int i=0;i<g;i++)
    {
        for(int j=0;j<v;j++)
        {
            cin>>va[i][j];
        }
    }
    solve(0);
    vector<int> answer;
    for(int x=1,cnt=0;x<=imax;x<<=1,cnt++)
    {
        if(res&x)
        {
            answer.push_back(cnt+1);
        }
    }
    cout<<answer.size()<<" ";
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i];
        if(i!=answer.size()-1){cout<<" ";}
    }
    cout<<"\n";
    return 0;
}
