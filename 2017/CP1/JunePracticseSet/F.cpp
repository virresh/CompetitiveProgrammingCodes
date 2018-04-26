#include <bits/stdc++.h>
using namespace std;

#define sz 100015

int parent[sz];

int findParent(int x){
    if(parent[x]<0){
        return x;
    }
    else{
        int y = findParent(parent[x]);
        parent[x]=y;
        return y;
    }
}

void doUnion(int a, int b){
    int p=findParent(a);
    int q=findParent(b);
    if(p!=q)
    {
        parent[a]=q;
        parent[p]=q;
        parent[q]--;
    }
}


int main()
{
	int N,M;
	cin>>N>>M;
	memset(parent,-1,sizeof(parent));
	for(int i=0; i<M; i++){
        int u,v;
        cin>>u>>v;
        doUnion(u,v);
	}
	int ans=0;
	for(int i=1; i<=N; i++){
        if(parent[i]<0){
            ans++;
        }
	}
	/*for(int i=1; i<=N; i++)
    {
        cout<<parent[i]<<" ";
    }*/
    //cout<<"\n";
	cout<<ans<<"\n";
	return 0;
}



/*
6 5
2 1
3 1
4 3
5 4
5 6
*/
