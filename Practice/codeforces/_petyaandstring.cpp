#include <bits/stdc++.h>
using namespace std;
#define ll long long
int compare(char *a,char *b)
{
	int i=0,x,y;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>='a' && a[i]<='z'){x=(int) (a[i]-'a');}
		else if(a[i]>='A' && a[i]<='Z')
			{x= (int)(a[i]-'A');}

		if(b[i]>='a' && b[i]<='z'){y= (int)(b[i]-'a');}
		else if(b[i]>='A' && b[i]<='Z')
			{y=(int)(b[i]-'A');}

		if(x<y){return -1;}
		else if(x>y){return 1;}
	}
	return 0;
}
int main()
{
	char a[101],b[101];
	scanf("%s\n%s",a,b);
	printf("%d",compare(a,b));
	return 0;
}
