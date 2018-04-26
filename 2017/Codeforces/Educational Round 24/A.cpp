#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,k;
    cin>>n>>k;
    ll nC, nD, nT;
    nT = n;
    nC = n/(2*(k+1)) ;
    nD = k * nC;
    nT = n - nC - nD;
    cout<<nC<<" "<<nD<<" "<<nT<<"\n";

    return 0;
}
