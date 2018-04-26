#include <bits/stdc++.h>
using namespace std;

#define sz 1000005

int s_treeMax[4*sz],a[sz], s_treeMin[4*sz];

void fastscan(int &number)
{
    // courtesy : GeeksForGeeks
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

void build(int root, int l, int r)
{
    if(l==r)
    {
        s_treeMax[root]=a[l];
        s_treeMin[root]=a[l];
    }
    else{
        int mid = (l+r)/2;
        build(2*root, l, mid);
        build(2*root+1, mid+1, r);
        s_treeMax[root] = max(s_treeMax[2*root], s_treeMax[2*root+1]);
        s_treeMin[root] = min(s_treeMin[2*root], s_treeMin[2*root+1]);
    }
}

void queryMaxMin(int root, int l, int r, int ql, int qr, int &mx, int &mn)
{
    if(l>qr || r<ql){
        return;
    }
    if(l>=ql && r<=qr){
        //return s_treeMax[root];
        mx = s_treeMax[root];
        mn = s_treeMin[root];
        return;
    }
    int mid = (l+r)/2;
    int mx1=-1,mx2=-1,mn1=INFINITY,mn2=INFINITY;
    queryMaxMin(2*root,l,mid,ql,qr,mx1,mn1);
    queryMaxMin(2*root+1,mid+1,r,ql,qr,mx2,mn2);
    mx = max(mx1,mx2);
    mn = min(mn1,mn2);
}

void update(int root, int l, int r, int index, int val)
{
    if(index>r || index<l)
    {
        return;
    }
    if(l==r && l==index)
    {
        s_treeMax[root] = val;
        s_treeMin[root] = val;
        a[index] = val;
    }
    else if(l!=r){
        int mid = (l+r)/2;
        update(2*root, l, mid, index, val);
        update(2*root+1, mid+1, r, index, val);
        s_treeMax[root] = max(s_treeMax[2*root], s_treeMax[2*root+1]);
        s_treeMin[root] = min(s_treeMin[2*root], s_treeMin[2*root+1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int N,Q;
    cin>>N>>Q;
    //scanf("%d %d",&N, &Q);
    //fastscan(N);
    //fastscan(Q);
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
        //scanf("%d",&a[i]);
        //fastscan(a[i]);
    }
    build(1,1,N);
    int A,B;
    for(int i=0; i<Q; i++)
    {
        int a;
        cin>>a;
        //scanf("%d",&a);
        //fastscan(a);
        if(a==1)
        {
            int x,y;
            cin>>x>>y;
            //scanf("%d %d",&x, &y);
            //fastscan(x);
            //fastscan(y);
            queryMaxMin(1,1,N,x,y,A,B);
            //cout<<A-B<<"\n";
            printf("%d\n",(A-B));
        }
        else if(a==2)
        {
            int i,x;
            cin>>i>>x;
            //scanf("%d %d",&i,&x);
            //fastscan(i);
            //fastscan(x);
            update(1,1,N,i,x);
        }
    }
	return 0;
}
