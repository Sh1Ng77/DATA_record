//file handling - Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and read the information from the file.
  
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream outf ("deep.txt");	
				
	char name[30];
	int roll_no;
	char address[50];
	cout<<"\nEnter roll no:";
	cin>>roll_no;
	outf<<roll_no<<endl;	
	cout<<"\nEnter name:";
	cin.ignore();
	cin.getline(name,30);
	outf<<name<<endl;
	cout<<"\nEnter address:";
	cin.getline(address,50);
	outf<<address<<endl;
	outf.close();		
	
	ifstream inf;
	
	inf.open("student.txt");				
	inf>>roll_no;
	inf>>name;
	inf>>address;		
	cout<<roll_no<<"\n"<<name<<"\n"<<address<<endl;  
	inf.close();		
	return 0;
}
	
 

