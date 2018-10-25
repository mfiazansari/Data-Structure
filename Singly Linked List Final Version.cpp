#include<iostream>
#include<stdlib.h>				// stream containing the defination of cin,cout etc
using namespace::std;			
struct node{					 
	int data;						// data variable to store the data item of a node
	node *next;					// next pointer of type node to store the address of the next node
	node(int d){			// constructor to initialize the data with the passsed value and next to null
		data=d;				
		next=NULL;		// Initially assign NULL to the next of every node
	}
};							// body of the structure closed
class list{					
	node *head,*tail;		// two pointers of type node to store the address of first and last node	
	public:					
		list(){						// default constructor to initialize head and tail with null
			head=tail=NULL;			// assignment statement
		}
		void insertFront(node *newNode){	//function to insert a node at the front of list it will take the address of new node	
			if(head==NULL){					// condition to check whether the list is empty
				head=tail=newNode;			// to assign head & tail new node if list is empty
			}
			else{							
				newNode->next=head;			// to point the next of new node towards the head
				head=newNode;	
			}
		}
		void insertLast(node *newNode){		// function to insert new node at last	
			if(tail==NULL)					// condition to check whether the list is empty
				head=tail=newNode;			// to assign head & tail new node if list is empty
			else{
				tail->next=newNode;				// assigning new node to the next of tail
				newNode->next=NULL;
				tail=newNode;					// to assign new node which is at las now to tail 
			}				
		}
		void insertAfter(int a,node *newNode){		// function to isert new node after a particular node
			if(head==NULL){							// condition to check whether the list is empty
				cout<<"empty";
			}
			else {
			    node *prev=head,*cur=head->next;		// initialization of prev with head and cur with next node of head, two pointer of type node 
				while(prev->next!=NULL&&prev->data!=a){	// use of AND (&&) to check compound condition
					prev=cur;							// assigning cur node to prev
					cur=cur->next;						// to movecur pointer forward i.e. assigninment statement of next node of cur to cur
				}
				if(prev->data==a){						// to check wether the specified node is found
					prev->next=newNode;					// insertion of new node after finding the specific node
					newNode->next=cur;					// linking the new node to the next node of specific node
				}
			}
		}
		void deleteFront(){								//Function to delete the front node
			if(head==NULL){								// condition to check whether the list is empty
				cout<<"empty";							// display empty if the list is empty 
			}
			else if(head!=NULL&&head==tail){			//for checking if the list has only a single node by AND operator
				delete head;							// for deleting head(i.e. also tail) if the list has only one node
				head=tail=NULL;							// assignment of NULL to head and tail to make the list empty
			}	
			else{
				node *temp=head;						// create a new pointer of type node to store the address of head
				head=head->next;						// move the head forward i.e. the next node of assigning to the head
				delete temp;							// delete temp i.e. first node
			}
		}
		void deleteLast(){								// Function to delete the last node
			if(head==NULL){								// condition to check whether the list is empty
				cout<<"empty";							// display empty if the list is empty 
			}
			else if(head!=NULL&&head==tail)				//for checking if the list has only a single node by AND operator
			{
				delete tail;							// for deleting tail(i.e. same also head) if the list has only one node
				head=tail=NULL;							// assignment of NULL to head and tail to make the list empty
			}
			else{
				node *prev=NULL,*cur=head;				//if lis contain more then 1 nodes create two pointers of type node 
				while(cur!=tail){						//termination condition when trawersing ends i.e. reching at tail
					prev=cur;							// moving prev forward at the position of cur
					cur=cur->next;						// moving cur to next node
				}										// loop ends
				delete cur;								// delete the cur which contains the eddress of tail i.e the last node
				prev->next=NULL;						// setting the next of the 2nd last element to null
				tail=prev;								// assigning the tail the address of the 2nd last node 
			}											// termination of else body
		}												// closing the defination of the deletelast function
		void deleteSpecific(int a){						
			if(head==tail)
				cout<<"Empty";
			else if(head!=NULL&&tail==head){
				if(head->data=a){
					delete head;
					head=tail=NULL;
				}
			}
			else{
				node *prev=NULL,*cur=head;
				while(cur!=NULL&&cur->data!=a){
					prev=cur;
					cur=cur->next;
				}
				if(cur->data==a&&cur==head){
					deleteFront();
				}
				else if(cur->data==a&&cur==tail){
					deleteLast();
				}
				else if(cur->data==a){
					prev->next=(cur->next);
					delete cur;
				}
				else
					cout<<endl<<"Not found";
			}
		}
		void search(int a){
			node *cur=head;
			while(cur!=NULL&&cur->data!=a){
				cur=cur->next;
			}
			if(cur->data==a)
				cout<<endl<<"Found";
			else
				cout<<endl<<"Not found";
		}
		
		void nextTo(int a){
			if(head==NULL)
				cout<<"empty";
			else {
				node *cur=head;
				while(cur!=NULL&&cur->data!=a){
					cur= cur->next;
				}
				if(cur->data==a){
					cout<<endl<<"Next to "<<a<<" is "<<cur->next->data;
				}
				else
					cout<<"wrong input";
			}
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
				if(cur->data==a){
					cout<<endl<<"The previous data of "<<a<<" is "<<prev->data;
				}
				else
					cout<<"Wrong Input";
			}
		}
		void count(){
		    node *cur=head;
			int c=0;
			while(cur!=NULL){
				c++;
				cur=cur->next;
			}
			cout<<"Singly List has "<<c<<" nodes";
		}
		void display(){
			if(head==NULL){
				cout<<"Sorry List is empty!"<<endl;
			}
			else{
				node *cur=head;
				cout<<"\nValues in the list are: ";
				while(cur!=NULL)
				{
					cout<<cur->data<<"\t";
					cur=cur->next;
				}
			}
		}
};
int main(){
		list l1;
		int ask=1,n=0,choice=0,d=0;
		while(ask==1){
			cout<<endl<<"Enter your choice: "<<endl;
			cout<<"1.	Insert at front\n2.	Insert at Last \n3.	Insert after some particular node";
			cout<<"\n4.	Delete front\n5.	Delete last\n6.	Delete some particular node";
			cout<<"\n7.	find the number of nodes\n8.	display next";
			cout<<"\n9.	display previous\n10.	Search a particular node/value in the list "<<endl;
			cout<<"11.	Display the whole list again: \n12.	Exit"<<endl;
			cin>>choice;
			switch(choice){
				case 1:
				{
					cout<<endl<<"Enter the node to be inserted: "; cin>>d; node *s=new node(d);l1.insertFront(s);
					l1.display();
				}
					break;
				case 2:
					{
						cout<<endl<<"Enter the node to be inserted: "; cin>>d; node *s=new node(d);l1.insertLast(s);
						l1.display();
					}
					break;
				case 3:
					{
						cout<<"Enter the node after which you want to insert the new data: "; cin>>n; 
						cout<<endl<<"Enter the node to be inserted: "; cin>>d; node *s=new node(d);l1.insertAfter(n,s);
						l1.display();
					}
					break;
				case 4:
					{
						l1.deleteFront(); l1.display();
					}
					break;
				case 5:
					{
						l1.deleteLast(); l1.display();
					}
					break;
				case 6:
					{
						cout<<endl<<"Enter node you want to delete: ";cin>>n;
						l1.deleteSpecific(n); l1.display();
					}
					break;
				case 7:
					{
						l1.count();
					}
					break;
				case 8:
					{
						cout<<endl<<"Enter the node whose next you want find: ";cin>>n;l1.nextTo(n);
					}
					break;
				case 9:
					{
						cout<<endl<<"Enter the node whose previous you want find: ";cin>>n;l1.previousOf(n);
					}
					break;
				case 10:
					{
						cout<<endl<<"enter the number you want to search: ";cin>>n;l1.search(n);
					}
					break;
				case 11:
					{
						l1.display();
					}
					break;
				case 12:
						{
							exit(EXIT_SUCCESS);
						}
					break;
				default:
					cout<<endl<<"Incorrect choice number is entered....!!!!!";
			}
		}
	return 0;
}
