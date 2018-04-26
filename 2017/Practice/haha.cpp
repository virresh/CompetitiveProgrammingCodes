#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	long long int N;
	long long int A[100005];
	cin>>T;
	for(int i=1; i<=T; i++){
		cin>>N;
		for(long long int i=0; i<N; i++) {cin>>A[i];}

		long long int width_of_sub=0;
		long long int Happiness=0,H=0,sum=0;
		cout<<"\n"<<N<<"\n";
		for(int i=0; i<N; i++) {sum+=A[i];}
		if(sum<0){
			for(long long int i=0; i<N; i++)
			{
				if(A[i]>=0){
					H+=A[i];
					width_of_sub++;
				}
				else
				{
					Happiness += H*width_of_sub;
					width_of_sub = 0;
					H=0;
					Happiness += A[i];
				}
			}
		Happiness+=H*width_of_sub;
		cout<<Happiness<<endl;
		}
		else
		{
			cout<<sum*N<<endl;	
		}
	}
	return 0;
}