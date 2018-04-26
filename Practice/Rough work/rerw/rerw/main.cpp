#include <iostream>
using namespace std;

class fraction
{
    int num,den;
public:
    fraction(int f=0,int i=0){num=f; den=i;}        //constructor
    void reduce()
    {
        int m,n,j;
        if(num>den){m=num; n=den;}
        else{n=num; m=den;}
        while(j>0)
        {
            j=m%n;
            m=n;
            n=j;
        }
        den=den/m;
        num=num/m;
    }
    void print()
    {
        cout<<num<<"/"<<den;
    }
    void in()
    {
        cin>>num;
        cin>>den;
    }
};
int main()
{
    fraction f1;
    cout<<"Enter your fraction.\n";
    f1.in();
    f1.reduce();
    f1.print();
    return 0;
}
