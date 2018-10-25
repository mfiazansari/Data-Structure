#include<iostream>				
#include<stdlib.h>
using namespace::std;			
class node{	
	public:				 
	int data;						
	node *next;					
	node(int d);
};							
class CList{					
	node *head;
	node *tail;			
	public:					
		CList();
		void insertLast(node *newNode);
		int count();
		void display();
		void leader(int s);
};
int main(){
	CList l1;
	int d=0,i=1,c=0,s=0;
	for(;i==1;){
		cout<<"\nEnter Your Choice: "<<endl;
		cout<<"1.	Enter 1 to add number :";
		cout<<"\n2.	See the list"; 
		cout<<"\n3.	Choose a Servivor";
		cout<<"\n4.	EXIT"<<endl;
		cin>>c;
		if(c==1){
			cout<<endl<<"Enter number: ";
			cin>>d;
			node *n=new node(d);
			l1.insertLast(n);
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
				cout<<endl<<"Enter the order of men to be skipped: ";
				cin>>s;
				l1.leader(s);
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
CList::CList(){						
	head=tail=NULL;			
}
void CList::insertLast(node *newNode){		
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
int CList::count(){
	node *cur=head;
	int c=1;
	while(cur!=tail){
		cur=cur->next;
		c++;
	}
	return c;
}
void CList::display(){
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
void CList::leader(int s){
	node *cur=head;
	node *prev=tail;
	while(cur!=prev){
		for(int i=1;i<=s;i++){
			prev=cur;
			cur=cur->next;
		}
		cout<<endl<<cur->data<<" is skipped";
		prev->next=cur->next;
		node *temp=cur;
		cur=cur->next;
		delete temp;
		
	}
	cout<<endl<<"Leader is: "<<cur->data;
}
