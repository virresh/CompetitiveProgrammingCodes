#include <bits/stdc++.h>
#define ll int
using namespace std;

int main() {
	ll t;
	char c;
	scanf("%d ",&t);
	while(t--)
	{
	    scanf("%c ",&c);
	    if(c=='b'||c=='B')
	    {
	        printf("BattleShip\n");
	    }
	    else if(c=='c'||c=='C')
	    {
	        printf("Cruiser\n");
	    }
	    else if(c=='d'||c=='D')
	    {
	        printf("Destroyer\n");
	    }
	    else if(c=='f'||c=='F')
	    {
	        printf("Frigate\n");
	    }
	}
	return 0;
}
