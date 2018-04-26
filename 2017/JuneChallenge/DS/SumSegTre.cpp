#include <bits/stdc++.h>
using namespace std;

#define sz 100005

int tree[sz];
int a[sz];

void build(int node, int left, int right){
    if(left == right)
    {
        tree[node] = a[left];
    }
    else
    {
        int mid = (left+right)/2;
        build(2*node,left, mid);
        build(2*node+1,mid+1, right);
        tree[node] = tree[2*node]  + tree[2*node+1];
    }

}



int main()
{
	int N;
	cin>>N;
	for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    build(1,0,N-1);
	return 0;
}
