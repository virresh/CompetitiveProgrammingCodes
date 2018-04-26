#include <iostream>
using namespace std;
int arr[100005];
#define INT_MAX 1000000000
/*
    ( ( [ ( ) [ ] ] ( ) [ ( [ ( ) ] ) ] ) )
    20
    1 1 3 1 2 3 4 4 1 2 3 1 3 1 2 4 2 4 2 2

*/
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int flag=10,oct=0,alt=0,rct=0,sqct=0,str=INT_MAX,stsq=INT_MAX,ansr=0,anssq=0,tempr=0,tempsq=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==1)
        {
            if(flag==10)
            {
                flag=1;
                oct++;
            }
            else if(flag==3)
            {
                oct++;
                flag=1;
            }
            else
                tempr++;
            if(str==INT_MAX)
                str=i;
            rct++;
        }
        else if(arr[i]==2)
        {
            if(flag==1 && tempr==0)
            {
                oct--;
                flag=3;
            }
            else if(tempr!=0)
                tempr--;
            rct--;
        }
        else if(arr[i]==3)
        {
            if(flag==10)
            {
                flag=3;
                oct++;
            }
            else if(flag==1)
            {
                oct++;
                flag=3;
            }
            else
                tempsq++;
            if(stsq==INT_MAX)
                stsq=i;
            sqct++;
        }
        else if(arr[i]==4)
        {
            if(flag==3 && tempsq==0)
            {
                oct--;
                flag=1;
            }
            else if(tempsq!=0)
                tempsq--;
            sqct--;
        }
        //cout<<oct<<endl;
        if(oct==0)
        {
            flag=10;
        }
        alt=max(oct,alt);
        if(rct==0)
        {
            ansr=max(ansr,i-str+1);
            str=INT_MAX;
        }
        if(sqct==0)
        {
            anssq=max(anssq,i-stsq+1);
            stsq=INT_MAX;
        }
    }
    cout<<alt<<' '<<ansr<<' '<<anssq;
}
