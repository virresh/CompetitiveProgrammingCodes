#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 105
struct span{
    int start,endd,limit,bess;
};

pair<int,int> limit[sz]; //--> first - length of segment,
pair<int,int> bess[sz]; // --> second - speed
vector<span> route;
int main()
{
    ofstream fout ("speeding.out");
    ifstream fin ("speeding.in");
    int m,n,i,j,k,travelled=0,maxOverspeed=0,cml1=0,cml2=0;
    fin>>n>>m;
    for(i=0;i<n;i++)
    {
        fin>>limit[i].first>>limit[i].second;
    }
    for(i=0;i<m;i++)
    {
        fin>>bess[i].first>>bess[i].second;
    }
    i=j=k=0;
    span s;
    for(;travelled<100 && i<n && j<m ;)      // overlap both routes
    {
        s.start=travelled;
        if(limit[i].first+cml1<bess[j].first+cml2)
        {
            cml1+=limit[i].first;
            s.endd=cml1;
            s.bess=bess[j].second;
            s.limit=limit[i].second;
            i++;
        }
        else if(limit[i].first+cml1>bess[j].first+cml2)
        {
            cml2+=bess[j].first;
            s.endd=cml2;
            s.bess=bess[j].second;
            s.limit=limit[i].second;
            j++;
        }
        else
        {
            cml1+=limit[i].first;
            cml2+=bess[j].first;
            s.endd=cml1;
            s.bess=bess[j].second;
            s.limit=limit[i].second;
            i++;
            j++;
        }
        travelled=max(cml1,cml2);
        route.push_back(s);
        k++;
    }
    for(i=0;i<route.size();i++)
    {
        if(route[i].bess>route[i].limit)
        {maxOverspeed=max(maxOverspeed,route[i].bess-route[i].limit);}
    }
    fout<<maxOverspeed<<"\n";
    return 0;
}
