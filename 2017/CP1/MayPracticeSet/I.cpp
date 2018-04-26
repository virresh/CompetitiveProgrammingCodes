#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define sz 1000005
#define mod 1000000007

ll x[sz],f[sz],p[sz];

int main(){
    memset(p,0,sizeof(p));
    int n,q;
    cin>>n>>q;
    cin>>f[0]>>f[1];
    ll a,b;
    cin>>a>>b;

    for(int i=2; i<sz; i++){
        f[i] = (a*f[i-2]+ b*f[i-1])%mod;        
    }

    for(int i=0; i<n; i++){
        cin>>x[i];
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        l--; r--;
        if(l<r){
            // the l and l+1 th index have tp exist and get f(1) and f(2) added to them
            p[l] = (p[l] + f[0])%mod;
            p[l+1] = (p[l+1] + f[1]) %mod;

            p[l+1] = (p[l+1] + mod - (b*f[0])%mod) %mod;
            // keep only one coefficient part in this

            p[r+1] = (p[r+1] + mod - f[r-l+1])%mod; 
            // subtract to nullify any effect of coefficient from l to r in i > r
            p[r+2] = (p[r+2] + mod - (a * f[r-l])%mod )%mod; 
        }
        else{
            // if l==r
            p[l] = (p[l]+ f[0])%mod;

            p[r+1] = (p[r+1] + mod - (b * f[0]) %mod )%mod;
            p[r+2] = (p[r+2] + mod - (a * f[0]) %mod )%mod;
        }
    }

    for(int i=0; i<n; i++){
        if(i>1){
            p[i] = (p[i] + (a*p[i-2])%mod)%mod;
            // calculate effect of all a's coefficients
        }
        if(i>0){
            p[i] = (p[i] + (b*p[i-1])%mod)%mod;
            // calculate effect of b's coefficients
        }
    }

    for(int i=0; i<n; i++){
        x[i] = (x[i] + p[i])%mod;
        cout<<x[i]<<" ";
    }
    cout<<"\n";

    return 0;
}