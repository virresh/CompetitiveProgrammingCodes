#include <bits/stdc++.h>

using namespace std;

int main()
{

    int x1, y1, x2, y2;
    int X,Y;
    cin>>x1>>y1>>x2>>y2;
    cin>>X>>Y;

    int horizD = abs(x2 - x1), vertD = abs(y2-y1);
    bool possible = false;
    if(vertD % Y == 0)
    {
        int n2 = vertD/Y; //these many steps to (SOMETHING,Y)
        int x1Dash = n2*X+x1;
        if(abs(x1Dash - x2) % X == 0)
        {
            int n1 = abs(x1Dash-x2)/X;
            if(n1%2==0){
                possible = true;
            }
        }
    }

//    if((horizD % X ==0) && (vertD % Y==0) && ((horizD/X)%2 == (vertD/Y)%2)){
//        cout<<"YES\n";
//    }
//    else
//    {
//        cout<<"NO\n";
//
    if(possible == true){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}
