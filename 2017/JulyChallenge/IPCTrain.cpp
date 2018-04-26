#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz 100005

struct trainer{
    ll di,ti,si;
};

bool comp1(trainer a, trainer b) // for sorting by sadness values
{
    return a.si < b.si;
}

bool comp2(trainer a, trainer b)    // for sorting by day of arrival
{
    return a.di < b.di;
}
trainer a[sz];

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        ll N,D;
        cin>>N>>D;
        for(ll i=0; i<N; i++)
        {
            cin>>a[i].di >> a[i].ti >> a[i].si;
        }

        sort(a,a+N,comp2);
        ll curDay=1, aIndex=0, ans=0;
        priority_queue<trainer,vector<trainer>,decltype(&comp1)> pq(&comp1);
        while(curDay<=D)
        {
            // process day curDay

            while(curDay>=a[aIndex].di && aIndex<N)
            {
                trainer x = a[aIndex];
                pq.push(x);
                aIndex++;
            }

            if(pq.empty())
            {
                curDay++;
                continue;
            }

            trainer y=pq.top();
            //cout<<"Day "<<curDay<<" Goes to "<<y.di<<" " <<y.ti<<" "<<y.si<<"\n";
            pq.pop();
            if(y.ti == 1)
            {
                // do nothing, this day goes to this trainer and finishes it off here itself
            }
            else{
                y.ti -=1;
                pq.push(y);
            }
            curDay++;
        }

        while(!pq.empty())
        {
            trainer z = pq.top();
            pq.pop();
            ans = z.ti * z.si + ans;
        }

        cout<<ans<<"\n";
    }
	return 0;
}
