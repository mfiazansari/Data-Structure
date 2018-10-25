#include<iostream>				// stream containing the defination of cin,cout etc
#include<stdlib.h>
using namespace::std;			
struct node{					 
	int data;						// data variable to store the data item of a node
	node *next;					// next pointer of type node to store the address of the next node
	node(int d){			// constructor to initialize the data with the passsed value and next to null
		data=d;				
		next=NULL;			// Initially assign NULL to the next of every node
	}
};							// body of the structure closed
class stack{					
	node *head;				// two pointers of type node to store the address of first and last node	
	public:					
		stack(){						// default constructor to initialize head and tail with null
			head=NULL;			// assignment statement
		}
		void push(node *newNode){	//function to insert a node at the front of list it will take the address of new node	
			if(head==NULL){					// condition to check whether the list is empty
				head=newNode;			// to assign head & tail new node if list is empty
			}
			else{							
				newNode->next=head;			// to point the next of new node towards the head
				head=newNode;				// assign new node to head
			}
		}
		void pop(){								//Function to delete the front node
			if(head==NULL){								// condition to check whether the list is empty
				cout<<"empty";							// display empty if the list is empty 
			}
			else{
				node *temp=head;						// create a new pointer of type node to store the address of head
				head=head->next;						// move the head forward i.e. the next node of assigning to the head
				delete temp;							// delete temp i.e. first node
			}
		}
		int top(){
			if(head==NULL){								// condition to check whether the list is empty
				cout<<"empty";							// display empty if the list is empty 
			}
			else
				return head->data;
		}
		void display(){
			if(head==NULL){
				cout<<"Sorry Stack is empty!"<<endl;
			}
			else{
				node *cur=head;
				cout<<"\nThe Stack has: ";
				while(cur!=NULL)
				{
					cout<<cur->data<<"\t";
					cur=cur->next;
				}
			}
		}
};
int main(){
	stack s1;
	int i=1,c,v;
	for( ;i==1;){
		cout<<"\nEnter your choice:"<<endl;
		cout<<"1.	Push \n2.	pop\n3.	Top	\n4.	display"<<endl;cin>>c;
		switch(c){
			case 1:
				{
					cout<<endl<<"Enter value_";cin>>v;node *n=new node(v);s1.push(n);s1.display();
				}
			break;
			case 2:
				{
					cout<<endl<<"Top is: ";s1.pop();
				}
			break;
			case 3:
				{
					cout<<"\nTop is: "<<s1.top()<<endl;
				}
			break;
			case 4:{
				s1.display();
			}
			break;
			case 5:
			{
				exit(EXIT_SUCCESS);
				break;
			}
			default:
				cout<<"Wrong choice is selected please enter again: ";
		}
	}
	return 0;
}

