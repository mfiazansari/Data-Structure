#include<iostream>
using namespace::std;
class shap{
	public:
		virtual float calculateArea(){
			cout<<endl<<"Area of the Shap"<<endl;
		}
};
class circle:public shap{
	private:
		float radius;
	public:
		circle(){
			radius=0.0;
		}
		void set(int n){
			radius=n;
		}
	virtual float calculateArea(){
			return 3.14*radius*radius;
	}
	void print(){
		cout<<endl<<"Area of the Circle is: "<<calculateArea();
	}
};
class rectangle:public shap{
	private:
		float length,width;
	public:
		void set(float l,float w){
			length=l;
			width=w;
		}	
		virtual float calculateArea(){
			return 0.5*length*width;
		}
		void print(){
			cout<<endl<<"Area of the Rectangle is: "<<calculateArea();
		}
};
class square{
	private:
		float length_Of_Side;
	public:	
		square(){
			length_Of_Side=0.0;
		}
		void set(float l){
			length_Of_Side=l;
		}
		virtual int calculateArea(){
			return length_Of_Side*length_Of_Side;
		}	
		void print(){
			cout<<endl<<"The Area of the square is: "<<calculateArea();
		}
};
int main(){
	circle c1;
	int r;
	cout<<"Enter Radius";
	cin>>r;
	c1.set(r);
	c1.calculateArea();
	c1.print();
	rectangle r1;
	float l,w;
	cout<<"\nEnter Length: ";
	cin>>l;
	cout<<"\nEnter width: ";
	cin>>w;
	r1.set(l,w);
	r1.calculateArea();
	r1.print();
	square s1;
	float length_Of_side;
	cout<<endl<<"\nEnter Lenth of side of square: ";
	cin>>length_Of_side;
	s1.set(length_Of_side);
	s1.calculateArea();
	s1.print();
	return 0;
}






