#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 10005

int main()
{
    int t;
	scanf("%d ",&t);
	//freopen("out.txt","w",stdout);
	while(t--){
		long k;
		long ct = 0;		// total cost of publishing
		long cost[257] = {0};
		scanf("%d ",&k);		// character - cost pairs
		while(k--){
			char x;
			long y;
			scanf("%c %d ",&x,&y);
			cost[(int)(x)]=y;
		}
		
		long m;
		scanf("%d ",&m);
		/*for(int i=0; i<m ; i++){
			char str[sz];
			//scanf("%[^\n]s ",str);
			gets(str);
			int p = strlen(str);
			//printf("%d %s\n",p,str);
			for(int j=0; j<p ; j++){
				map <char,long>::iterator it = cost.find(str[j]);
				if(it!= cost.end()){
					ct = ct + it->second ;
				}
			}
		}*/
		char c='`';
		while((c=getchar())!='\n'){
				ct = ct + cost[(int)(c)];
		}
		float f = ct/100.0;
		printf("%.2f$\n",f);
	}
    return 0;
}
