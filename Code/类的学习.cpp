#include<iostream>
using namespace std;
class A {
  public:
	int i;
	void d();
};
void A::d() {
	
	this->i = 10;//"this"is a hidden parameter,created with object created.
	cout << &i << endl;
	cout<<this<<endl;
}
int main() {
	A a;
	a.i = 20;
	cout<<&a<<endl<<&a.i<<endl;
	a.d();
	cout<<endl;
	A b;
	b.d();
}
/*Point a;
a.print();
can be regarded as:Point::print(&a); */

