#include <bits/stdc++.h>
using namespace std;

#define sz 100005
int a[sz];
deque<int> dq;

int main()
{
	int t;
	cin>>t;
	for(int i=1; i<=t; i++)
    {
        int n;
        cin>>n;
        dq.clear();
        for(int i=0; i<n; i++){
            cin>>a[i];
            dq.push_back(a[i]);
        }
        sort(dq.begin(),dq.end());
        int t = (n-1)/2;
        bool ans = true;
        for(int i=0; i<n; i++){
            if(i%2==0){
                t = t-i;
            }
            else{
                t = t+i;
            }
//            cout<<t<<" "<<a[t]<<"\n";
            if(a[t]==*dq.begin()){
                dq.pop_front();
            }
            else if(a[t]==*(--dq.end())){
                dq.pop_back();
            }
            else{
                ans = false;
                break;
            }
        }
        if(ans)
            cout<<"Case #"<<i<<": "<<"YES\n";
        else
            cout<<"Case #"<<i<<": "<<"NO\n";
    }
	return 0;
}
