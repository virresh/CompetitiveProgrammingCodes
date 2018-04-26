#include <iostream>
using namespace std;
struct obj
{
    int id,attr,val,mpr;
};
int main()
{
    int n,m,tid,tp,tat,tval;
    cin>>n>>m;
    obj x;
    cin>>x.id>>x.attr>>x.val>>x.mpr;
    for(int j=0;j<n;j++)
    {
        cin>>tid;
        cin>>tat;
        cin>>tval;
        cin>>tp;
        if(tp>=x.mpr){x.val=tval;}
    }
    for(int i=0;i<m;i++)
    {
        cin>>tid;
        cin>>tat;

    }
    return 0;
}
