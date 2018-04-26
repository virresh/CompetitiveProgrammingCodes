#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int freqP[256], freqQ[256], numDisP=0;
        memset(freqP,0,sizeof(freqP));
        memset(freqQ,0,sizeof(freqQ));
        string a,b;
        cin>>a>>b;
        if(a==b)
        {
            cout<<"YES\n";
        }
        else{
            for(int i=0; i<a.size(); i++)
            {
                freqP[a[i]]++;
                freqQ[b[i]]++;
            }
            vector<int> P;
            vector<int> Q;
            for(int i=0; i<256; i++)
            {
                if(freqP[i]!=0)
                {
                    P.push_back(freqP[i]);
                }
                if(freqQ[i]!=0)
                {
                    Q.push_back(freqQ[i]);
                }
            }
            sort(P.begin(), P.end());
            sort(Q.begin(), Q.end());

            bool x=true;

            if(P.size()!=Q.size())
            {
                x=false;
            }
            else
            {
                for(int l=0; l<P.size(); l++)
                {
                    if(P[l]!=Q[l])
                    {
                        x=false;
                        break;
                    }
                }
            }

            if(x==true && P.size()!=26){
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }

        }
    }
}
