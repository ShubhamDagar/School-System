//**********************************************************
//	SCHOOL ADMINISTRATION
//**********************************************************
#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include<windows.h>

using namespace std;

//**********************************************************
// STUDENT CLASS
//**********************************************************
void gotoxy (int x, int y)
    {
         COORD coordinates;     // coordinates is declared as COORD
         coordinates.X = x;     // defining x-axis
         coordinates.Y = y;     //defining  y-axis
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);       
    }
class STUDENT
{
	public:
			void addition(void);
			void list(void);
			void class_list(void);
			void record(void);
			void deletion(void);
			void modification(void);
	private :
			int admno;
			char name[30];
			char father[30];
			int age;
			char address[40];
			char clas[8];
} ;


//**********************************************************
// TEACHER CLASS
//**********************************************************

class TEACHER
{
	public:
			void addition(void);
			void list(void);
			void record(void);
			void class_teacher(void);
			void deletion(void);
			void modification(void);
	private :
			int code;
			char name[30];
			int age;
			char designation[15];
			char address[40];
			char clas[8];
} ;


//**********************************************************
// FUNCTION TO ADD NEW RECORD IN STUDENT FILE
//**********************************************************

void STUDENT :: addition(void)
{
	char ch ;
	int tadmno=0;
	fstream f;
	f.open("student.dat",ios::in);
	while (f.read((char*) this, sizeof(STUDENT)))
	tadmno = admno;
	f.close();
	tadmno++;
	do
	{
		system("cls") ;
		gotoxy(30,3) ;
		cout<<"ADDITION OF STUDENT" ;
		gotoxy(29,4) ;
		cout<<"*******************" ;
		gotoxy(5,6) ;
		cout<<"Adm no. " <<tadmno;
		gotoxy(5,7) ;
		fflush(stdin);
		cout<<"Student Name   : " ;
		gets(name);
		gotoxy(5,8) ;
		cout <<"Father's Name : " ;
		fflush(stdin);
		gets(father);
		gotoxy(5,9) ;
		cout<<"Student Address : " ;
		fflush(stdin);
		gets(address);
		gotoxy(5,10) ;
		cout<<"Age : " ;
		cin>>age;
		gotoxy(5,11);
		cout<<"Class : ";
		fflush(stdin);
		gets(clas);
		do
		{
			gotoxy(5,14) ;
			cout<<"Do you want to save (y/n) : " ;
			cin>>ch;
			ch = toupper(ch) ;
		} while (ch != 'Y' && ch != 'N') ;
		if (ch == 'Y')
		{
			f.open("student.dat",ios::app);
			if (!f)
			{
				cout<<"\nCannot open file to write";
				exit(0);
			}
			admno = tadmno;
			f.write((char*) this, sizeof(STUDENT));
			f.close();
			tadmno++;
		}
		do
		{
			gotoxy(5,16);
			cout <<"Do you want to add more (y/n) : " ;
			cin>>ch;
			ch = toupper(ch) ;
		} while (ch != 'Y' && ch != 'N') ;
	} while (ch == 'Y') ;
}


//**********************************************************
// FUNCTION TO DISPLAY LIST OF ALL THE STUDENTS
//**********************************************************

void STUDENT  :: list(void)
{
	system("cls") ;
	int row=6 , found=0 ;
	char ch ;
	gotoxy(33,1) ;
	cout<<"LIST OF STUDENTS" ;
	gotoxy(32,2) ;
	cout<<"****************" ;
	gotoxy(1,4) ;
	cout<<"ADM.NO.     NAME                 FATHER'S NAME            AGE         CLASS" ;
	gotoxy(1,5) ;
	cout<<"******************************************************************************" ;
	fstream f;
	f.open("student.dat", ios::in) ;
	while (f.read((char *) this, sizeof(STUDENT)))
	{
		found = 1 ;
		gotoxy(2,row);
		cout<<admno;
		gotoxy(13,row);
		cout<<name;
		gotoxy(34,row);
		cout<<father;
		gotoxy(59,row);
		cout<<age;
		gotoxy(72,row);
		cout<<clas;
		if (row == 23)
		{
			row = 6 ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			system("cls") ;
			gotoxy(33,1) ;
			cout<<"LIST OF STUDENTS" ;
			gotoxy(32,2) ;
			cout<<"****************" ;
			gotoxy(1,4) ;
			cout<<"ADM.NO.     NAME                 FATHER'S NAME            AGE            CLASS" ;
			gotoxy(1,5) ;
			cout<<"******************************************************************************" ;
		}
		else
			row = row + 1 ;
	}
	if (!found)
	{
		gotoxy(5,10) ;
		cout <<"\7Records not found" ;
	}
	f.close () ;
	getch();
}


//**********************************************************
// FUNCTION TO DISPLAY CLASS WISE LIST OF THE STUDENTS
//**********************************************************

void STUDENT  :: class_list(void)
{
	system("cls") ;
	int row=6 , found=0 ;
	char ch, tclas[8];
	fflush(stdin);
	cout<<"\nEnter the class : ";
	gets(tclas);
	system("cls");
	gotoxy(28,1) ;
	cout<<"CLASS WISE LIST OF STUDENTS" ;
	gotoxy(28,2) ;
	cout<<"***************************" ;
	gotoxy(1,4) ;
	cout<<"ADM.NO.     NAME                 FATHER'S NAME            AGE         CLASS" ;
	gotoxy(1,5) ;
	cout<<"******************************************************************************" ;
	fstream f;
	f.open("student.dat", ios::in) ;
	while (f.read((char *) this, sizeof(STUDENT)))
	{
		if (!strcmp(clas,tclas))
		{
			found = 1 ;
			gotoxy(2,row);
			cout<<admno;
			gotoxy(13,row);
			cout<<name;
			gotoxy(34,row);
			cout<<father;
			gotoxy(59,row);
			cout<<age;
			gotoxy(72,row);
			cout<<clas;
			if (row == 23)
			{
				row = 6 ;
				gotoxy(1,25) ;
				cout <<"Press any key to continue..." ;
				getch() ;
				system("cls") ;
				gotoxy(28,1) ;
				cout<<"CLASS WISE LIST OF STUDENTS" ;
				gotoxy(28,2) ;
				cout<<"***************************" ;
				gotoxy(1,4) ;
				cout<<"ADM.NO.     NAME                 FATHER'S NAME            AGE            CLASS" ;
				gotoxy(1,5) ;
				cout<<"******************************************************************************" ;
			}
			else
				row = row + 1 ;
		}
	}
	if (!found)
	{
		gotoxy(5,10) ;
		cout <<"\7Records not found" ;
	}
	f.close () ;
	getch();
}


//**********************************************************
// FUNCTION TO DISPLAY SINGLE RECORD OF THE STUDENT
//**********************************************************

void STUDENT  :: record(void)
{
	system("cls") ;
	int found=0, tadmno;
	char ch ;
	do
	{
		system("cls");
		found = 0;
		cout<<"       STUDENT RECORD";
		cout<<"\n\nEnter adm no. of the student : ";
		cin>>tadmno;
		fstream f;
		f.open("student.dat", ios::in) ;
		while (f.read((char *) this, sizeof(STUDENT)))
		{
			if (admno == tadmno)
			{
				found = 1 ;
				cout<<"\n\nAdm no. : "<<admno;
				cout<<"\n\nName          : "<<name;
				cout<<"\nFather's name : "<<father;
				cout<<"\nAge           : "<<age;
				cout<<"\nClass         : "<<clas;
				cout<<"\nAddress       : "<<address;
				break;
			}
		}
		if (!found)
			cout<<"\n\n\nRecords not found";
		f.close();
		cout<<"\n\nContinue (y/n)  : ";
		cin>>ch;
	} while (toupper(ch) == 'Y');
}


//**********************************************************
// FUNCTION TO DELETE STUDENT RECORD
//**********************************************************

void STUDENT :: deletion(void)
{
	int tadmno, found=0;
	char ch;
	do
	{
		system("cls");
		cout<<"           DELETION OF STUDENT";
		cout<<"\n\nEnter Student Adm no. to be deleted : ";
		cin>>tadmno;
		fstream f;
		f.open("STUDENT.DAT", ios::in) ;
		fstream temp ;
		temp.open("temp.dat", ios::out) ;
		found = 0;
		while (f.read((char*) this, sizeof(STUDENT)))
		{
			if (admno != tadmno)
				temp.write((char *) this, sizeof(STUDENT));
			else
			{
				found = 1;
				cout<<"\nName : " <<name;
				cout<<"\nFather's name : " <<father;
				cout<<"\nAge : "<<age;
				cout<<"\nAddress : " <<address;
				cout<<"\nClass : "<<clas;
				cout<<"\n\nDo want to delete this record (y/n) : ";
				cin>>ch;
				if (toupper(ch) == 'N')
					temp.write((char *) this, sizeof(STUDENT));
			}
		}
		f.close() ;
		temp.close() ;
		if (found && toupper(ch) != 'N')
		{
			f.open("STUDENT.DAT", ios::out) ;
			temp.open("temp.dat", ios::in) ;
			while (temp.read((char*) this, sizeof(STUDENT)))
				f.write((char *) this, sizeof(STUDENT)) ;
			f.close() ;
			temp.close() ;
			cout<<"\n\nRecord Deleted";
		}
		if (!found)
			cout<<"\n\nRecord not found";
		cout<<"\n\nDo you want to delete more (y/n) ";
		cin>>ch;
	} while (toupper(ch) == 'Y');
}


//**********************************************************
// FUNCTION TO MODIFY THE STUDENT RECORD
//**********************************************************

void STUDENT :: modification(void)
{
	int tadmno, found=0;
	int tage;
	char tname[30], tfather[30], taddress[40], tclas[8];
	char ch;
	do
	{
		system("cls");
		cout<<"           MODIFICATION OF STUDENT";
		cout<<"\n\nEnter Student Adm no. to be modified : ";
		cin>>tadmno;
		fstream f;
		f.open("STUDENT.DAT", ios::in) ;
		fstream temp ;
		temp.open("temp.dat", ios::out) ;
		found = 0;
		while (f.read((char*) this, sizeof(STUDENT)))
		{
			if (admno != tadmno)
				temp.write((char *) this, sizeof(STUDENT));
			else
			{
				found = 1;
				cout<<"\nEnter New Data ---\n\n";
				cout<<"Student Name   : " ;
				fflush(stdin);
				gets(tname);
				cout <<"Father's Name : " ;
				fflush(stdin);
				gets(tfather);
				cout<<"Student Address : " ;
				fflush(stdin);
				gets(taddress);
				cout<<"Age : " ;
				cin>>tage;
				cout<<"Class : ";
				fflush(stdin);
				gets(tclas);
				cout<<"\nDo want to modify this record (y/n) : ";
				cin>>ch;
				if (toupper(ch) == 'N')
					temp.write((char *) this, sizeof(STUDENT));
				else
				{
					strcpy(name,tname);
					strcpy(father,tfather);
					age = tage;
					strcpy(address,taddress);
					strcpy(clas,tclas);
					temp.write((char *) this, sizeof(STUDENT));
				}
			}
		}
		f.close() ;
		temp.close() ;
		if (found && toupper(ch) != 'N')
		{
			f.open("STUDENT.DAT", ios::out) ;
			temp.open("temp.dat", ios::in) ;
			while (temp.read((char*) this, sizeof(STUDENT)))
				f.write((char *) this, sizeof(STUDENT)) ;
			f.close() ;
			temp.close() ;
			cout<<"\n\nRecord Modified";
		}
		if (!found)
			cout<<"\n\nRecord not found";
		cout<<"\n\nDo you want to modify more (y/n) ";
		cin>>ch;
	} while (toupper(ch) == 'Y');
}


//**********************************************************
// FUNCTION TO ADD NEW RECORD IN TEACHERS FILE
//**********************************************************

void TEACHER :: addition(void)
{
	char ch ;
	int tcode=0;
	fstream f;
	f.open("teacher.dat",ios::in);
	while (f.read((char*) this, sizeof(TEACHER)))
	tcode = code;
	f.close();
	tcode++;
	do
	{
		system("cls") ;
		gotoxy(30,3) ;
		cout<<"ADDITION OF TEACHER" ;
		gotoxy(29,4) ;
		cout<<"*******************" ;
		gotoxy(5,6) ;
		cout<<"Code : " <<tcode;
		gotoxy(5,7) ;
		cout<<"Teacher Name   : " ;
		fflush(stdin);
		gets(name);
		gotoxy(5,8) ;
		cout <<"Age : " ;
		cin>>age;
		gotoxy(5,9) ;
		cout<<"Address : " ;
		fflush(stdin);
		gets(address);
		gotoxy(5,10) ;
		cout<<"Designation : " ;
		fflush(stdin);
		gets(designation);
		gotoxy(5,11);
		cout<<"Class : ";
		fflush(stdin);
		gets(clas);
		do
		{
			gotoxy(5,14) ;
			cout<<"Do you want to save (y/n) : " ;
			cin>>ch;
			ch = toupper(ch) ;
		} while (ch != 'Y' && ch != 'N') ;
		if (ch == 'Y')
		{
			f.open("teacher.dat",ios::app);
			if (!f)
			{
				cout<<"\nCannot open file to write";
				exit(0);
			}
			code = tcode;
			f.write((char*) this, sizeof(TEACHER));
			f.close();
			tcode++;
		}
		do
		{
			gotoxy(5,16);
			cout <<"Do you want to add more (y/n) : " ;
			cin>>ch;
			ch = toupper(ch) ;
		} while (ch != 'Y' && ch != 'N') ;
	} while (ch == 'Y') ;
}


//**********************************************************
// FUNCTION TO DISPLAY LIST OF ALL THE TEACHER
//**********************************************************

void TEACHER  :: list(void)
{
	system("cls") ;
	int row=6 , found=0 ;
	char ch ;
	gotoxy(33,1) ;
	cout<<"LIST OF TEACHERS" ;
	gotoxy(32,2) ;
	cout<<"****************" ;
	gotoxy(1,4) ;
	cout<<"CODE      NAME                 AGE           DESIGNATION               CLASS" ;
	gotoxy(1,5) ;
	cout<<"******************************************************************************" ;
	fstream f;
	f.open("teacher.dat", ios::in) ;
	while (f.read((char *) this, sizeof(TEACHER)))
	{
		found = 1 ;
		gotoxy(2,row);
		cout<<code;
		gotoxy(11,row);
		cout<<name;
		gotoxy(33,row);
		cout<<age;
		gotoxy(47,row);
		cout<<designation;
		gotoxy(74,row);
		cout<<clas;
		if (row == 23)
		{
			row = 6 ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue..." ;
			getch() ;
			system("cls") ;
			gotoxy(33,1) ;
			cout<<"LIST OF TEACHERS" ;
			gotoxy(32,2) ;
			cout<<"****************" ;
			gotoxy(1,4) ;
			cout<<"CODE      NAME                 AGE           DESIGNATION               CLASS" ;
			gotoxy(1,5) ;
			cout<<"******************************************************************************" ;
		}
		else
			row = row + 1 ;
	}
	if (!found)
	{
		gotoxy(5,10) ;
		cout <<"\7Records not found" ;
	}
	f.close () ;
	getch();
}


//**********************************************************
// FUNCTION TO DISPLAY SINGLE RECORD OF TEACHER
//**********************************************************

void TEACHER  :: record(void)
{
	system("cls") ;
	int found=0, tcode;
	char ch ;
	do
	{
		system("cls");
		found = 0;
		cout<<"       TEACHER RECORD";
		cout<<"\n\nEnter Code of the Teacher : ";
		cin>>tcode;
		fstream f;
		f.open("teacher.dat", ios::in) ;
		while (f.read((char *) this, sizeof(TEACHER)))
		{
			if (code == tcode)
			{
				found = 1 ;
				cout<<"\n\nCode no. : "<<code;
				cout<<"\n\nName          : "<<name;
				cout<<"\nDesignation   : "<<designation;
				cout<<"\nAge           : "<<age;
				cout<<"\nClass         : "<<clas;
				cout<<"\nAddress       : "<<address;
				break;
			}
		}
		if (!found)
			cout<<"\n\n\nRecord not found";
		f.close();
		cout<<"\n\nContinue (y/n)  : ";
		cin>>ch;
	} while (toupper(ch) == 'Y');
}


//**********************************************************
// FUNCTION TO DISPLAY THE CLASS TEACHER RECORD
//**********************************************************

void TEACHER  :: class_teacher(void)
{
	system("cls") ;
	int found=0;
	char ch, tclas[8];
	do
	{
		system("cls");
		found = 0;
		cout<<"       CLASS TEACHER RECORD";
		cout<<"\n\nEnter the Class for which you want to see the teacher record : ";
		fflush(stdin);
		gets(tclas);
		fstream f;
		f.open("teacher.dat", ios::in) ;
		while (f.read((char *) this, sizeof(TEACHER)))
		{
			if (!strcmp(clas,tclas))
			{
				found = 1 ;
				cout<<"\n\nCode no. : "<<code;
				cout<<"\n\nName          : "<<name;
				cout<<"\nDesignation   : "<<designation;
				cout<<"\nClass         : "<<clas;
				break;
			}
		}
		if (!found)
			cout<<"\n\n\nRecords not found";
		f.close();
		cout<<"\n\nContinue (y/n)  : ";
		cin>>ch;
	} while (toupper(ch) == 'Y');
}


//**********************************************************
// FUNCTION TO DELETE THE TEACHER RECORD
//**********************************************************

void TEACHER :: deletion(void)
{
	int tcode, found=0;
	char ch;
	do
	{
		system("cls");
		cout<<"           DELETION OF TEACHER";
		cout<<"\n\nEnter Teacher's code to be deleted : ";
		cin>>tcode;
		fstream f;
		f.open("TEACHER.DAT", ios::in) ;
		fstream temp ;
		temp.open("temp.dat", ios::out) ;
		found = 0;
		while (f.read((char*) this, sizeof(TEACHER)))
		{
			if (code != tcode)
				temp.write((char *) this, sizeof(TEACHER));
			else
			{
				found = 1;
				cout<<"\nName : " <<name;
				cout<<"\nAge : "<<age;
				cout<<"\nAddress : " <<address;
				cout<<"\nDesignation : "<<designation;
				cout<<"\nClass : "<<clas;
				cout<<"\n\nDo want to delete this record (y/n) : ";
				cin>>ch;
				if (toupper(ch) == 'N')
					temp.write((char *) this, sizeof(TEACHER));
			}
		}
		f.close() ;
		temp.close() ;
		if (found && toupper(ch) != 'N')
		{
			f.open("TEACHER.DAT", ios::out) ;
			temp.open("temp.dat", ios::in) ;
			while (temp.read((char*) this, sizeof(TEACHER)))
				f.write((char *) this, sizeof(TEACHER)) ;
			f.close() ;
			temp.close() ;
			cout<<"\n\nRecord Deleted";
		}
		if (!found)
			cout<<"\n\nRecord not found";
		cout<<"\n\nDo you want to delete more (y/n) ";
		cin>>ch;
	} while (toupper(ch) == 'Y');
}


//**********************************************************
// FUNCTION TO MODIFY THE TEACHER RECORD
//**********************************************************

void TEACHER :: modification(void)
{
	int tcode, found=0;
	int tage;
	char tname[30], tdesignation[30], taddress[40], tclas[8];
	char ch;
	do
	{
		system("cls");
		cout<<"           MODIFICATION OF TEACHER";
		cout<<"\n\nEnter Teacher's code to be modified : ";
		cin>>tcode;
		fstream f;
		f.open("TEACHER.DAT", ios::in) ;
		fstream temp ;
		temp.open("temp.dat", ios::out) ;
		found = 0;
		while (f.read((char*) this, sizeof(TEACHER)))
		{
			if (code != tcode)
				temp.write((char *) this, sizeof(TEACHER));
			else
			{
				found = 1;
				cout<<"\nEnter New Data ---\n\n";
				cout<<"Teacher's Name   : " ;
				fflush(stdin);
				gets(tname);
				cout <<"Designation : " ;
				fflush(stdin);
				gets(tdesignation);
				cout<<"Address : " ;
				fflush(stdin);
				gets(taddress);
				cout<<"Age : " ;
				cin>>tage;
				cout<<"Class : ";
				fflush(stdin);
				gets(tclas);
				cout<<"\nDo want to modify this record (y/n) : ";
				cin>>ch;
				if (toupper(ch) == 'N')
					temp.write((char *) this, sizeof(TEACHER));
				else
				{
					strcpy(name,tname);
					strcpy(designation,tdesignation);
					age = tage;
					strcpy(address,taddress);
					strcpy(clas,tclas);
					temp.write((char *) this, sizeof(TEACHER));
				}
			}
		}
		f.close() ;
		temp.close() ;
		if (found && toupper(ch) != 'N')
		{
			f.open("TEACHER.DAT", ios::out) ;
			temp.open("temp.dat", ios::in) ;
			while (temp.read((char*) this, sizeof(TEACHER)))
				f.write((char *) this, sizeof(TEACHER)) ;
			f.close() ;
			temp.close() ;
			cout<<"\n\nRecord Modified";
		}
		if (!found)
			cout<<"\n\nRecord not found";
		cout<<"\n\nDo you want to modify more (y/n) ";
		cin>>ch;
	} while (toupper(ch) == 'Y');
}

//**********************************************************
// MAIN FUNCTION
//**********************************************************

int main(void)
{
	char ch, ch1, ch2, ch3;
	STUDENT st;
	TEACHER th;
	do
	{
		system("cls") ;
		gotoxy(29,6) ;
		cout<<"SCHOOL ADMINISTRATION " ;
		gotoxy(29,7) ;
		cout<<"~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(30,10) ;
		cout<<"1. Add Student Record" ;
		gotoxy(30,11) ;
		cout<<"2. Add Teacher Record" ;
		gotoxy(30,12) ;
		cout<<"3. Edit" ;
		gotoxy(30,13) ;
		cout<<"4. Reports" ;
		gotoxy(30,14) ;
		cout<<"5. Query" ;
		gotoxy(30,15) ;
		cout<<"0. Quit" ;
		gotoxy(30,18) ;
		cout<<"Enter your choice : " ;
		cin>>ch;
		switch(ch)
		{
			case '1':
				st.addition();
				break;
			case '2':
				th.addition();
				break;
			case '3':
				do
				{
					system("cls") ;
					gotoxy(32,8) ;
					cout<<"E D I T  M E N U";
					gotoxy(32,9) ;
					cout<<"~~~~~~~~~~~~~~~~" ;
					gotoxy(34,11) ;
					cout<<"1. Modify Student" ;
					gotoxy(34,12) ;
					cout<<"2. Delete Student" ;
					gotoxy(34,13) ;
					cout<<"3. Modify Teacher" ;
					gotoxy(34,14) ;
					cout<<"4. Delete Teacher" ;
					gotoxy(34,15) ;
					cout<<"0. EXIT" ;
					gotoxy(31,17) ;
					cout<<"Enter your choice : " ;
					cin>>ch1;
					switch(ch1)
					{
						case '1':
							st.modification();
							break;
						case '2':
							st.deletion();
							break;
						case '3':
							th.modification();
							break;
						case '4':
							th.deletion();
							break;
					}
				} while (ch1 != '0');
				break;
			case '4':
				do
				{
					system("cls") ;
					gotoxy(33,8) ;
					cout<<"R E P O R T S";
					gotoxy(33,9) ;
					cout<<"~~~~~~~~~~~~~" ;
					gotoxy(34,11) ;
					cout<<"1. Student's List" ;
					gotoxy(34,12) ;
					cout<<"2. Teacher's List" ;
					gotoxy(34,13) ;
					cout<<"3. Classwise Student List" ;
					gotoxy(34,14) ;
					cout<<"0. EXIT" ;
					gotoxy(31,16) ;
					cout<<"Enter your choice : " ;
					cin>>ch2;
					switch(ch2)
					{
						case '1':
							st.list();
							break;
						case '2':
							th.list();
							break;
						case '3':
							st.class_list();
							break;
					}
				} while (ch2 != '0');
				break;
			case '5':
				do
				{
					system("cls") ;
					gotoxy(35,8) ;
					cout<<"Q U E R Y";
					gotoxy(35,9) ;
					cout<<"~~~~~~~~~" ;
					gotoxy(34,11) ;
					cout<<"1. Student's Record" ;
					gotoxy(34,12) ;
					cout<<"2. Teacher's Record" ;
					gotoxy(34,13) ;
					cout<<"3. Class Teacher" ;
					gotoxy(34,14) ;
					cout<<"0. EXIT" ;
					gotoxy(31,16) ;
					cout<<"Enter your choice : " ;
					cin>>ch3;
					switch(ch3)
					{
						case '1':
							st.record();
							break;
						case '2':
							th.record();
							break;
						case '3':
							th.class_teacher();
							break;
					}
				} while (ch3 != '0');
				break;
		}
	} while (ch != '0');
	return 0;
}
