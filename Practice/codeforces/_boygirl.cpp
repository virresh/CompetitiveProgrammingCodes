#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    set<char> s;
    char a[105];
    scanf("%s",a);
    int i=0;
    for(i=0;a[i]!='\0';i++)
    {
        s.insert(a[i]);
    }
    cout<<((s.size()%2==0)?"CHAT WITH HER!":"IGNORE HIM!");
    return 0;
}
