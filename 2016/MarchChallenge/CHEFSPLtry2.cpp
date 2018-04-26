#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000005
char s[sz];
int slen;
int weight(char x)
{
	return (int)(x-'a'+1);
}

bool isDouble(int q=-1)
{
	int n=slen;//,t=0;
	/*char r[sz];
	for(int i=0;i<n;i++)
	{
		if(i!=q)
		{
			r[t]=s[i];
			t++;
		}
	}*/
	if(q!=-1)
	{
		int p=n-1,i,lo,hi;
		lo=0;
		hi=p/2;
		if(lo>q){lo++;}
		if(hi>q){hi++;}
		for(i=p/2; i<p ; i++,lo++,hi++)
		{
			if(lo==q){lo++;}
			if(hi==q){hi++;}
			if(s[lo]!=s[hi])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		for(int j=0;j<n/2;j++)
		{
			if(s[j]!=s[n/2+j])
			{
				return false;
			}
		}
		return true;
	}
}

bool isSpl()
{
	int n=slen;
	if(n%2==0)
	{
		if(isDouble())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if(n==1)
		{
			return false;
		}
		int lweight=0,rweight=0,temp,smid;
		smid=(n-1)/2;
		for(int i=1;i<n;i++)
		{
			if(i<=smid)
			{
				lweight+=weight(s[i]);
			}
			else
			{
				rweight+=weight(s[i]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(lweight == rweight)
			{
				if(isDouble(i-1))
				{
					return true;
				}
			}
			if(i>=n){break;}
			if(i<=smid)
			{
				lweight = lweight + weight(s[i-1]) - weight(s[i]);
			}
			else if(i>smid)
			{
				rweight = rweight + weight(s[i-1]) - weight(s[i]);
			}
		}
	}
	return false;
}
int main()
{
	
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    int d;
	scanf("%d",&d);
	while(d--)
	{
		scanf("%s",s);
		slen = strlen(s);
		if(isSpl())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
    return 0;
}
