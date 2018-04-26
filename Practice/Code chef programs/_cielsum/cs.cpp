#include <iostream>
int arr[100];
using namespace std;
void printra(int l) //Print reversed array
{
     int test=(l==0)?0:(l-1);
     for(;test>=0;test--)
     {cout<<arr[test];}
     cout<<"\n";
}
long len(long num)
{
     int counter=0;
     long re=0;
     if(num>9){
     while(num>0)
     {
             arr[counter]=num%10;
             num/=10; counter++;
     }    
     }
     else{arr[counter]=num;}
     return counter;
}
int dowrong(long num)
{
     int l=len(num),x;
     x=l;
     if(l%2==0){l/=2;}
     else{l=(l+1)/2;}
     
     if(arr[l]!=9){arr[l]++;}
     else{arr[l]--;}
     
     return x;     
}

int main()
{
    unsigned long n1,n2,diff;
    cin>>n1>>n2;
    diff=n1-n2;
    printra(dowrong(diff));
    //system("pause");
    return 0;   
}
