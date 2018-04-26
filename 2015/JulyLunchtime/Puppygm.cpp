#include <iostream>

using namespace std;

int main()
{
    int t;
    long a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a%2==0 && b%2==0){cout<<"Tuzik"<<"\n";}
        else if(a%2!=0 && b%2!=0){cout<<"Vanka"<<"\n";}
        else {cout<<"Tuzik"<<"\n";}
    }
    return 0;
}
