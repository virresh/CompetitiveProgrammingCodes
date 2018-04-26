#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <dos.h>
using namespace std;
// Some important declarations //
#define MALE 'm'
#define FEMALE 'f'
#define MAXPOPULATION 100
int year=0;
const char* bunnycolour[]={"White","Brown","Black","Spotted"};
const char* namelist[]={"Thumper","Fufu","Darth Maul","Julius Caesar","Aritro","Paul"};
const int s1=4,s2=6; // s1 for colour and s2 for names
//This will be the number of names we have in the list above Do not forget to change these

// Required classes  //
class bunny
{
public:
    char gender;
    int age,color,name;
    bool rmvb;
    bunny *next,*prev;
    static int population,adultmale,adultfemale,vampire;
    bunny()              //Parameterless constructor (For bunnies without parents)
    {
        population++;
        age=0;
        int n=rand()%s1;
        color=n;
        n=rand()%s2;
        name = n;
        n=rand()%2;             //50% chances for both
        if(n==0){gender=MALE;}
        else{gender=FEMALE;}
        n=rand()%100+1;         // 2% chances of bunny to be radioactive_mutant_vampire_bunny
        if(n==1||n==2){rmvb=true;}
        else {rmvb=false;}
        if(rmvb==true){cout<<"Radioactive Mutant Vampire "; vampire++;}
        cout<<"Bunny "<<namelist[name]<<" was born.\n\n";
    }
    bunny(const bunny &mother)    //When the bunny is born
    {
        population++;
        this->age=0;
        this->color=mother.color;
        int n=rand()%s2;
        this->name = n;
        n=rand()%2;             //50% chances for both
        if(n==0){this->gender=MALE;}
        else{this->gender=FEMALE;}
        n=rand()%100+1;         // 2% chances of bunney to be radioactive_mutant_vampire_bunny
        if(n==1||n==2){this->rmvb=true;}
        else {this->rmvb=false;}
        if(rmvb==true){cout<<"Radioactive Mutant Vampire "; vampire++;}
        cout<<"Bunny "<<namelist[name]<<" was born.\n\n";
    }
    ~bunny()
    {
        //showinfo();
        if(rmvb==true){cout<<"Radioactive Mutant Vampire "; vampire--;}
        cout<<"Bunny "<<namelist[name]<<" Died. at the age of : "<<age<<"\n\n";
        population --;
    }
    void showinfo()
    {
        printf("Name : %s\nAge :%d \nGender : %c \nColor : %s\nRadioactive Mutant :%d\n\n",namelist[name],age,gender,bunnycolour[color],rmvb);
    }
};

class blist
{
public:
    bunny *head,*tail;
public:
    bool isEmpty()
    {
        if(head==NULL)
            {return true;}
        return false;
    }
    blist(){head=NULL; tail=NULL;}
    void addbunny()  //Append at the end
    {
        if(head==NULL)
        {
            bunny *x=NULL;
            x=new bunny();
            if(x!=NULL)
            {
                head=x;
                tail=head;
                head->prev=NULL;
                head->next=NULL;
            }
            else {cout<<"Out of Memory";}
        }
        else if(tail==head)
        {
            bunny *x=NULL;
            x=new bunny();
            if(x!=NULL)
            {
                tail=x;
                tail->prev=head;
                tail->next=NULL;
                head->prev=NULL;
                head->next=tail;
            }
            else{cout<<"Out of Memory";}
        }
        else
        {
            bunny *x=NULL;
            x=new bunny();
            if(x!=NULL)
            {
                x->prev=tail;
                x->next=NULL;
                tail->next=x;
                tail=x;
            }
            else
            {
                cout<<"Out of memory";
            }
        }
    }
    void addbunny(const bunny &a)  //Append at the end and born to a mother
    {
        if(head==NULL)
        {
            bunny *x=NULL;
            x=new bunny(a);
            if(x!=NULL)
            {
                head=x;
                tail=head;
                head->prev=NULL;
                head->next=NULL;
            }
            else {cout<<"Out of Memory";}
        }
        else if(tail==head)
        {
            bunny *x=NULL;
            x=new bunny(a);
            if(x!=NULL)
            {
                tail=x;
                tail->prev=head;
                tail->next=NULL;
                head->prev=NULL;
                head->next=tail;
            }
            else{cout<<"Out of Memory";}
        }
        else
        {
            bunny *x=NULL;
            x=new bunny(a);
            if(x!=NULL)
            {
                x->prev=tail;
                x->next=NULL;
                tail->next=x;
                tail=x;
            }
            else
            {
                cout<<"Out of memory";
            }
        }
    }
    void removebunny(bunny *a)
    {
        if(a==NULL){return;}
        if(head==NULL)
        {
            return;
        }
        else if(tail==head)
        {
            delete(tail);
            tail=NULL;
            head=NULL;
        }
        else if(a!= tail && a!=head)
        {
            bunny *b;
            b=a->next;
            b->prev=a->prev;
            delete(a);
            a=b;
        }
        else if(a==tail)
        {
            a=a->prev ;
            delete(a->next);
            a->next=NULL;
        }
        else if(a==head)
        {
            a=a->next;
            delete(a->prev);
            a->prev=NULL;
        }
    }
    ~blist()
    {
        while(tail!=NULL)
        {
            removebunny(tail);
        }
    }
    void aging()
    {
        cout<<"************  Year "<<year++<<" **********\n";
        bunny *b=head;
        while(b!=NULL)
        {
            (b->age)++;
            if(b->age == 2 && b->rmvb==false)
                {
                    if(b->gender==MALE)
                        bunny::adultmale++;
                    else if(b->gender==FEMALE)
                        bunny::adultfemale++;
                }
            if((b->age)>=2 && (b->gender)==FEMALE && bunny::adultmale>0 && b->rmvb==false)
            {
                addbunny(*b);
            }
            if((b->rmvb)==false && (b->age)>=10){b=(b->next); removebunny(b->prev);}
            else if(b->rmvb==true&& (b->age)>=50){b=(b->next); removebunny(b->prev);}
            else{b=(b->next);}
        }
        if(bunny::population > MAXPOPULATION)
        {
            cout<<"******* FOOD SHORTAGE *********\n";
            int n=bunny::population /2,l=0,i=0;
            while (bunny::population > n)
            {
                l=rand()%(bunny::population + 1);  //RANDOMLY SELECT BUNNIES FOR KILLING
                b=head;
                while(i<l){b=b->next; i++;};
                removebunny(b);
            }
            cout<<"******* POPULATION HALVED *********\n";
        }

    }
};
// TODO : EDIT THE AGING FUNCTION and MAKE A NEW KILL BUNNY FUNCTION
/* ********************* MAIN EXECUTION  BEGINS FROM HERE *********************** */
int bunny::population=0,bunny::adultfemale=0,bunny::adultmale=0,bunny::vampire=0;  //These variable tracks the population.(it is only being initialized it is declared in the bunny class itself)
int main()
{
    freopen("log.txt","w",stdout);
    srand(time(0));
    int i=0;
    blist b;
    while(i++<5){b.addbunny();}
    while(!b.isEmpty() && bunny::population <100)
    {
        //_sleep(100);
        b.aging();
    }
    return 0;
}
