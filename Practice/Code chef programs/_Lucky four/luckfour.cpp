#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll t,ans=0;
    char ch='`';
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>ch;
        if(ch=='4'){ans++;}
        while(ch!='\n')
        {
            cin.get(ch);
            if(ch=='4'){ans++;}
        }
        cout<<ans<<"\n";
    }
    return 0;
}
