 /*Imagine a publishing company which does marketing for book and audio cassette versions.
Create a class publication that stores the title (a string) and price (type float) of publications.
From this class derive two classes: book which adds a page count (type int) and tape which adds
a playing time in minutes (type float)*/


#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class publication
{	
	protected:
	string title;
	float price;
	public:
		publication()
		{
			title="";
			price=0.0;
		}
		virtual void get_data()=0;
		virtual void display()=0;
		
};

class book:public publication
{
	int page;
	public:
		book()
		{
			page=0;
		}
		void get_data()
		{
			cout<<"Enter Title of Book: ";
			cin.ignore();
			getline(cin,title);
			cout<<"Enter Price : ";
			cin>>price;
			cout<<"Enter Page Count : ";
			cin>>page;
			try
			{
				if(page<=0||price<=0)
				{
					throw price;
				}
				
			}
			catch(float)
			{
				page=0;
				price=0;
				title="0";
			}
		}
		void display()
		{
			cout<<"\n"<<title<<"\t\t"<<price<<"\t\t"<<page;
			
		}
};

class tape:public publication
{
	float play_time;
	public:
		tape()
		{
			play_time=0.0;
		}
		void get_data()
		{
			cout<<"Enter Title of Tape : ";
			cin.ignore();
			getline(cin,title);
			cout<<"Enter Price : ";
			cin>>price;
			cout<<"Enter Playing Time : ";
			cin>>play_time;
				try
			{
				if(play_time<=0||price<=0)
				{
					throw price;
				}
				
			}
			catch(float)
			{
				play_time=0;
				price=0;
				title="0";
			}
		}
		void display()
		{
			cout<<"\n"<<title<<"\t\t"<<price<<"\t\t"<<play_time;
		}
};


int main()
{
	int choice=0,bookCount=0,tapeCount=0,i;
	tape t[100];
	book b[100];
	
	do
	{
		cout<<"\n 1. Add book ";
		cout<<"\n 2. Add tape: ";
		cout<<"\n 3. Display book ";
		cout<<"\n 4. Display tape";
		cout<<"\n 5. Exit:\n";
		cout<<"\n Enter Choice : ";
		
		
		cin>>choice;
		
		switch(choice)
		{
			case 1:
			{
				cout<<"Add Book: \n";
				b[bookCount].get_data();
				bookCount++;
				break;
			}
			case 2:
			{
				cout<<"Add Tape: \n";
				
				t[tapeCount].get_data();
				tapeCount++;
				break;
			}
			case 3:
			{
				cout<<"\nBooks"<<endl;
				cout<<"Title\t\tPrice\t\tPages";
				for(i=0;i<bookCount;i++)
				{
					b[i].display();
				}
				cout<<"\n";
				break;
			}
			case 4:
			{
				cout<<"\nTapes"<<endl;
				cout<<"Tital\t\tPrice\t\tPlaying time";
				for(i=0;i<tapeCount;i++)
				{
					t[i].display();
				}
				cout<<"\n";
				break;
			}
			case 5:
			{
				exit(0);
			}
			default:
			{
				cout<<"Enter valid Choice";
			}
		}
	}
	while(choice!=5);
	
	return 0;
	
}
