#include<iostream>
using namespace::std;
int main(){
	int a[5]={7,5,6,11,9};
	int i,j,min;
	cout<<"The unsorted array is: ";
	for(i=0;i<5;i++){
		cout<<endl<<a[i];	
	}
	cout<<endl<<endl<<"......The Ascending Sort Process......"<<endl<<endl;
	for(i=0;i<4;i++){
		for(j=0;j<5;j++)
			if(a[j]>a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
				
	}
	cout<<"The sorted array is: ";
		a[i]=j;
	for(i=0;i<5;i++){
		cout<<endl<<a[i];	
	}
	j=5;
	for(i=0;i<5;i++){
		j--;	
	}
	cout<<endl<<"The unsorted array is: ";
	for(i=0;i<5;i++){
		cout<<endl<<a[i];	
	}
	for(i=0;i<4;i++){
		min=a[i];
		for(j=i+1;j<5;j++){
			if(min>a[j]){
				min=a[j];
			}
		}
		int t=min;
		min=a[i];
		a[i]=t;
	}
	cout<<endl<<endl<<"......The Ascending Sort Process......"<<endl<<endl;
	cout<<"The sorted array is: ";
	for(i=0;i<5;i++){
		cout<<endl<<a[i];	
	}
	return 0;
}
