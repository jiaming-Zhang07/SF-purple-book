#include<iostream>
using namespace std;
class A {
  public:
	A(int ii): i(ii) {
		cout << "A::A()" << endl;
	}~A() {
		cout << "A::~A()" << endl;
	} void set(int ii) {
		i = ii;
	} void print() {
		cout << i << endl;
	}
  protected://只有它自己和它的子类可以访问，一般包含的方法便于子类访问自己的private，别人不能做
	void se(int ii) {
		i = ii;
	}
  private://一般所有数据都放在private
	int i;
};
/*这个 public 决定了父类的成员在子类中“长什么样”。在 C++ 中，这被称为继承权限
99% 的情况下都会使用 public 继承
你可以把这个 public 理解为一个**“权限过滤器”**。它规定了父类 $A$ 的成员进入子类 $B$ 后，最高能获得什么样的权限
*/
class B: public A {//B是A的子类，自动继承A的属性
  public://B中添加部分
	B(): A(15) {//构造时父类先构造，析构时子类先析构
		cout << "B()" << endl;   //父类成为了B的一部分，所以父类中的变量也要在子类中先初始化
	}
	~B() {
		cout << "~B()" << endl;   //i=30;//报错：[错误] 'int A::i' is private within this context
	}
	void f() {//B中是有i 的，毕竟能间接用set操作i,但不能直接操作i.
		set(20);
		se(1);//合法
		
		print();
	}
};
int main() {
	B b;
//	b.se(1);//[错误] 'void A::se(int)' is protected within this context
	b.set(10);
	b.print();
	b.f();
	cout << "main will end" << endl;
}
