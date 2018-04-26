#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    set <string> s;
    string word;
    char buffer[100];
    int n,i,j;
    cin>>n;
    cin.getline(buffer,100,'\n');
    for(i=0;i<n;i++)
    {
        //cout<<i<<" ";
        cin.getline(buffer,100,'\n');
        word.clear();
        for(j=0;buffer[j]!='\0';j++)
        {
            if(buffer[j]>='a'&& buffer[j]<='z')
            {
                word+=buffer[j];
            }
            else if(buffer[j]>='A' && buffer[j]<='Z')
            {
                buffer[j]=buffer[j]-'A'+'a';
                word+=buffer[j];
            }
            else if(buffer[j]=='\''){}
            else
            {
                if(word.empty()){}
                else
                {
                    s.insert(word);
                    word.clear();
                }
            }
        }
        if(word.empty()){}
        else
        {
            s.insert(word);
            word.clear();
        }
    }
    cout<<s.size()<<"\n";
    for(set<string>::iterator itr =s.begin(); itr!=s.end(); itr++)
    {
        cout<<*itr<<"\n";
    }
    return 0;
}
