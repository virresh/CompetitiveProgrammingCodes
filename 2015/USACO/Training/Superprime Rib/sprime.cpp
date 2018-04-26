#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
ID: virresh1
PROG: sprime
LANG: C++
*/
int n;
//set<int> res;
vector <ll> res;
bool isPrime(ll num)
{
    if(num==2){return true;}
    else if(num%2==0)
    {
        return false;
    }
    else
    {
        ll k=3;
        for(;k<=num/k; k+=2)
        {
            if(num%k==0)
            {
                return false;
            }
        }
        return true;
    }
}
void solve(ll num,int depth)       // does dfs for a given prime node
{
    if(depth>n){return;}
    if(depth==n){
                res.push_back(num);
                return;
            }
    for(int x=1; x<=9;x+=2)
    {
        if(isPrime(num*10+x))
        {
            solve(num*10+x,depth+1);
        }
    }
}

void compute()
{
    solve(2,1);
    solve(3,1);
    solve(5,1);
    solve(7,1);
}

int main()
{
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    fin>>n;
    compute();
    for(ll i=0;i<res.size();i++)
    {
        fout<<res[i]<<"\n";
    }
    return 0;
}
