#include<iostream>
using namespace std;
class A {
  public:
	static int j;
	A() {
		i = 0;
	}
//	A():i(0){}[错误] 'int A::i' is a static data member; it can only be initialized at its definition
	 void set(int ii) {
		i = ii;
	} static void print() {
		cout << i << endl;
		cout<<k;//error,静态成员函数只能使用静态成员变量。
		cout<<this->i;//error,静态成员函数不依赖于对象，因此没有this
	}
  private:
	int k;
	static int i;//类内部的static只是一个声明，而非定义。static表示所有对象共用
};
int A::j=1;
int A::i=2;//定义
//对比
//现代 C++ 的“特权”写法 (C++17)
class B {
private:
	inline static int i = 0; // C++17 支持，既是私有，又直接完成了定义
};
void countCalls() {
	static int counter = 0; // 声明 + 定义 + 初始化一次性完成
	counter++;
	cout << counter << endl;
}
static int global_val = 100; // 声明 + 定义+ 初始化一次性完成
int main() {
	A::print();//static函数可以这样调用，输出2因为还没有建立对象对i进行改变
	A a, b;
	A::print();//输出0
	cout<<a.j;//ok
	cout<<A::j;//ok
	cout<<A::i;//[错误] 'int A::i' is private within this context
	cout<<a.i<<endl;//[错误] 'int A::i' is private within this context
	a.set(10);
	b.print();
}
