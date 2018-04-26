#include <bits/stdc++.h>
using namespace std;

deque<int> num;

int main()
{
    double e = 2.7182818284590452353602874713527f;
    int ans=0;
    //cout<<1000*e<<" ";
    for(int i=1; i<=1500000; i++){
        ans = ans + (int)(i*e);
    }
    cout<<ans<<"\n";
    return 0;
}
