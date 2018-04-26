#include <iostream>       // std::cout
#include <stdio.h>
#include <stack>          // std::stack
#include <string>

using namespace std;


int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int Test; // Number of test cases.
    cin >> Test;
    string buffer ;
    stack<char> rpnStack;
    string rpnResult = "";
    //getline(cin,no);
    while(Test--){
        cin >> buffer ; // buffer now contains the expression.
        for (int i=0; i < buffer.size(); i++){
            if(buffer[i]== '(' || buffer[i]== '+' || buffer[i]== '-' || buffer[i]== '*' || buffer[i]== '/' || buffer[i]== '^' || buffer[i]== '%'){
                rpnStack.push(buffer[i]);
            }else if(buffer[i]== ')'){
                //rpnStack.pop();
                rpnResult += rpnStack.top();
                rpnStack.pop();
                rpnStack.pop();
            }else if(isalpha(buffer[i])){
                rpnResult += buffer[i];
            }
        }
        cout << rpnResult << endl;
        rpnResult = "";
    }

    return 0;
}
