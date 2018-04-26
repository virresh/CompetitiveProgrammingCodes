#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define imax 32769
#define INF 100000
/*
ID: virresh1
PROG: holstein
LANG: C++
*/
int v,g,va[15+3][25+3],requirement[25+3],no_of_feeds=INF,result=0;
//  rows -> store info about one type of feeds =>v
//  cols -> store info about the no of vitamin =>g
//  SET stores the set of vitamins selected viz 1...15

bool satisfies(int s)
{
    int ans[25+3]={0};
    for(int i=0; i<g;i++)
    {
        if(s&(1<<(i)))    // ith feed is selected
        {
            for(int j=0;j<v;j++)
            {
                ans[j]+=va[i][j];
            }
        }
    }
    for(int j=0;j<v;j++)
    {
        if(ans[j]<requirement[j])
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    int SET=0;
    int p=(1<<(g+1))-1; // the last subset possible
    for(;SET< p ;SET++)
    {
        if(satisfies(SET))
        {
            int x=SET,cnt=0;
            while(x>0)
            {
                if(x&1){cnt++;}
                x>>=1;

            }
            //cerr<<SET<<" "<<cnt<<"\n";
            if(cnt<no_of_feeds)
            {
                no_of_feeds=cnt;
                result=SET;
            }
        }
    }

}

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
    solve();
    cout<<no_of_feeds;
    bool r;
    for(int t=1; t<=g;t++)
    {
        r=false;
        if(result & (1<<(t-1)))
        {
            cout<<" "<<t;
        }
    }
    cout<<"\n";
    return 0;
}
