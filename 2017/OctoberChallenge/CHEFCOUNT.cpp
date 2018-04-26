#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        for(int i=1; i<=n; i++){
            if(i==n/4){
                cout<< "99999 ";
            }
            else{
                cout<<"100000 ";
            }
        }
        cout<<"\n";
	}

	return 0;
}
