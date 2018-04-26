#include <bits/stdc++.h>
using namespace std;

#define sz 5000005

vector<int> tree[sz];
int a[sz];
bool prime[sz];
int SPF[sz];

void precompute(){
	memset(prime,true,sizeof(prime));
	memset(SPF,1,sizeof(SPF));
	prime[1]=false;
	prime[2]=true;
	for(int i=2; i<sz; i++){
		if(prime[i]==true){
            SPF[i]=i;
			for(int k=2*i; k<sz;k+=i){
                if(prime[k]==true){
                    prime[k]=false;
                    SPF[k]=i;
                }
			}
		}
	}
}

void factorize(int num,int index){
    // factorize num in log n
    while(num!=1){
        int x;
		x = SPF[num];
		tree[index].push_back(x);
		num = num/x;
    }
}


void custom_merge(int i1, int i2, int i3){
    //merge v1 and v2 into v3
    int p=0,q=0, result=0;
    while(p <tree[i1].size() && q<tree[i2].size()){
        if(tree[i1][p]<=tree[i2][q]){
            tree[i3].push_back(tree[i1][p]);
            p++;
        }
        else{
            tree[i3].push_back(tree[i2][q]);
            q++;
        }
    }
    while(p<tree[i1].size()){
        tree[i3].push_back(tree[i1][p]);
        p++;
    }
    while(q<tree[i2].size())
    {
        tree[i3].push_back(tree[i2][q]);
        q++;
    }
}


void build(int node,int startI,int endI){
    if(startI == endI){
        factorize(a[startI],node);
    }
    else
    {
        int mid = (startI+endI)/2;
        build(2*node,startI,mid);
        build(2*node+1, mid+1,endI);
        custom_merge(2*node,2*node+1,node);
    }
    //cout<<"Here "<<node<<" Start Index - "<<startI<<" End Index - "<<endI<<"\n";
}


int query(int node, int lo, int hi, int left, int right, int K){
    //cout<<tree[node].size()<<"\n";
    // returns elements less than K in the range l to r
    if(lo>=left && hi<=right){
        int y = (lower_bound(tree[node].begin(),tree[node].end(),K)-tree[node].begin());
        //cout<<y<<"\n";
        return y;
    }

    if(hi<left || lo > right){
        return 0;
    }

    int mid = (lo+hi)/2;
    return query(2*node,lo,mid,left,right,K) + query(2*node+1,mid+1,hi,left,right,K);
}


int main()
{
    ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
    precompute();

    int N;
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>a[i];
    }
    build(1,1,N);

    int Q;
    cin>>Q;
    for(int i=1;i<=Q;i++){
        int L,R,X,Y;
        cin>>L>>R>>X>>Y;
        cout<< query(1,1,N,L,R,Y+1) - query(1,1,N,L,R,X)<<"\n";
    }
    //cout<<query(1,1,10,1,10,6)<<"\n";

    //cout<< (lower_bound(tree[1].begin(), tree[1].end(),3)-tree[1].begin()) <<"\n";
    return 0;
}
