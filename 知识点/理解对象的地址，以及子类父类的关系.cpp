#include<iostream>
using namespace std;
class A {
  public:
	int i;
	A(): i(1) {}
};
class B: public A {
  public:
	int j;
	B(): j(5) {}
};
A f() {//返回值是A的对象，而不是这个a（local)的地址,这样是可以的，但返回的时A的一个副本，这个副本是个匿名临时对象。
	A a;
	return a;
}
int main() {
	f().i=10;//[错误] using rvalue as lvalue [-fpermissive]把右值（临时的）当作左值（有明确地址的）使用，这个返回的副本在这句结束后就消失了，所以编译器不允许这样做。
	A a;
	B b;
	int*p = (int*)&a;//强制类型转换，转换为指向整数的地址，也就可以访问i的值了
	cout << a.i << " " << b.i << endl;//一样
	cout << *p << endl;//输出i
	p = (int*)&b;
	cout << *p << endl;//也是i，但这两个地址不一样，毕竟不是一个东西
	p++;//指向了j
	cout << *p;//输出j
}//子类地址的前面部分指向的就是父类的成员
