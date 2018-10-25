#include<iostream>
using namespace::std;
class stack{
	int top,size,*array=new int[size];
	public:
		stack(int s){
			size=s;
			top=-1;
		}
		void push(int x){
			if(top==size-1)
				cout<<"Stack is full";
			else
				array[++top]=x;
		}
		int pop(){
			if(top==-1)
				cout<<"Stack is empty";
			else
				return array[top--];
		}
		void display(){
			if(top==-1)
				cout<<"Stack is empty";
			else{
				cout<<endl<<"The Stack has: ";
				for(int i=top;i>-1;i--)
					cout<<array[i]<<"\t";
			}
			cout<<endl;
		}
		void seatop(){
			if(top==-1)
				cout<<"Stack is empty";
			else
				cout<<endl<<"Top is: "<<array[top]<<endl;
		}
};
int main(){
	int s;cout<<"Enter size: ";cin>>s;
	stack s1(s);
	int i=1,c,n;
	for( ;i==1;){
		cout<<"\nEnter your choice:"<<endl;
		cout<<"1.	Push \n2.	pop\n3.	Top	\n4.	display"<<endl;cin>>c;
		switch(c){
			case 1:
				{
					cout<<endl<<"Enter value";cin>>n;s1.push(n);s1.display();
				}
			break;
			case 2:
				{
					cout<<endl<<"Top is: "<<s1.pop();s1.display();
				}
			break;
			case 3:
				{
					s1.seatop();
				}
			break;
			case 4:{
				s1.display();
			}
			break;
			default:
				cout<<"Wrong choice is selected please enter again: ";
		}
		cout<<endl<<"Enter 1 to select choice again:";cin>>i;
	}
	return 0;
}
