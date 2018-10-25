#include<iostream>
using namespace::std;
struct tree{
	tree *p,*root,*l,*r;
	int data;
	public:
	tree()
	{
	root=p=l=r=NULL;
	}
	void create()
	{	
	int value,c=0,s;
	cout<<"Enter the size of tree: ";
	cin>>s;
		while(c<s)
		{
			if(root==NULL)
			{
				root=new tree;
				cout<<endl<<"Enter the value of root node: ";
				cin>>root->data;
				root->r=root->l=NULL;
			}
			else
			{
				p=root;
				cout<<"\nEnter the value: ";
				cin>>value;
				while(true)
				{
					if(value<p->data)
					{	
						if(p->l==NULL)
						{
							p->l=new tree;
							p=p->l;
							p->data=value;
							p->l=p->r=NULL;
							cout<<endl<<value<<" Is entered in left.";
							break;
						}
						else 
							p=p->l;
					}
					else if(value>p->data)
					{
						if(p->r==NULL)
						{	
							p->r=new tree;
							p=p->r;	
							p->data=value;
							p->l=p->r=NULL;
							cout<<endl<<value<<" is entered in right";	
		
							break;
						}
						else 
							p=p->r;
					}	
					else {
						 cout<<"\nValue is not appropriate"; 
						 break;
					     }
				}
			}
			c++;
		}
	}	
};
int main()
{
	tree t1;
	t1.create();
	return 0;
}
