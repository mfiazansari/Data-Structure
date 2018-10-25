#include<iostream>
using namespace::std;
int main(){
	int a[5]={5,7,1,3,9};
	int i,j,min;
	for(i=0;i<5;i++){
		cout<<endl<<a[i];
	}
	cout<<endl;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(a[i]<a[j]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<5;i++){
		cout<<endl<<a[i];
	}
	j=5;
	for(i=0;i<5;i++){
		a[i]=j;
		j--;
	}
	for(i=0;i<5;i++){
		cout<<endl<<a[i];
	}
	cout<<endl;
	for(i=0;i<4;i++){
		min=a[i];
		for(j=i+1;j<5;j++){
			if(min>a[j]){
				min=a[j];
			}
		}
		int t=a[i];
		a[i]=min;
		min=a[i];
	}
	cout<<endl<<endl;
	for(i=0;i<5;i++){
		cout<<endl<<a[i];
	}
	return 0;
}
