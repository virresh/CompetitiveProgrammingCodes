#include<bits/stdc++.h>
using namespace std;

int main()
{
    int blocks[200005],inactive[200005];
    string a,b;
    cin>>a>>b;
    for(int i=0; i<a.size(); i++){
        cin>>blocks[i];
        blocks[i]--;
    }
    int ans = a.size();
    int lo=0, hi=ans-1;
    while(lo<hi){
        int mid = (lo+hi)/2;
        memset(inactive,0,sizeof(inactive));
        for(int i=0; i<=mid; i++){
            inactive[blocks[i]]++;
        }

        char newS[200005];
        int neCount=0;
        for(int j=0; j<=a.size(); j++){
            if(inactive[j]==0){
                newS[neCount] = a[j];
                neCount++;
            }
        }
        newS[neCount]='\0';
//        for(int l=0; l<neCount; l++){
//            cout<<newS[l];
//        }
//        cout<<"\n";
        int k1=0,k2=0;
        while(k1<b.size() && k2<neCount)
        {
            if(newS[k2]==b[k1]){
                k2++;
                k1++;
            }
            else{
                k2++;
            }
            //cout<<k1<<" " <<k2<<" Here\n";
        }

        bool possible=true;

        if(k1<b.size()){
            possible=false;
        }

        if(possible){
            lo = mid+1;
        }
        else{
            hi = mid;
        }
        //cout<<mid << " " <<possible<<"\n\n";
    }
    cout<<lo<<"\n";
    return 0;
}
