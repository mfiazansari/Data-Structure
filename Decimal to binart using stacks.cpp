#include<iostream>
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
			return;
		}
		int pop(){
			if(top==NULL)
				cout<<"Stack is empty";
			else{
				node *temp=top;
				top=top->next;
				return temp->d;
			}
		}
		int IsEmpty(){
			if(top==NULL)
				return 0;
			else
				return 1;
		}
};
int main(){
	stack s1;int d=0;
	int num; cout<<"Enter decimal: ";cin>>num;
	while(num>0){
		d=num%2;node *n=new node(d);
		s1.push(n);
		num=num/2;
	}
	cout<<"\nThe Binary String of the decimal is: ";
	while(s1.IsEmpty()){
		cout<<s1.pop();
	}
	cout<<endl;
	return 0;
}
