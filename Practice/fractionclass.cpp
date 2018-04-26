#include <iostream>
using namespace std;
class fraction
{
    int num,den;
public:
    fraction(int f=0,int i=1){num=f; den=i;}        //constructor
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
    fraction(const fraction &a)
    {
        num=a.num;
        den=a.den;
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
    //*****************        overloaded operators       **********************//
    fraction operator+(const fraction &f)
    {
        fraction f1(0,1);
        f1.num= (this->num)*f.den + f.num*(this->den);
        f1.den= (this->den)*f.den;
        f1.reduce();
        return f1;
    }
    fraction operator-(const fraction &f)
    {
        fraction f1(0,1);
        f1.num= (this->num)*f.den - f.num*(this->den);
        f1.den=(this->den)*f.den;
        f1.reduce();
        return f1;
    }
    fraction operator*(const fraction &f)
    {
        fraction f1(0,1);
        f1.num= (this->num)*f.num;
        f1.den=(this->den)*f.den;
        f1.reduce();
        return f1;
    }
    fraction operator/(const fraction &f)
    {
        fraction f1(0,1);
        f1.num= (this->num)*f.den;
        f1.den=(this->den)*f.num;
        f1.reduce();
        return f1;
    }
    friend bool operator >>(istream& inp,fraction &f)
    {
        int a;
        cout<<"Numerator :\t";
        inp>>a;
        cout<<"Denominator :\t";
        f.num=a;
        inp>>a;
        if(a==0){cout<<"\nUndefined form. Cannot proceed.\n"; return false;}
        f.den=a;
        f.reduce();
        cout<<"\n";
        return true;

    }
    friend ostream& operator <<(ostream &out,fraction f)
    {
        if(f.num==0){out<<f.num<<" ";}
        else if(f.den==1){out<<f.num<<" ";}
        else{out<<f.num<<"/"<<f.den<<" ";}
        return out;
    }
};
int main()
{
    fraction f1,f2,f3,res;
    cout<<"Enter your fractions :\n";
    if((cin>>f1)&&(cin>>f2))
    {
        res=(f1+f2+f2);
        cout<<res;
    }
    return 0;
}
