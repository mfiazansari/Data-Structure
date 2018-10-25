#include<iostream>
using namespace ::std;
int main(){
	int array[10]={0};
	int i,j=0;
	cout<<"Enter the values of the array: "<<endl;
	for(i=0;i<10;i++){
		cin>>array[i];
	}
	
	for(i=0;i<10/2;i++){
		for(j=i+1;j<10/2;j++){
			if(array[j]<array[i]){
				int t=array[i];
				array[i]=array[j];
				array[j]=t;
			}
		}
	}
	for(i=9;i>=10/2;i--){
		for(j=i-1;j>=10/2;j--){
			if(array[j]<array[i]){
				int t=array[j];
				array[j]=array[i];
				array[i]=t;
			}
		}
	}
	cout<<"values in the array are: ";
	for(i=0;i<10;i++){
		cout<<array[i]<<",";
	}
	return 0;
}
