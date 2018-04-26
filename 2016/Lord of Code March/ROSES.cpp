#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000005
int epet[sz],opet[sz],ein,oin;
char str1[]="Happy",str2[]="Sad";
int main()
{
    int t;
	cin>>t;
	while(t--)
	{
		int n,end=-1,i,temp;
		ll res=0;
		char p[10];
		ein=0; oin=0;
		cin>>n;
		cin>>p;
		if(strcmp(p,str1)==0)
		{
			end=1;	// starts with happy so to end in happy npetal must be odd
		}
		else
		{
			end=0;	// starts with sad so to end in happy npetal must be even
		}
		for(i=0;i<n;i++)
		{
			cin>>temp;
			if(temp%2==0)
			{
				epet[ein]=temp;
				ein++;
			}
			else
			{
				opet[oin]=temp;
				oin++;
			}
			res+=temp;
		}
		sort(epet,epet+ein);
		sort(opet,opet+oin);
		if(res%2== end) // all roses can be taken
		{
			cout<<res<<"\n";
		}
		else	// some rose must be left
		{
			if(end==0)	// remove an odd petaled rose so total becomes even
			{
				if(oin!=0)
				{
					res-= opet[0];
					if(res !=0)
					{
						cout<<res<<"\n";
					}
					else
					{
						cout<<str2<<"\n";
					}
				}
				else
				{
					cout<<str2<<"\n";
				}
			}
			else	// remove an odd petaled rose so total becomes odd
			{
				if(oin!=0)
				{
					res-= opet[0];
					if(res !=0)
					{
						cout<<res<<"\n";
					}
					else
					{
						cout<<str2<<"\n";
					}
				}
				else
				{
					cout<<str2<<"\n";
				}
			}
		}
	}
    return 0;
}
