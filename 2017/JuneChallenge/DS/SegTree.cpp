#include <bits/stdc++.h>
using namespace std;

#define sz 100005

vector<int> tree[sz];
int a[sz];

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
        tree[node].push_back(a[startI]);
    }
    else
    {
        int mid = (startI+endI)/2;
        build(2*node,startI,mid);
        build(2*node+1, mid+1,endI);
        custom_merge(2*node,2*node+1,node);
    }
    cout<<"Here "<<node<<" Start Index - "<<startI<<" End Index - "<<endI<<"\n";
}


int main()
{
    for(int i=1; i<=10; i++){
        a[i]=10-i+1;
    }
    build(1,1,10);
    for(int i=0; i<tree[1].size(); i++){
        cout<<tree[1][i]<<" ";
    }
    cout<<"\n";
    return 0;
}
