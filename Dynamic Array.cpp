#include<iostream>
using namespace::std;
int main(){
	int n=0;int *y=new int[n];
	cout<<"enter the size of the dynamic array: ";
	cin>>n;
	int *temp=y;
	for(int i=0;i<n;i++){
		cin>>*y++;
	}
	for(int i=0;i<n;i++){
		cout<<endl<<*temp++;
	}
	
	
	return 0;
}
