#include <bits/stdc++.h>
using namespace std;

#define sz 100005

int freq[15];
char s[sz];
int alphaSupported[256][10];

int main()
{
    memset(alphaSupported,0,sizeof(alphaSupported));
    for(int i='A'; i<='Z'; i++){
        int j= i;
        while(j>0){
            int t= j%10;
            j /= 10;
            alphaSupported['A'][t]++;
        }
    }

	int t;
	cin>>t;
	while(t--)
    {
        scanf("%s", s);
        for(int i=0; i<=10; i++)
        {
            freq[i] = 0;
        }
        for(int i=0; s[i]!='\0'; i++)
        {
            freq[(s[i]-'0')]++;
        }
        if(freq[6] >=1 && freq[5]>=1){
            cout<<"A";
        }
        if(freq[6] >=2){
            cout<<"B";
        }
        if(freq[6] >=1 && freq[7]>=1){
            cout<<"C";
        }
        if(freq[6] >=1 && freq[8]>=1){
            cout<<"D";
        }
        if(freq[6] >=1 && freq[9]>=1){
            cout<<"E";
        }
        if(freq[7] >=1 && freq[0]>=1){
            cout<<"F";
        }
        if(freq[7] >=1 && freq[1]>=1){
            cout<<"G";
        }
        if(freq[7] >=1 && freq[2]>=1){
            cout<<"H";
        }
        if(freq[7] >=1 && freq[3]>=1){
            cout<<"I";
        }
        if(freq[7] >=1 && freq[4]>=1){
            cout<<"J";
        }
        if(freq[7] >=1 && freq[5]>=1){
            cout<<"K";
        }
        if(freq[7] >=1 && freq[6]>=1){
            cout<<"L";
        }
        if(freq[7] >=2){
            cout<<"M";
        }
        if(freq[7] >=1 && freq[8]>=1){
            cout<<"N";
        }
        if(freq[7] >=1 && freq[9]>=1){
            cout<<"O";
        }
        if(freq[8] >=1 && freq[0]>=1){
            cout<<"P";
        }
        if(freq[8] >=1 && freq[1]>=1){
            cout<<"Q";
        }
        if(freq[8] >=1 && freq[2]>=1){
            cout<<"R";
        }
        if(freq[8] >=1 && freq[3]>=1){
            cout<<"S";
        }
        if(freq[8] >=1 && freq[4]>=1){
            cout<<"T";
        }
        if(freq[8] >=1 && freq[5]>=1){
            cout<<"U";
        }
        if(freq[8] >=1 && freq[6]>=1){
            cout<<"V";
        }
        if(freq[8] >=1 && freq[7]>=1){
            cout<<"W";
        }
        if(freq[8] >=2){
            cout<<"X";
        }
        if(freq[8] >=1 && freq[9]>=1){
            cout<<"Y";
        }
        if(freq[9] >=1 && freq[0]>=1){
            cout<<"Z";
        }

        cout<<"\n";
    }
	return 0;
}
