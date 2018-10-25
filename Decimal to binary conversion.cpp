#include<iostream>
using namespace::std;
int main(){
	int n;cout<<"Enter Decimal number: ";cin>>n;
	cout<<endl;
	while(n>0){
		cout<<n%2;
		n=n/2;
	}
	return 0;
}
