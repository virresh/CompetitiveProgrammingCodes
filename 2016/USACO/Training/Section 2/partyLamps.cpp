#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 105
/*
ID: virresh1
PROG: lamps
LANG: C++                  
*/
int n,c;
bool possible=false;
int finalState[sz];
set <string> answers;
set<string>::iterator it;
void print(int t) // t is the state of switches and is saves the state into a string
{
	string s="";
	possible=true;
	int p;
	for(int i=0;i<n;i++)
	{
		p=1;
		p=p^((t&1)!=0); // apply button 1
		if((i+1)%2==0)
		{
			p=p^((t&4)!=0); //apply button 3
		}
		else
		{
			p=p^((t&2)!=0); //apply button 2
		}
		if(i%3==0)
		{
			p=p^((t&8)!=0); //apply button 4
		}
		//cout<<p;
		if(p==0)
		{
			s+='0';
		}
		else
		{
			s+='1';
		}
	}
	answers.insert(s);
	//cout<<"\n";
}

bool isValid(int t)
{
	//cout<<t<<"\n";
	int p;
	for(int i=0;i<n;i++) // i=0 => lamp 1 or index=lampno-1 
	{
		if(finalState[i+1]!=-1)
		{
			p=1;
			p=p^((t&1)!=0); // apply button 1
			//cout<<"b1 "<<p<<" "<<((t&1) !=0)<<" ";
			if((i+1)%2==0)	// even lamp
			{
				p=p^((t&4)!=0); //apply button 3
				//cout<<"b3 "<<p<<" "<<((t&4) !=0)<<" ";
			}	
			else
			{
				p=p^((t&2)!=0); //apply button 2
				//cout<<"b2 "<<p<<" "<<((t&2) !=0)<<" ";
			}
			if(i%3==0)
			{
				p=p^((t&8)!=0); //apply button 4
				//cout<<"b4 "<<p<<" "<<((t&8) !=0)<<" ";
			}
			//cout<<i+1<<"\n";
			if(p!=finalState[i+1]){return false;}
		}
	}
	return true;
}
void solve(int state,int dep) // dep is the number of valid button presses available
{
	//cout<<state<<" "<<dep<<"\n";
	if(dep<0){return;}
	if(isValid(state))
	{
		print(state);
		//answers.insert(state);
	}
	if(dep==0){return;}
	int i=0;
	for(int k=1;k<=8;k=k<<1)
	{
		if(((state&k)==0))
		solve(state^k,dep-1);
	}
}
int main()
{	
	memset(finalState,-1,sizeof(finalState));
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
	cin>>n>>c;
	c=min(c,4);
	int state=0; //all switches are off
    int x=0;
	cin>>x;
	while(x!=-1)
	{
		finalState[x]=1;
		cin>>x;
	}
	cin>>x;
	while(x!=-1)
	{
		finalState[x]=0;
		cin>>x;
	}
	/*for(int i=1;i<=n;i++)
	{
		cout<<finalState[i]<<" ";
	}
	cout<<"\n";*/
	solve(state,c);
	if(answers.size()!=0){possible=true;}
	if(!possible)
	{
		cout<<"IMPOSSIBLE\n";
	}
	else
	{
		for(it=answers.begin(); it!=answers.end(); it++)
		{
			cout<<*it<<"\n";
		}
	}
	//cout<<isValid(1)<<"\n";
	//print(3);
	//<<"\n";
    return 0;
}
