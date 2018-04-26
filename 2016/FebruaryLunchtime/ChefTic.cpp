#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz (10+2)
char maze[sz][sz]; // X== Chef O==Player 2
int k,n;
// 1==Up 2==Left 4==Down 8==Right  
// 16==Top Left 32==Top Right 64==Bottom right 128==Bottom Left
bool visited[sz][sz];

bool valid(int si,int sj)
{
	if(si<n && si>=0 && sj<n && sj>=0)
	{
		return true;
	}
}
bool search(int si,int sj,int contK,int dir,int Ndot=0)
{
	if(contK==0){
			if(Ndot==1){
				return true;
			}
			else
			{
				return false;
			}
	}
	
	if(valid(si+1,sj))
	{
		
	}
}
bool isPossible()
{
	if(k==1){return true;}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if((maze[i][j]=='O' || maze[i][j]=='.')&& search(i,j,k-1,0)==true)
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
    int t,i,j,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>maze[i][j];
			}
		}
		
		if(isPossible())
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
