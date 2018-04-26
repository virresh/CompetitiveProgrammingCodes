 #include <bits/stdc++.h>
using namespace std;

#define sz 4500006

int s_tree[sz];
int a[1000006];

int calcZ(int P)
{
    if(P==0){
        return 1;
    }
    else{
        int k=0;
        while(P>0)
        {
            if(P%10==0)
            {
                k++;
            }
            P = P/10;
        }
        return k;
    }
}

void build(int root, int left, int right)
{
    if(left == right){
        //single element in range, so do the basic function
        s_tree[root] = calcZ(a[left]);
    }
    else{
        int mid = (left+right)/2;
        build(2*root, left,mid);
        build(2*root+1,mid+1, right);
        s_tree[root] = s_tree[2*root]+ s_tree[2*root+1];
    }
}

int query(int index, int left, int right, int val)
{
    if(val > s_tree[index]){
        return -1;
    }

    if(left==right)
    {
        return left;
    }

    int mid = (left+right)/2;
    int t = s_tree[2*index];
    if(val > t)
    {
        return query(2*index+1,mid+1,right,val-t);
    }
    else{
        return query(2*index,left, mid, val);
    }
}

void update(int v,int index,int root, int left, int right){
    if(left == right)
    {
        // left==right==index
        a[index] = v;
        s_tree[root] = calcZ(v);
        return;
    }
    int mid = (left+right)/2;
    if(index <= mid)
    {
        update(v,index,2*root,left,mid);
    }
    else
    {
        update(v,index,2*root+1, mid+1, right);
    }

    s_tree[root] = s_tree[2*root]+ s_tree[2*root+1];
}
int main()
{
    int N,Q;
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
    }
    build(1,1,N);
    cin>>Q;
    for(int i=1; i<=Q; i++)
    {
        int d;
        cin>>d;
        if(d==0)
        {
            int I,V;
            cin>>I>>V;
            update(V,I+1,1,1,N);
        }
        else if(d==1)
        {
            int K;
            cin>>K;
            int a = query(1,1,N,K)-1;
            cout<< ((a>=0)?a:-1) <<"\n";
        }
    }

    return 0;
}

/*
4
100 1000 2215 2012
*/
