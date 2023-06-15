/*Develop a program in C++ to create a database of student’s information system containing the
following information: Name, Roll number, Class, Division, Date of Birth, Blood group,
Contact address, Telephone number, Driving license no. and other. Construct the database with
suitable member functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer and dynamic memory
allocation operators-new and delete.

Name : Deep Chhabhaiya
Roll no. : 17
Class : SE (AIDS)
Div : A
*/
#include <iostream>
#include<string.h>
using namespace std;
class student
{
    public:
    int rno;
    char clas[10];
    int srno;
    long int tele;
    char name[10];
    char bloodgrp[10];
    char div;
    char DOB[10];
    static int count;
    void getdata();
    friend void display(student&obj);
    
    student() //constructor
    {
        rno=0;
        cout<<"\tconstructor\n";
        rno=count;
        count++;
    }
    ~student() //destructor
    {
        cout<<"\nDestructor";
        cout<<"\nDestroying the object";
        count++;
    }
    static void getcount()
    {
        cout<<"Constructor count is"<<count<<endl;
    }
    student(student&obj)
    {
        rno=obj.rno;
        strcpy(name,obj.name);
        strcpy(DOB,obj.DOB);
        strcpy(clas,obj.clas);
        strcpy(bloodgrp,obj.bloodgrp);
        div=obj.div;
        tele=obj.tele;
        srno=count;
        count++;
    }
};//end of class

    int student::count=0;
    void student:: getdata()
{
    cout<<"\n"<<"Enter rno: ";
    cin>>rno;
    cout<<"\n"<<"Enter name: ";
    cin>>name;
    cout<<"\n"<<"Enter DOB: ";
    cin>>DOB;
    cout<<"\n"<<"Enter Bloodgroup: ";
    cin>>bloodgrp;
    cout<<"\n"<<"Enter class: ";
    cin>>clas;
    cout<<"\n"<<"Enter division: ";
    cin>>div;
    cout<<"\n"<<"Enter telephone no: ";
    cin>>tele;
}

void display(student & obj)//friend func
{
    
    cout<<"\n"<<obj.rno;
    cout<<"\t"<<obj.name;
    cout<<"\t"<<obj.DOB;
    cout<<"\t   "<<obj.bloodgrp;
    cout<<"\t\t"<<obj.clas;
    cout<<"\t"<<obj.div;
    cout<<"\t"<<obj.tele<<endl;
}
int main()
{
    student s1;
    student s2(s1);//copy constructor
    student :: getcount(); //accessing static function
    
  
    
     student*s[50];//array
     int i,n;
     cout<<"\n How many students objects do you want to create?";
     cin>>n;
     
     for(i=0;i<n;i++)
     {
         s[i]=new student();
     }
     for(i=0;i<n;i++)
     {
         s[i]->getdata();
     }
       cout<<"\n All the details are as below: \n";
    cout<<"Roll\tName\tDOB\tBloodgroup\tClass\tDiv\tPhone\n";
     for(i=0;i<n;i++)
     {
         display (*s[i]);
     }
    
    student::getcount(); //accessing static function
    
    for(i=0;i<n;i++)
    {
        delete (s[i]);
    }
    
    return 0;
}






/*
 All the details are as below: 
Roll	Name	DOB	Bloodgroup	Class	Div	Phone

1	Deep	19/05	   o		se	a	9854123532

2	ram	21/2	   a		se	a	8542154863

3	aditya	10/10	   ab		se	a	8541236549

4	disha	12/3	   b		se	a	7441258963

5	vidya	85/6	   ab-		se	a	9632587410
*/

