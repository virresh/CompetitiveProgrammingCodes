#include <bits/stdc++.h>
using namespace std;

#define sz 100005
#define ll long long

ll a[sz];
ll res[sz];

int main()
{
	ll t;
	cin>>t;
	while(t--)
    {
        memset(res,0,sizeof(res));
        ll N,D;
        cin>>N>>D;
        for(ll i=0; i<N; i++)
        {
            cin>>a[i];
        }
        bool impossible=false;
        for(ll i=0; i<D; i++)
        {
            ll total=a[i];
            ll j=i+D,cnt=1;
            while(j<N)
            {
                total+=a[j];
                j+=D;
                cnt++;
            }
            if(total%cnt !=0)
            {
                impossible = true;
                break;
            }
            res[i] = total/cnt;
        }

//        for(int i=0; i<D; i++){
//            cout<<res[i]<<" ";
//        }
//        cout<<"\n";

        for(ll i=1; i<D; i++)
        {
            if(res[i]!=res[i-1])
            {
                impossible=true;
            }
        }
        if(impossible)
        {
            cout<<"-1\n";
        }
        else
        {
            ll ans = 0;
            for(ll i=0; i<D; i++)
            {
                ll temp=a[i] - res[i];
                a[i] = res[i];
                ll j=i+D;
                while(j<N)
                {
                    ans += abs(temp);
                    a[j]+=temp;
                    temp = a[j]-res[i];
                    j+=D;
                }
                assert(temp==0);
                ans+=temp;
            }
//            for(int i=0; i<N; i++)
//            {
//                cout<<a[i]<<"\n";
//            }
            cout<<ans<<"\n";
        }
    }
	return 0;
}
// 1 4 7
