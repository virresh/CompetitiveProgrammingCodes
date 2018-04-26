#include <iostream>

using namespace std;

int main()
{
    int n,maxlead=0,winner=0, score1=0,score2=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
         int c1,c2;
         cin>>c1>>c2;
         score1+=c1; score2+=c2;
         if(score1<score2)
         {if((score2-score1)>maxlead){maxlead=score2-score1; winner=2;}}
         else 
         {if((score1-score2)>maxlead){maxlead=score1-score2; winner=1;}}
    }
    cout<<winner<<" "<<maxlead;
    return 0;
}
