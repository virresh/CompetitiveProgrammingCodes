#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct stu{
	char name[12];
	int score;
};

bool f(const stu s1,const stu s2)
{
	return s1.score > s2.score ;
}
vector <stu> a[10005];
int main()
{
    int n,m,r;
	//cin>>n>>m;
	scanf("%d %d",&n,&m);
	stu s;
	for(int i=0;i<n;i++)
	{
		scanf("%s %d %d",s.name,&r,&s.score);
		a[r].push_back(s);
	}
	
	for(int i=1; i<=m; i++)
	{
		if(a[i].size()!=0)
		{
			bool isUnique=true;
			stu s1,s2;
			sort(a[i].begin(),a[i].end(),f);
			s1 = a[i][0];
			s2 = a[i][1];
			for(int j=2; j< a[i].size();j++)
			{
				if(a[i][j].score == s2.score)
				{
					isUnique=false;
					break;
				}
			}
			if(isUnique)
			{
				printf("%s %s\n",s1.name,s2.name);
			}
			else
			{
				printf("?\n");
			}
		}
	}
    return 0;
}
