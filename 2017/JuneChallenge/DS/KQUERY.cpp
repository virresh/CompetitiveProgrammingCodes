#include<bits/stdc++.h>
using namespace std;
int btree[30009];

struct pos
{
    int l,r,p;
    long long int v;
};
pos a[230009];
bool cmp(pos a, pos b)
{
    if(a.v == b.v)
    {
        return a.l > b.l;
    }
    return a.v > b.v;
}

void update_it(int idx, int n)
{
    while(idx <=n)
    {
        btree[idx] += 1;
        idx += idx & (-idx);
    }
}

int read_it(int idx)
{
    int s=0;
    while(idx >0)
    {
        s += btree[idx];
        idx -= idx &(-idx);
    }
    return s;
}

int main()
{
    fill(btree,btree + 30009, 0);
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i].v);
        a[i].l = 0;
        a[i].p =0;
        a[i].r = i+1;
    }
    int q;
    scanf("%d",&q);
    int ans[q+1];
    for(i=n ;i< n+q; i++)
    {
        scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].v);
        a[i].p = i-n+1;
    }
    sort(a,a+n+q,cmp);
    //printf("Hello\n");   //check
   /* for(i=0; i<n+q;i++)
    {
        printf("%d %d %d\n",a[i].l,a[i].r,a[i].v);
    }*/
    for(i=0;i< n+q;i++)
    {
        if(a[i].l == 0)
        {
            update_it(a[i].r,n + 9);
        }
        else
        {
           // printf("\n");
       //     for(int j=1;j<=n;j++)
         //      printf("b[%d] = %d\n",j,btree[j]);  // check
           ans[a[i].p] = read_it(a[i].r) - read_it(a[i].l -1);
        }
    }
    //for(i=1;i<=n;i++)
      //  printf("b = %d\n",btree[i]);  //check
    for(i=1;i<=q;i++)
        printf("%d\n",ans[i]);
    return 0;

}
