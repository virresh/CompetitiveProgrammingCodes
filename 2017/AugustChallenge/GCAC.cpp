#include <bits/stdc++.h>
using namespace std;
#define sz 1003
#define ll long long

int qual[sz][sz];
ll offeredSal[sz];
ll maxJobOff[sz];
ll minSal[sz];

ll numEmployed[sz];
ll sal[sz];
ll companyHired[sz];

int main()
{
    int t;
    cin>>t;
    while(t--){
        memset(companyHired,0,sizeof(companyHired));
        memset(sal,0,sizeof(sal));
        memset(numEmployed, 0 ,sizeof(numEmployed));
        int N,M;
        cin>>N>>M;
        for(int i=1; i<=N; i++)
        {
            cin>>minSal[i];
        }

        for(int i=1; i<=M; i++)
        {
            cin>>offeredSal[i]>>maxJobOff[i];
        }

        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=M; j++)
            {
                char z;
                cin>>z;
                qual[i][j] = z - '0';
            }
        }
//        for(int i=1; i<=N; i++)
//        {
//            for(int j=1; j<=M; j++)
//            {
//                cout<<qual[i][j]<<" ";
//            }
//            cout<<"\n";
//        }

        for(int i=1; i<=N; i++)
        {
            ll tempCompany=-1;
            // For every candidate i
            for(int j=1; j<=M; j++)
            {
                //Corresponding companies
                if(qual[i][j]==1){
                    // person has qualified
                    if(offeredSal[j]>=minSal[i]){
                        // person can think of accepting
                        if((tempCompany==-1 || offeredSal[j]>=offeredSal[tempCompany] )&& maxJobOff[j]>0)
                        {
                            // this company is giving maximum salary till yet
                            tempCompany = j;
                        }
                    }
                }
            }
            if(tempCompany !=-1 && offeredSal[tempCompany]>=minSal[i]){
                numEmployed[tempCompany]++;
                sal[i] = offeredSal[tempCompany];
                companyHired[i] = tempCompany;
                maxJobOff[tempCompany]--;
            }
        }
        ll totalSal=0, wJob=0, noCandidat=0;
        for(int i=1; i<=N; i++)
        {
            totalSal += sal[i];
            if(companyHired[i]!=0)
            {
                wJob++;
            }
        }
        for(int i=1; i<=M; i++){
            if(numEmployed[i]==0){
                noCandidat++;
            }
        }

        cout<<wJob<<" "<<totalSal<<" "<<noCandidat<<"\n";

    }
	return 0;
}
