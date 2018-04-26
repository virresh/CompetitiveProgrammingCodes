#include <bits/stdc++.h>
using namespace std;
#define sz 100005

int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        int ans=0;
        int n;
        cin>>n;
        while(n>0){
            int j;
            for(j=1; j<=n/j; j++);
            if(j*j!=n){
                j--;
            }
            n = n - j*j;
//            cout<<n<<" "<<j<<"\n";
            ans++;
        }
        cout<<"Case #"<<i<<": "<<ans<<"\n";
    }
    return 0;
}
