#include<iostream>
 
using namespace std;
int main(){
int n,c;
cin>>n;
int a[12];
a[0]=1;
for(int i=1;i<12;i++){
a[i]=a[i-1]*2;
}
for(int i=0;i<n;i++){
cin>>c;
int j=11;
int m=0;
while(j>=0){
	if((c-a[j])>=0){
		c=c-a[j];
		m=m+1;
	}
	else
		j--;
 
}
cout<<m<<endl;
}
return 0;
}
 
