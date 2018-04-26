#include <cstdio>
#include <iostream>
using namespace std;

char st[1000],rev[1000];

unsigned long long int op=0;
int len(char m[])
{
  int l;
  for(l=0;m[l]!='\0';l++);
  return l;
}
void reve(int i)
{
     for(int j=0;j<=i;j++)
        {rev[j]=st[i-j-1];}
        return;
}
bool pal(int i)
{
    for(int k=0;k<=i;k++)
    { if(rev[k]!=st[k]){return false;}}
    return true;
}
void red(int i)
{
     for(int y=0;y<=(i-1)/2;y++)
     {       cout<<"Inisde LooP\t";
             if((int)(st[y])>(int)(rev[i-y-1]))
             {
                  while((int)(st[y])!=(int)(rev[i-y-1])){(int)(st[y])--; op++;}
             }
             else if((int)(st[y])<(int)(rev[i-y-1]))
             {
                  while((int)(st[y])!=(int)(rev[i-y-1])){(int)(st[i-y-1])++; op++;}
             }
     }
     cout<<"Exiting loop \n";
}
int main() 
{
    int t=0,i,o=-1; char p;
    cin>>t;
    while(t--){
    for(o=0;;o++)
    {
             cin.get(p);
             if(p=='\n'){break;}
             st[o]=p;
    }
    i=len(st);
    reve(i);
    if(pal(i)){cout<<0<<"\t i m here\n";}
    else{red(i); cout<<op<<"\t i m heredl\n"; op=0;}
    for(int h=0;h<=i;h++)
    {
            cout<<st[h]<<"\n";
    }
    }
    system("pause");
    return 0;
}
