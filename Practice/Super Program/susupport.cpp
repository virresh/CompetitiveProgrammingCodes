#include <iostream.h>
using namespace std;
/* ******************************** Block 1 ************************** */
class suarray
{
    private :

        int a[20000],len;

    public :

        void savea(int x);
        void printa();
        void printra(char name[],int param);
        void multiply(int num2);  //multiply within the array
};
void suarray::savea(int x)
        {
            for(int i=0;x!=0;i++)
            {
                a[i]=x%10;
                x/=10;
                len=i;
            }
        }
void suarray::printa()
        {
            for(int i=0;i<=len;i++)
            {
                cout<<a[i];
            }
            cout<<"\n";
        }
void suarray::printra(char name[],int param=-1)
        {
            if(param==-1)
            {
            for(int i=len;i>=0;i--)
            {
                cout<<a[i];
            }
            cout<<"\n";
            }
            else
            {
                fstream file;
                file.open("Result.txt",ios::app|ios::ate);
                file<<"\n"<<param<<"! = ";
                for(int j=len;j>=0;j--)
                {
                    file<<a[j];
                }
                file<<"\nSaved by : "<<name<<"\n\n";
                file.close();
            }
        }
void suarray::multiply(int num2)
        {
            int carryover=0,j=0,b=0;
            for(j=0;j<=len;j++)
            {
                       b=(a[j]*num2)+carryover ;
                       a[j]=b%10;
                       carryover=b/10;
            }
            while(carryover)
            {
                     a[j]=carryover%10;
                     carryover/=10;
                     len++;
                     j++;
            }
        }

suarray factorial(int n)
{
    suarray num;
    num.savea(1);
    for(int i=2;i<=n;i++)
    {
        num.multiply(i);
    }
    return num;
}
/* ******************************** Block 1 end ************************** */
/* ******************************** Block 2 ************************** */
unsigned long int sdiv(unsigned long int num)
{
         unsigned long int i=3,l=2;
         if((num%2==0)&&(num!=2)){return 2;}
         for(i=3;i<=num/l;i++)
         {
                              if(num%i==0){return i;}
                              else {l=i;}
         }
         return num;
}
/* ******************************** Block 2 end ************************** */
