#include<iostream>
using namespace::std;
class date{
	public:
		int day,year,month;
		date(){
			day=year=month=0;
		}
};
class employee{
	string name;
	date joinDate,dateOfBirth;
	public:
		employee(string s){
			name=s;
		}
		void getEmpJoinDate(){
			cout<<endl<<name<<" Please Enter the Joining date: "<<endl;
			cout<<"1.	Enter day:	";cin>>joinDate.day;
			cout<<endl<<"2.	Enter month:	";cin>>joinDate.month;
			cout<<endl<<"3.	Enter year:	";cin>>joinDate.year;
		}
		void getEmpDateOfBirth(){
			cout<<endl<<name<<" Please Enter the Date of Birth: "<<endl;
			cout<<"1.	Enter day:	";cin>>dateOfBirth.day;
			cout<<endl<<"2.	Enter month:	";cin>>dateOfBirth.month;
			cout<<endl<<"3.	Enter year:	";cin>>dateOfBirth.year;
		}
		void showEmpJoinDate(){
			cout<<endl<<name<<" Your Joining Date: "<<joinDate.day<<" / "<<joinDate.month<<" / "<<joinDate.year<<endl;
		}
		void showEmpDateOfBirth(){
			cout<<endl<<name<<" Your Date of Birth: "<<dateOfBirth.day<<" / "<<dateOfBirth.month<<" / "<<dateOfBirth.year<<endl;
		}
		bool checkDate(){
			if(joinDate.year>2010)
				return 1;
			else
				return 0;
		}
		string getName(){
			return name;
		}
		bool checkAge(){
			if(dateOfBirth.year>1975)
				return 1;
			else
				return 0;
		}
};
int main(){
	string nam;
	cout<<endl<<"Enter Your name: ";cin>>nam;cout<<endl;
	employee e1(nam);
	e1.getEmpJoinDate();
	e1.showEmpJoinDate();
	e1.getEmpDateOfBirth();
	e1.showEmpDateOfBirth();
	if(e1.checkDate()==1){
		cout<<endl<<e1.getName()<<" is joined in previous 5 yrears."<<endl;
	}
	else{
		cout<<endl<<e1.getName()<<" did not join in previous 5 yrears."<<endl;
	}
	if(e1.checkAge()==1){
		cout<<endl<<e1.getName()<<" is less than 40 years old."<<endl;
	}
	else{
		cout<<endl<<e1.getName()<<" is not less than 40 years old."<<endl;
	}
	cout<<endl<<"Enter Your name: ";cin>>nam;cout<<endl;
	employee e2(nam);
	e2.getEmpJoinDate();
	e2.showEmpJoinDate();
	e2.getEmpDateOfBirth();
	e2.showEmpDateOfBirth();
	if(e2.checkDate()==1){
		cout<<endl<<e2.getName()<<" is joined in previous 5 yrears."<<endl;
	}
	else{
		cout<<endl<<e2.getName()<<" did not join in previous 5 yrears."<<endl;
	}
	if(e2.checkAge()==1){
		cout<<endl<<e2.getName()<<" is less than 40 years old."<<endl;
	}
	else{
		cout<<endl<<e2.getName()<<" is not less than 40 years old."<<endl;
	}
	cout<<endl<<"Enter Your name: ";cin>>nam;cout<<endl;
	employee e3(nam);
	e3.getEmpJoinDate();
	e3.showEmpJoinDate();
	e3.getEmpDateOfBirth();
	e3.showEmpDateOfBirth();
	if(e3.checkDate()==1){
		cout<<endl<<e3.getName()<<" is joined in previous 5 yrears."<<endl;
	}
	else{
		cout<<endl<<e3.getName()<<" did not join in previous 5 yrears."<<endl;
	}
	if(e3.checkAge()==1){
		cout<<endl<<e3.getName()<<" is less than 40 years old."<<endl;
	}
	else{
		cout<<endl<<e3.getName()<<" is not less than 40 years old."<<endl;
	}
	return 0;
}
