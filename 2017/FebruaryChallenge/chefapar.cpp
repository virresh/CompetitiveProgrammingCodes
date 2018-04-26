#include <bits/stdc++.h>

using namespace std;

int  main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        int zeroCount= 0, noPenaltyCount=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            if(x==0){
                zeroCount++;
            }
            else if(i==noPenaltyCount){
                noPenaltyCount++;
            }
        }
        int penalty = zeroCount==0?0:((n-noPenaltyCount)*100);
        int dues = zeroCount * 1000;
        cout<<penalty+dues<<"\n";
    }
    return 0;
}
