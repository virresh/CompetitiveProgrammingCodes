#include <bits/stdc++.h>
using namespace std;

#define sz 100005

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int chef[n+2], sheath[n+2];
		for(int i=1; i<=n; i++){
			cin>>chef[i];
		}

		for(int i=1; i<=n; i++){
			cin>>sheath[i];
		}

		int front=0, back=0;
		for(int i=1; i<=n; i++)
		{
			if(chef[i] > sheath[i] && front ==0){
				front = 1;
			}

			if(chef[i] > sheath[n-i+1] && back == 0){
				back = 1;
			}

			if(front ==1 && back==1){
				break;
			}
		}

		if(front==0 && back ==0){
			cout<<"both\n";
		}
		else if(front == 1 && back ==0){
			cout<<"back\n";
		}
		else if(front == 0 && back ==1){
			cout<<"front\n";
		}
		else{
			cout<<"none\n";
		}
	}
	return 0;
}
