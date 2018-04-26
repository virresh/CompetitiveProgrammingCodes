#include <bits/stdc++.h>
using namespace std;
#define ll long long

string arr[6] ={"HELLO","HOLA","HALLO","BONJOUR","CIAO","ZDRAVSTVUJTE"};
string arr2[6]= {"ENGLISH","SPANISH","GERMAN","FRENCH","ITALIAN","RUSSIAN"};
int main()
{
    string s;
    int t,k=1,p=0;
    while(cin>>s)
    {
        p=0;
        if(s=="#"){break;}
        else
        {
            cout<<"Case "<<k<<": ";
            for(t=0;t<6;t++)
            {
                if(arr[t].compare(s)==0)
                {
                    p=1;
                    cout<<arr2[t]<<"\n";
                    break;
                }
            }
            if(p==0){cout<<"UNKNOWN\n";}
        }
        k++;
    }
    return 0;
}
