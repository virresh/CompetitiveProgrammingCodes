#include<bits/stdc++.h>
using namespace std;

#define sz 1000005
#define mod 100000009
#define ll long long

struct queries{
    ll l1,r1,l2,r2;
    int index;
    ll v;

    bool operator < (const queries &b){
        return (v<b.v);
    }
};

ll a[sz];
ll squares[sz],sums[sz],hashes[sz];
bool ans[sz];
ll seg_tree[sz];
vector<queries> query;

void updateTree(int node,int index,int lo, int hi){
    if(lo>index || hi < index){
        return;
    }
    else{
        seg_tree[node]+=1;
        mid = (lo+hi)/2;
        update(2*node,index,lo,mid);
        update(2*node+1,index,mid+1,hi);
    }
}


int querySum(int node, int lo, int hi, int left, int right, int K){
    //cout<<tree[node].size()<<"\n";
    // returns elements less than K in the range l to r
    if(lo>=left && hi<=right){
        return segtree[node];
    }

    if(hi<left || lo > right){
        return 0;
    }

    int mid = (lo+hi)/2;
    return querySum(2*node,lo,mid,left,right,K) + querySum(2*node+1,mid+1,hi,left,right,K);
}

int readTree(int index){
    // return count of elements from range 1 to index
    // so the count from range l to r will be read(r)- read(l-1)
    int s=0;
    while(index>0){
        s+=f_tree[index];
        index = index - (index & (-index));
        //cout<<index<<"\n";
    }
    return s;
}



int main()
{
    int T;
    cin>>T;
    squares[0]=0;
    sums[0]=0;
    hashes[0]=0;
    while(T--)
    {
        memset(f_tree,0,sizeof(f_tree));
        memset(ans,false,sizeof(ans));
        ll n,q;
        cin>>n>>q;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            squares[i] = squares[i-1]+a[i]*a[i];
            sums[i] = sums[i-1]+a[i];
            ll bigh=1;
            for(int j=1; j<=10; j++){
                bigh = (bigh * a[i])%mod;
            }
            hashes[i]= hashes[i-1]+bigh;
        }

        for(int i=1; i<=q; i++)
        {
            queries qr;
            qr.index = i;
            cin>>qr.l1>>qr.r1>>qr.l2>>qr.r2;
            ll a = -1, b= -1, aplusb = -1;
            ll aminusb = (sum[r1]-sum[l1-1]) - (sum[r2]-sum[l2-1]);
            ll asminusbs = (squares[r1]-squares[l1-1]) - (squares[r2]-squares[l2-1]);
            if(aminusb!=0){
                aplusb = asminusbs/aminusb;
                a = (aplusb + aminusb)/2;
                b = aplusb - a;
            }

            ll c1 = hashes[r1]-hashes[l1-1], c2 = hashes[r2]-hashes[l2-1];
            if(c1==c2)
            {
                // hashes are same, so possible all elements are same so aplusb == aminusb == 0
                // answer to this query has to be "YES"
                ans[i]=true;
            }
            else
            {
                // check for position of a and b from
                // so add this as a query to be processed offline
                qr.v = a;
                query.push_back(a);
                qr.v = b;
                query.push_back(b);
            }
        }
        sort(query.begin(),query.end());
        for(int i=query.size()-1; i>=0; i--)
        {

        }


    }
    return 0;
}
