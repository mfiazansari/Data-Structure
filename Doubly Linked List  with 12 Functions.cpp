#include<iostream>
#include <stdlib.h>
using namespace::std;
struct node{
	int data;
	node *next,*prev;
	node(int d){
		data=d;
		next=prev=NULL;
	}
};
class list{
	node *head,*tail;
	public:
		list(){
			head=NULL;
			tail=NULL;
		}
		void insertFront(node *newNode){
			if(head==NULL){
				head=tail=newNode;
			}
			else{
				newNode->next=head;
				head->prev=newNode;
				head=newNode;
			}
		}
		void insertLast(node *newNode){
			if(head==NULL)
				head=tail=newNode;
			else{
				tail->next=newNode;
				newNode->prev=tail;
				tail=newNode;
			}
		}
		void deleteFront(){
			if(head==NULL){
				cout<<"empty";
			}
			else if(head!=NULL&&head==tail){
				delete head;
				head=tail=NULL;
			}
			else{
				node *temp=head;
				head=head->next;
				head->prev=NULL;
				delete temp;
			}
		}
		void deleteLast(){
			if(head==NULL)
				cout<<"empty";
			else if(head!=NULL&&head==tail)
			{
				delete tail;
				head=tail=NULL;
			}
			else{
				node *temp=tail;
				tail=tail->prev;
				tail->next=NULL;
				delete temp;
				
			}
		}
		void insertAfter(int a,node *newNode){
			// for empty list
			if(head==NULL){
				cout<<endl<<"Empty"; 
				return;
			}
			// for non-empty list
			node *cur=head;
			while(cur!=NULL){
				if(cur->data==a){
					break;
				}
				cur=cur->next;
			}
			if(cur==tail){
				insertLast(newNode);
				return;
			}
			if(cur==NULL){
				cout<<"Node not exist";
				return;
			}
			cur->next=newNode;
			newNode->prev=cur;
			newNode->next=cur->next;
			cur->next->prev=newNode;		
		}
		void deleteSpecific(int a){
			// FOR EMPTY LIST
			if(head==NULL){
				cout<<"empty";
			}
			// FOR SINGLE ELEMENT
			else if(head!=NULL&&head==tail){
				if(head->data==a){
					delete head;
					head=tail=NULL;
				}
				else{
					cout<<"Node does not exist.";
				}
				return;
			}
			// FOR MORE THAN 1 ELEMENT
			else{
				node *cur=head;
				while(cur!=NULL){
					if(cur->data==a){
						break;
					}
					else
						cur=cur->next;
				}
				// when node is first i.e. head
				if(cur==head){
					deleteFront();return;
				}
				// when node not found in the whole list
				if(cur==NULL){
					cout<<"Node not exist";return;
				}
				// when node is last i.e. tail
				if(cur==tail){
					deleteLast();return;
				}
				// for any node between head and tail i.e. between first and last
				if(cur->data==a){
					(cur->prev)->next=cur->next;
						(cur->next)->prev=cur->prev;
						delete cur;
						return;
				}
				cout<<"Node not found";
			}
		}
		void search(int a){
			// for empty list
			if(head==NULL)
				cout<<endl<<"Empty"<<endl;
			// for single node
			else if(head!=NULL&&head==tail){
				if(head->data==a){
					cout<<"Exists"<<endl;
				}
				else{
					cout<<"Node does not exist."<<endl;
				}
				return;
			}
			// for more than 1 nodes
			else{
				node *cur1=head,*cur2=tail;
				while(cur1!=cur2&&cur1->next!=cur2->prev){
					if(cur1->data==a||cur2->data==a){
						cout<<"Data found"<<endl;
						return;
					}
					else{
						cur1=cur1->next;
						cur2=cur2->prev;
					}
				}
				if(cur1==cur2&&cur1->data==a){
					cout<<"data found"<<endl;
				}
				if(cur1->next==cur2->prev&&cur1->next->data==a||cur1->data==a||cur2->data==a)
					cout<<"data found"<<endl;
				else
					cout<<"Data not found"<<endl;
			}
		}
		void count(){
			node *cur=head;
			int c=0;
			while(cur!=NULL){
				c++;
				cur=cur->next;
			}
			cout<<"You have entered "<<c<<" nodes so far."<<endl;
		}
		void previousOf(int a){
			if(head==NULL)
				cout<<"empty";
			else{
				node *cur=head,*prev=NULL;
				while(cur!=NULL&&cur->data!=a){
					prev=cur;
					cur=cur->next;
				}
				if(cur->data==a&&cur!=head){
					cout<<endl<<"The previous data of "<<a<<" is "<<prev->data;
				}
				else if(cur->data==a&&cur==head)
					cout<<endl<<cur->data<<" is the first element and has no previous element";
				else
					cout<<"Data does not exist";
			}
		}
		void nextTo(int a){
			if(head==NULL)
				cout<<"empty";
			else {
				node *cur=head;
				while(cur!=NULL&&cur->data!=a){
					cur= cur->next;
				}
				if(cur->data==a&&cur==tail)
					cout<<endl<<cur->data<<" is the last element and no element is next to "<<cur->data;
				else if(cur->data==a&&cur!=tail)
					cout<<endl<<"Next to "<<a<<" is "<<cur->next->data;
				else
					cout<<"Data does not exist";
			}
		}
		void display(){	
			if(head==NULL){
				cout<<"Sorry List is empty!"<<endl;
			}
			else{
				node *cur=head;
				cout<<endl<<"\nValues in the list are: \t";
				while(cur!=NULL)
				{
					cout<<cur->data<<"\t";
					cur=cur->next;
				}
			}
			cout<<endl;
		}
};
int main(){
		list l1;
		int ask=1,n=0,choice=0,d=0;
		while(ask==1){
			cout<<"Enter your choice: "<<endl;
			cout<<"1.  Insert at front\n2.  Insert at Last ";
			cout<<"\n3.  Delete front\n4.  Delete last";
			cout<<"\n5.  Delete some particular node";
			cout<<"\n6.  find the number of nodes\n7.  display next";
			cout<<"\n8.  display previous";
			cout<<"\n9.  Search a particular node";
			cout<<"\n10.  display the list";
			cout<<"\n11.  Exit from the program";
			cout<<"\n12.  Insert After specific node"<<endl;
			cin>>choice;
			switch(choice){
				case 1:
				{
					cout<<endl<<"Enter the node to be inserted: "; 
					cin>>d; node *s=new node(d);l1.insertFront(s);
					l1.display();
				}
					break;
				case 2:
					{
						cout<<endl<<"Enter the node to be inserted: "; cin>>d;
						node *s=new node(d);l1.insertLast(s);
						l1.display();
					}
					break;
				case 3:
					{
						l1.deleteFront(); l1.display();
					}
					break;
				case 4:
					{
						l1.deleteLast(); l1.display();
					}
					break;
				case 5:
					{
						cout<<endl<<"Enter node you want to delete: ";cin>>n;
						l1.deleteSpecific(n); l1.display();
					}
					break;
				case 6:
					{
						l1.count();
					}
					break;
				case 7:
					{
						cout<<endl<<"Enter the node whose next you want find: ";cin>>n;l1.nextTo(n);
					}
					break;
				case 8:
					{
						cout<<endl<<"Enter the node whose previous you want find: ";cin>>n;l1.previousOf(n);
					}
					break;
					case 9:
					{
						cout<<endl<<"Enter the node you want to find: ";cin>>n;l1.search(n);
					}
					break;
					case 10:
					{
						l1.display();
					}
					break;
					case 11:
					{
						exit(EXIT_SUCCESS);
					}
					break;
					case 12:
					{
						cout<<"Enter the node after which you want to insert new node: ";
						cin>>n; cout<<endl<<"Enter new node: ";cin>>d; node *s=new node(d);
						l1.insertAfter(n,s);l1.display();
					}
					break;
				default:
					cout<<endl<<"Incorrect choice number is entered....!!!!!";
			}
		}
	return 0;
}





