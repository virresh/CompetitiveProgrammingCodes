#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>

class club
{
	protected:
	int club_number;
	char club_name[20];
	int club_level;
	int budget_limit;
	int wage_limit;

	public:
	void in()
	{
		cprintf("Enter Club Number\n\r");
		cin>>club_number;
		cprintf("Enter Club Name\n\r");
		gets(club_name);
		cprintf("Enter Club Level\n\r");
		cin>>club_level;
		cprintf("Enter the Budget\n\r");
		cin>>budget_limit;
		cprintf("Enter Wage Limit\n\r");
		cin>>wage_limit;
	}

	char* getclubname()
	{
			return club_name;
	}

	void out()
	{
		cout<<club_number<<"\n\r";
		puts(club_name);
		cout<<club_level<<"\n\r";
		cout<<budget_limit<<"\n\r";
	}

};

class player
{
	int player_number;
	char first_name[10];
	char last_name[10];
	/*int age;
	char position[5];
	int rating;
	int contract;
	int wages;
	int importance_level;
	char old_club_name[20];
	//char new_club_name[20];
	int release_clause;
	//club player_club;*/

	public:
	void in()
	{
		cprintf("Enter Player Number\n\r");
		cin>>player_number;
		cprintf("Enter First Name\n\r");
		gets(first_name);
		cprintf("Enter Last Name\n\r");
		gets(last_name);
		/*cprintf("Enter Age");
		cin>>age;
		cprintf("Enter Position");
		gets(position);
		cprintf("Enter Rating");
		cin>>rating;
		cprintf("Enter Contract Date");
		cin>>contract;
		cprintf("Enter Weekly Wages");
		cin>>wages;
		cprintf("Enter Status at the Club");
		cin>>importance_level;
		cprintf("Enter Club Name");
		gets(old_club_name);
		//strcpy(new_club_name,old_club_name);
		cprintf("Enter Release Clause");
		cin>>release_clause;    */
	}

	/*char* getclubname()
	{
		return old_club_name;
	}

	void setclub(club a)
	{
		player_club = a;
	} */

	void out()
	{
		cout<<player_number;
		puts(first_name);
		//player_club.out();
	}

};

int editdata()
{
	char ch;
	cprintf("Enter 1. for Entering Team\n\r");
	cprintf("Enter 2. for Entering Players\n\r");
	cprintf("Enter 4. to Exit\n\r");
	ch = getche();
	cout<<endl;
	char counter = '1';
	ofstream fout;
	ifstream fin;

	if(ch == '1')
	{
		fout.open("clubs.dat",ios::app|ios::binary);
		club new_club;
		do
		{
			new_club.in();
			fout.write((char*)&new_club,sizeof(new_club));
			cprintf("Do you want to continue? Press Y to continue\n\r");
			counter = getche();
			cout<<endl;
		}while(counter == 'y');
		fout.close();
		editdata();
	}

	else if(ch == '2')
	{
		fout.open("players.dat",ios::app|ios::binary);
		//fin.open("clubs.dat",ios::in|ios::binary);
		//club temp_club;
		player new_player;
		do
		{
			new_player.in();
			fout.write((char*)&new_player,sizeof(new_player));
			/*while(!fin.eof())
			{
				fin.read((char*)&temp_club,sizeof(temp_club));
				if(strcmp(temp_club.getclubname(),new_player.getclubname()))
				{
					new_player.setclub(temp_club);
					break;
				}
			}*/
			cprintf("Want to Continue ?\n\r");
			counter = getche();
			cout<<endl;
		}while(counter == 'y');
		fout.close();
		//fin.close();
		editdata();
	}

	else if(ch == '3')
	{
	    ifstream f1;
        f1.open("players.dat",ios::in|ios::binary);
        player a;
        if(f1)
        {
            while(!f1.eof())
            {
                f1.read((char*)&a,sizeof(a));
                a.out();
            }
            if(!f1.eof()){f1.close();}
        }
		//exit(0);
	}
    else if(ch == '4')
	{
	    ifstream f1;
        f1.open("clubs.dat",ios::in|ios::binary);
        while(!f1.eof())
        {
            club a;
            f1.read((char*)&a,sizeof(a));
            if(!f1.eof()){a.out();}
		}
		f1.close();
    }
	else
	{
		cprintf("Wrong Choice!");
		return 1;
	}
	return 0;
}

void main()
{
	clrscr();
	while(editdata()==1){//do nothing
	}
	getch();
}
