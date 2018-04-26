#include <iostream>
#include <cstdio>
#define gc getchar

char array[100];

int read_int() 
{
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') 
  {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
void savea()
{
     char m;
    do
    {
          std::cout<<read_int();
          
    }while(m!='\n');     
}
int main()
{
    savea();
    return 0;   
}
