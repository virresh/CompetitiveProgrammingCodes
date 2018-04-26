#include <bits/stdc++.h>
using namespace std;
#define ll long long

int weight(char x)
{
	return (int)(x-'a');
}

bool isSpl(string s,int o=-1)
{
	int j=s.length()-1,i=0;
	if(j<=0)
	{
		return false;
	}
	if(j%2==0 && o==-1)	// odd length string
	{
		for(int p=0;p<=j;p++)
		{
			if(isSpl(s,p))
			{
				return true;
			}
		}
	}
	else	// even length string or odd length and need to drop one character
	{
		string r;
		int len=0,k;
		if(o!=-1)
		{
			for(k=0;k<=j;k++)
			{
				if(k!=o)
				{
					r+=s[k];
					len++;
				}
			}
		}
		else
		{
			r=s;
			len=j+1;
		}
		for(i=0,k=len/2; i<len/2 && k<len ; i++,k++)
		{
			if(r[i]!=r[k])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

bool isDouble(string s)
{
	int p=s.length(),i;
	for(i=p/2; i<p ; i++)
	{
		if(s[i]!=s[i-p/2])
		{
			return false;
		}
	}
	return true;
}

/* Using binary search
bool isSpl(string s)
{
	int n=s.length();
	if(n%2==0)
	{
		if(isDouble(s))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else	// need to binary search
	{
		int low=0,high = n-1,mid,lweight=0,rweight=0,temp=0;
		mid=(low+high)/2 ;
		for(int q=0; q<n;q++)
		{
			if(q<mid)
				lweight+=weight(s[q]);
			else if( q>mid)
				rweight+=weight(s[q]);
		}
		while(low <= high)
		{
			temp=weight(s[mid]);
			if(lweight<rweight)
			{
				high=mid-1;
				mid=(low+high)/2;
				lweight= lweight + temp - weight(s[mid]);
			}
			else if(lweight>rweight)
			{
				low=mid+1;
				mid=(low+high)/2;
				rweight= rweight + temp - weight(s[mid]);
			}
			else
			{
				string r;
				for(int q=0;q<n;q++)
				{
					if(q!=mid)
						r+=s[q];
				}
				if(isDouble(r))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	return false;
}
*/
int main()
{
    int d;
	cin>>d;
	while(d--)
	{
		string s;
		cin>>s;
		if(isSpl(s))
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
    return 0;
}
