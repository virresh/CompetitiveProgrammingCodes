#include<bits/stdc++.h>
using namespace std;

bool isValid(char c)
{
    switch(c)
    {
    case 'L':
    case 'T':
    case 'I':
    case 'M':
    case 'E': return true;
    default : return false;
    }
}
int main()
{
	int t,i,flag=0;
	cin>>t;
	char s[102];
	int a[5];
	while(t--)
	{
	    memset(a,0,sizeof(a));
		scanf("%s",s);
		//cin.getline(s,100);
		//printf("%s\n",s);
		flag=0;
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]=='L'){a[0]++;}
			else if(s[i]=='T'){a[1]++;}
			else if(s[i]=='I'){a[2]++;}
			else if(s[i]=='M'){a[3]++;}
			else if(s[i]=='E'){a[4]++;}
		}
		if(isValid(s[0]) && isValid(s[i-1]))
		{
			for(i=0;i<5;i++){if(a[i]<2){flag=1; break;}}
			if(flag==1){cout<<"NO\n";}
			else{cout<<"YES\n";}
		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}
