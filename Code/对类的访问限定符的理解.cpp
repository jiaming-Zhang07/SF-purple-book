//private：仅类内部成员可见，public：外部代码、子类均可见。理解可见的意思
#include<iostream>
using namespace std;
class A {
  private:
	int i, tim = 0;
  public:
	int p;
	void set(int m) {
		i = m;
	}
	void times(int t) {//这就是所谓的按键或接口
		if (t > 0)tim += t;
	}
	void g(A*q) {
		cout << q->i << endl;//这是类的内部函数所以i是可见的
	}
	int read();
};
//权限（Access Rights）是针对“函数身份”的，而不是针对“代码写在哪里”的，
//只要一个函数在类（class）的内部声明过，它就是这个类的“家族成员”。无论它的函数体（实现代码）写在类大括号里面，还是写在几百行之外，它都拥有访问 private 成员的“特权”。
int A::read() {//别忘了A::这个前缀。
	return tim;   //合法
}
int main() {
	A a, b;
	a.p = 1; //不报错，p是public中的，可见
//	a.i=1;//报错，在main中i不可见，private只能通过 public 的按键（接口）来间接操作。
	a.set(100);//不报错，set是public中的，在任何地方都可见
	b.set(12);
	b.g(&a);//成员之间可以互相访问private
	a.times(5);//通过public的接口间接操作
	cout << a.read();//间接读取，输出5
}
