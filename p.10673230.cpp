#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
 
using namespace std;
 
 
 
class student
{
	int idnum;
	char name[50];
	double score;
	char grade;
	void grading();	
public:
	void getdata();		
	void show_profile() const;	
	void show_tabular() const;
	void get_courses(char courses[][30],int r, int c);
	int getIDNum() const;
}; 
 
 
void student::grading()
{
	
	if(score>=80)
		grade='A';
	else if(score>=70)
		grade='B';
	else if(score>=65)
		grade='C';
	else if(score>=50)
		grade='C';
	else if(score>=45)
		grade='D';
	else if(score>=35)
		grade='E';
	else if(score>=30)
		grade='F';

}
 
void student::getdata()
{
	cout<<"\nEnter the student id ";
	cin>>idnum;
	cout<<"\n\nEnter student's Name: ";
	cin.ignore();
	cin.getline(name,50);
	}

void student::get_courses(char courses[][30],int r, int c){
	cout<<"enter the courses for the semester\n";
	cin>>c;
	cout<<"enter student courses\n";
	for (int r=0;r<15;r++){
		for(int c=0;c<30;c++)
		cin.get(courses[15][30]);
	}
}

 
void student::show_profile() const
{
	cout<<"\nID Number: "<<idnum;
	cout<<"\nName: "<<name;
cout<<"the courses for the semester are:"<<student::get_courses(char courses[][30],18, 30)
}

void add_staff(){
	string name;string course;int idnum;
	cout<<"Enter staff id\n";
	cin>> idnum;
	cout<<"enter name\n";
	cin>>name;
	cout<<"what course are you taking htis semester\n";
	cin>> course;
}
 
 void show_staff_data(){
 	add_staff();
 }
int  student::getIDNum() const
{
	return idnum;
}
 
 
 
void SaveStudent();	
void display_allData();	
void Searchdisplay(int);	
void modifyStudent(int);	
void deleteStudent(int);	
void DisplayClassResult();	
void DisplayResult();			
	
 
 
 
 
void writeStudent(){
	student st;
	ofstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
	outFile.close();
    	cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();
}
 
 
 
void display_allData(){
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.show_profile();
		
	}
	inFile.close();
	cin.ignore();
	cin.get();
}
 
 
  void display_sp(int n){
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.getIDNum()==n)
		{
	  		 st.show_profile();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}
 
 
void modifyStudent(int n)
{
	bool found=false;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		
	}
    	while(!File.eof() && found==false)
	{
 
		File.read(reinterpret_cast<char *> (&st), sizeof(student));
		if(st.getIDNum()==n)
		{
			st.show_profile();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.getdata();
		    	int pos=(-1)*static_cast<int>(sizeof(st));
		    	File.seekp(pos,ios::cur);
		    	File.write(reinterpret_cast<char *> (&st), sizeof(student));
		    	cout<<"\n\n\t Record Updated";
		    	found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
	cin.ignore();
	cin.get();
}
 
 
 
void delete_student(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.getIDNum()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cin.ignore();
	cin.get();
}
 
 
void class_result()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";

	cout<<"ID.No    Name     Course      Grade"<<endl;

	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.show_tabular();
	}
	cin.ignore();
	cin.get();
	inFile.close();
}
 
 
 
 
int main()
{
	char ch;
	int num;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); 
	do
	{
	system("cls");

	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.ADD STAFF RECORD";
	cout<<"\n\n\t7. DISPLAY CLASS RESULT";
	cout<<"\n\n\t8. DISPLAY STAFF RECORD";
	cout<<"\n\n\t9. EXIT";

	cout<<"\n\n\tPlease Enter Your Choice (1-7): ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
	case '1':	writeStudent(); break;
	case '2':	display_allData(); break;
	case '3':	cout<<"\n\n\tPlease Enter Student's ID number: "; cin>>num;
				display_sp(num); break;
	case '4':	cout<<"\n\n\tPlease Enter Student's ID number: "; cin>>num;
			modifyStudent(num);break;
	case '5':	cout<<"\n\n\tPlease Enter Student's ID number: "; cin>>num;
			delete_student(num);break;
	case '6' :	add_staff(); break;
    case '7':
    	class_result();break;
    case '8':
		
	case '9':	exit(0);;
	default:	cout<<"\a"; 
		 }
}
	while(ch!='9');
 
	return 0;
	}


