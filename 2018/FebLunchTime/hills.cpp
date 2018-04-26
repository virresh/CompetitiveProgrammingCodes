#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long N,U,D;
		std::vector<long long> hill;
		cin>>N>>U>>D;
		for(long long i=0; i<N; i++)
		{
			long long k;
			cin>>k;
			hill.push_back(k);
		}

		long long possible = 0;
		bool jump=true;
		for(long long i=1; i<N; i++)
		{
			// is it possible to reach hill[i] from hill[i-1]
			if(hill[i] >= hill[i-1] && (hill[i]-hill[i-1] <= U))
			{
				possible = i;
			}
			else if(hill[i] <= hill[i-1]){
				if(hill[i-1] - hill[i] <= D){
					possible = i;
				}
				else if(jump == true){
					jump = false;
					possible = i;
				}
				else{
					break;
				}
			}
			else{
				break;
			}
		}
		cout<<possible+1<<"\n";
	}
	return 0;
}
