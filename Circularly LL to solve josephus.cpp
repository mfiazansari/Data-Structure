#include<iostream>				// stream containing the defination of cin,cout etc
#include<stdlib.h>
using namespace::std;			
struct node{					 
	int data;						// data variable to store the data item of a node
	node *next;					// next pointer of type node to store the address of the next node
	node(int d);
};							// body of the structure closed
class CircList{					
	node *head,*tail;		// two pointers of type node to store the address of first and last node	
	public:					
		CircList();
		void insertLast(node *newNode);
		int count();
		void display();
		int servivor(int s);
};
int main(){
	CircList l1;
	int d=0,i=1,c=0,s=0;
	for(;i==1;){
		cout<<"\nEnter Your Choice: "<<endl;
		cout<<"1.	Enter 1 to add number \n2.	See the list \n3.	Choose a Servivor\n4.	EXIT"<<endl;cin>>c;
		if(c==1){
			cout<<endl<<"Enter number: ";cin>>d;node *n=new node(d);l1.insertLast(n);
			l1.display();
		}
		else if(c==2){
			l1.display();
		}
		else if(c==3){
			if(l1.count()==0)
				cout<<endl<<"Please Enter some numbers and then try again"<<endl;
			else{
				l1.display();
				cout<<endl<<"Enter the order of men to be killed e.g. 2nd,3rd,4rth etc : ";cin>>s;
				cout<<endl<<"Servivor is: "<<l1.servivor(s);
			}
		}		
		else if(c==4)
			exit(EXIT_SUCCESS);
		else
			cout<<endl<<"Wrong choice selected"<<endl;
	}
	return 0;
	}

node::node(int d){			
	data=d;				
	next=NULL;			
}
CircList::CircList(){						
	head=tail=NULL;			
}
void CircList::insertLast(node *newNode){		
		if(head==NULL){					
			head=tail=newNode;
			tail->next=head;						
		}
	else{							
		tail->next=newNode;
		newNode->next=head;			
		tail=newNode;				
					
	}
}
int CircList::count(){
	node *cur=head;
	int c=1;
	while(cur!=tail){
		cur=cur->next;
		c++;
	}
	return c;
}
void CircList::display(){
	if(head==NULL){
		cout<<"Sorry List is empty!"<<endl;
	}
	else{
		node *cur=head;
		cout<<"\nList conatins "<<count()<<" numbers as follows: ";
		while(cur!=tail)
		{
		cout<<cur->data<<"\t";
		cur=cur->next;
		}
		cout<<cur->data<<"\t"<<endl;
	}
}
int CircList::servivor(int s){
	node *cur=head;
	node *prev=tail;
	while(cur!=prev){
		for(int i=1;i<s;i++){
			prev=cur;
			cur=cur->next;
		}
		cout<<endl<<cur->data<<" is killed";
		prev->next=cur->next;
		node *temp=cur;
		cur=cur->next;
		delete temp;
		
	}
	return cur->data;
}
