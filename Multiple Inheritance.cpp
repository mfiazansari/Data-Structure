#include<iostream>
using namespace::std;
class person{
	private:
		string name,gender;
		int age;
	public:
		void setP(string n,string g,int a){
			name=n;
			gender=g;
			age=a;
		}
		string getName(){
			return name;
		}
		int getAge(){
			return age;
		}
		string getGender(){
			return gender;
		}
};
class employee{
	string e_name;
	int daily_wages;
	public:
	void set_E(string n,int d){
		e_name=n;
		daily_wages=d;
	}
	string get_e_name(){
		return e_name;
	}
	int getWages(){
		return daily_wages;
	}	
};
class teacher:public person,employee{
	char grade;
	public:
		
		void set(string n,string gend,int a,string e_n,int d,char g){
			setP(n,gend,a);
			set_E(e_n,d);
			grade=g;
		}
		char getGrade(){
			return grade;
		}
		void print(){
			cout<<"\nName= "<<getName();
			cout<<"\nage = "<<getAge();
			cout<<"\nGender = "<<getGender();
			cout<<"\nEmployee Name = "<<get_e_name();
			cout<<"\nDaily Wages = "<<getWages();
			cout<<"\nGrade = "<<grade;
		}
};
int main(){
	teacher t1;
	t1.set("Ali","Male",20,"Ahmad",2000,'A');
	t1.print();
	
	
	return 0;
}
