#include<iostream>
#include<stdlib.h>
using namespace::std;
struct node{
	int d;
	node *next;
	public:
		node(int a){
			d=a;
			next=NULL;
		}
};
class stack{
	node *top;
	public:
		stack(){
			top=NULL;
		}
		void push(node *n){
			if(top==NULL){
				top=n;
			}
			else{
				n->next=top;
				top=n;
			}
		}
		void pop(){
			if(top==NULL)
				cout<<"Stack is empty";
			else{
				node *temp=top;
				top=top->next;
				delete temp;
			}
		}
		int Top(){
			return top->d;
		}
		void display(){
			if(top==NULL)
				cout<<"\nEmpty"<<endl;
			else{
				cout<<"Stack contain: ";
				node *cur=top;
				while(cur!=NULL){
					cout<<cur->d<<"\t";
					cur=cur->next;
				}
			}
			cout<<endl;
		}
};
int main(){
	stack s1;
	int i=1,c,d;
	for( ;i==1;){
		cout<<"Enter your choice:"<<endl;
		cout<<"1.	Push \n2.	pop\n3.	Top	\n4.	display\n5.	Exit"<<endl;cin>>c;
		switch(c){
			case 1:
				{
					cout<<endl<<"Enter value: ";cin>>d;node *n=new node(d);s1.push(n);s1.display();
				}
			break;
			case 2:
				{
					s1.pop();s1.display();
				}
			break;
			case 3:
				{
					cout<<"Top is: "<<s1.Top()<<endl;
				}
			break;
			case 4:{
				s1.display();
			}
			break;
			case 5:
				exit(EXIT_SUCCESS);
				break;
			default:
				cout<<"Wrong choice is selected please enter again: ";
		}
	}
	return 0;
}


