#include <bits/stdc++.h>
using namespace std;

int main()
{
	char match[25];
	while(scanf("%s",match)!=EOF){
		int teamA = 0, teamB = 0, winner = -1; // 0 - Team A won, 1 - Team B won
		int i=0;
		for (i = 0; ((i < 10) && winner == -1); ++i)
		{
			if(match[i]=='1' && i%2==0){
				teamA++;
			}
			else if(match[i]=='1' && i%2==1){
				teamB++;
			}
			int turnsOfA =  (i/2)+1;
			int turnsOfB = ceil(i/2.0);
			// cout<<i<<" "<<turnsOfA<<" "<<turnsOfB<<"\n";
			if(teamA > teamB && ((teamA-teamB) > (5 -turnsOfB))){
				winner = 0;
				break;
			}

			if(teamB > teamA && ((teamB-teamA) > (5 - turnsOfA))){
				winner = 1;
				break;
			}
		}

		if(teamA > teamB){
			winner = 0;
		}
		else if(teamB > teamA){
			winner = 1;
		}

		while(winner == -1 && i<20){

			if(i%2 == 0 && match[i]=='1'){
				teamA++;
			}

			if(i%2 == 1 && match[i]=='1'){
				teamB++;
			}

			if(i%2==1){
				if(teamA > teamB){
					winner = 0;
					break;
				}
				else if(teamA < teamB){
					winner = 1;
					break;
				}
			}

			i++;
		}

		if(winner == -1){
			cout<<"TIE\n";
		}
		else if(winner == 0){
			cout<<"TEAM-A "<<(i+1)<<"\n";
		}
		else if(winner == 1){
			cout<<"TEAM-B "<<(i+1)<<"\n";
		}

	}
	return 0;
}
