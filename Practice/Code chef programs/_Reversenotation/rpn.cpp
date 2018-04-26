#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
class stak
{
public:
    char arr[500];
    int top;
    stak()
    {
        top=0;
    }
    char topele()
    {
        return arr[top-1];
    }
    void push(char x)
    {
        arr[top++]=x;
    }
    char pop()
    {
        return arr[--top];
    }
    void show();
};
int main()
{
    char input;
    int t;
    cin>>t;
    while(t--)
    {
        stak letter,opera;
        char ch='`';
        cin.ignore();
        while(ch!='\n')
        {
            cin.get(ch);
            if(isalpha(ch))
            {
                letter.push(ch);
            }
            else if(ch=='(')
            {
                opera.push(ch);
            }
            else if(ch==')')
            {
                int x=0;
                while(x<letter.top)
                {
                    cout<<letter.arr[x++];
                }
                letter.top=0;
                while((opera.topele()!='(')&&(opera.top))
                {
                     cout<<opera.pop();
                }
                opera.top--;
            }
            else
            {
                opera.push(ch);
            }
        }
        cout<<"\n";
    }
    return 0;
}
void stak::show()
{
    for(int i=0;i<top;i++){cout<<arr[i]<<" ";}
    cout<<"\n";
}
