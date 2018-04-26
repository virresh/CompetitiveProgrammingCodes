#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char a[100009];
        cin>>a; int n=0,c=0;
        for(n=0;a[n]!='\0';n++);
        sort(a,a+n);
        for(int i=1;a[i]!='\0';i++)
        {
            if(a[i]!=a[i-1]){c++;}
        }
        cout<<c+1<<"\n";
    }
    return 0;
}
 