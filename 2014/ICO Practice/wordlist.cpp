#include <iostream>
#include <cstdio>
using namespace std;
char a[100000],te='`';
long long int i,j,k[10000],kp=0,l,co=0,n,ap=0,np=0,y,temp,fl,o;
bool isChar(char a)
{
    if((a>='a')&&(a<='z')){return true;}
    else return false;
}
int main()
{
    freopen("res.txt","w",stdout);
    freopen("10.txt","r",stdin);
    scanf("%lld",&n);             //Take in the number of rows for the input
    for(i=0;i<=n;i++)   //Loop for taking in the sentence and ignoring the punctuations(they arent printed in the sample  output)
    {
        while(te!='\n')
        {
        scanf("%c",&te);
        if((te=='\n')&&(a[ap]!=' '))
        {
            a[ap]=' '; ap++;
            break;
        }
        else if(((te>='a')&&(te<='z'))||((te>='A')&&(te<='Z')))
            {a[ap]=te; ap++;}
        else if(te=='\''){}
        else
        {
            if(a[ap-1]!=' '){a[ap]=te; ap++;}
        }
        }
        te='`';
    }
    for(i=0;a[i]!='\0';i++)         //Converting all characters to lower case and storing length of array in i
    {
        if((a[i]>='A')&&(a[i]<='Z')){a[i]+=32;}
    }
    if((a[0]>='a')&&(a[0]<='z'))  //Checking the first letter (corner case for my algo
    {
        k[0]=0; kp++; co++;
    }
    for(j=0;j<i;j++)       //Calculating total number of words and storing the first letter's index in another array
    {
        if(((a[j]<'a')||(a[j]>'z'))&&((a[j+1]>='a')&&(a[j+1]<='z')))//&&(a[j-1]==' '))
        {
            k[kp]=j+1;
            kp++;
            co++;
        }
    }
    for(l=0;l<kp;l++)           //sorting the indexes of words in a lexicographical order
    {
    for(j=1;j<kp;j++)
    {
        y=0;
        if(a[k[j]]<a[k[j-1]])
            {temp=k[j-1]; k[j-1]=k[j]; k[j]=temp;}
        else if(a[k[j]]==a[k[j-1]])
        {
            while((a[k[j]+y]==a[k[j-1]+y])&&(a[k[j]+y]!=' ')){y++;}
            if(a[k[j]+y]<a[k[j-1]+y])
            {temp=k[j-1]; k[j-1]=k[j]; k[j]=temp;}
        }

    }
    }
    np=1;
    for(j=0;j<kp;j++,np++)           //Finding and marking duplicates by replacing index by -1
    {
        o=0,fl=0;
            while(isChar(a[k[np]+o]) && isChar(a[k[j]+o]))
            {
                if(a[k[np]+o]!=a[k[j]+o]){fl=1;}
                o++;
            }
            if(((fl==0))&&((!isChar(a[k[j]+o]))&&(!isChar(a[k[np]+o]))))
            {
                k[j]=-1;
                co--;
            }
    }
    cout<<co<<"\n";

    for(j=0;j<kp;j++)           //Displaying all the words in lexicographical order
    {
        y=0;
        while(((a[k[j]+y]>='a')&&(a[k[j]+y]<='z'))&&(k[j]!=-1))
        {
            cout<<a[k[j]+y];
            y++;
        }
        if(((a[k[j]+y-1]>='a')&&(a[k[j]+y-1]<='z'))&&(k[j]!=-1))
        cout<<"\n";
    }
    return 0;
}
