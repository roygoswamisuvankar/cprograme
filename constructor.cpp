#include<iostream>
using namespace std;
class student{
	private:
		int sub1, sub2;
	public:
		int r;
		string n;
		student(){					//default constructor
			cout<<"Enter roll: ";
			cin>>r;
			cout<<"Enter name: ";
			cin>>n;
			cout<<"Roll: "<<r<<" ";
			cout<<"Name : "<<n;
		}
		student(int s1, int s2){		//parameterize constructor
			sub1 = s1;
			sub2 = s2;
		}
		int gets1(){
			return sub1;
		}
		int gets2(){
			return sub2;
		}
};
int main(){
	int s1, s2,t;
	student st;			//default constructor invoked
	cout<<"Enter subject1: ";
	cin>>s1;
	cout<<"Enter subject2:";
	cin>>s2;
	student st2(s1, s2);		//parameterize constructor invoked
	cout<<"\n";
	cout<<"Subject1 : "<<st2.gets1();
	cout<<"\n";
	cout<<"subject2: "<<st2.gets2();
}
