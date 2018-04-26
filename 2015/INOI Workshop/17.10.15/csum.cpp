#include <bits/stdc++.h>
using namespace std;
#define ll long long
float a[1002];
int main()
{
    int t,n,i;
    float sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%f",&a[i]);
            sum+= a[i];
        }
        //printf("%0.2f \n",sum/pow(2,n));
        printf("%0.2f \n",sum/2);
    }
    return 0;
}
