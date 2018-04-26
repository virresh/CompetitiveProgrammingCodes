#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
ID: virresh1
PROG: milk3
LANG: C++
*/

int amax,bmax,cmax,a,b,c;
int ans[23][23][23];
ofstream fout ("milk3.out");
ifstream fin ("milk3.in");

void solve(int x,int y,int z)
{
    if(x<23&& y<23 && z<23)
        if(ans[x][y][z]==0)
        {
            //fout<<x<<":"<<y<<":"<<z<<"\n";
            ans[x][y][z]=1;
            // 1->2
            if(x+y>bmax)
            {
                solve(x-(bmax-y),bmax,z);
            }
            else
            {
                solve(0,x+y,z);
            }

            // 1->3
            if(x+z>cmax)
            {
                solve(x-(cmax-z),y,cmax);
            }
            else
            {
                solve(0,y,x+z);
            }
            // 2->1
            if(y+x>amax)
            {
                solve(amax,y+x-amax,z);
            }
            else
            {
                solve(y+x,0,z);
            }
            // 2->3
            if(z+y>cmax)
            {
                solve(x,z+y-cmax,cmax);
            }
            else
            {
                solve(x,0,z+y);
            }
            // 3->1
            if(z+x>amax)
            {
                solve(amax,y,z+x-amax);
            }
            else
            {
                solve(x+z,y,0);
            }
            // 3->2
            if(y+z>bmax)
            {
                solve(x,bmax,y+z-bmax);
            }
            else
            {
                solve(x,y+z,0);
            }
        }
}

int main()
{
    memset(ans,0,sizeof(ans));
    fin>>amax>>bmax>>cmax;
    a=b=0; c=cmax;
    int flag=0;
    solve(a,b,c);
    for(int i=0;i<23;i++)
    {
        for(int j=0;j<23;j++)
        {
            if(ans[0][j][i]==1){if(flag!=0){fout<<" ";} fout<<i; flag=1;}
        }
    }
    fout<<"\n";
    return 0;
}
