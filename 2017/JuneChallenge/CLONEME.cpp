#include <bits/stdc++.h>
using namespace std;

#define sz 100005

int a[sz],freq[sz];
int main()
{
    memset(freq,0,sizeof(freq));
    int t;
    cin>>t;
    while(t--)
    {
        int N,Q;
        cin>>N>>Q;
        for(int i=1; i<=N; i++){
            cin>>a[i];
        }

        for(int i=0; i<Q; i++){
            int A,B,C,D;
            vector<int> ar1;
            vector<int> ar2;
            cin>>A>>B>>C>>D;
            for(int k=A; k<=B; k++){
                freq[a[k]]++;
            }
            for(int j=1; j<sz; j++){
                while(freq[j]>0){
                    freq[j]--;
                    ar1.push_back(j);
                }
            }
            for(int k=C; k<=D; k++){
                freq[a[k]]++;
            }

            for(int j=1; j<sz; j++){
                while(freq[j]>0){
                    freq[j]--;
                    ar2.push_back(j);
                }
            }
            int ans=0;
            for(int j=0; j<ar1.size(); j++){
                if(ar1[j]!=ar2[j]){
                    ans++;
                }
            }
            if(ans>1){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
        }
    }

    return 0;
}
