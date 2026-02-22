//不一定要自己定义，编译器会自动为你生成一个默认的拷贝构造函数。
//如果你没有显式定义拷贝构造函数，C++ 编译器会自动为你创建一个。这个默认的行为被称为浅拷贝
//它的行为： 逐个成员地进行复制。
#include<iostream>
using namespace std;
class A {
  public:
	int value;
	A(int i) {
		cout << "A()" << endl << i<<endl;
	}
	A(const A&other){value=other.value;}
};
int main() {

	A h = 1;//合法，相当于A h(1),调用第一个构造函数
	h.value=2;
	A m=h;//调用拷贝构造
	cout<<m.value<<endl;
	A n(h);//另一种写法，也是调用拷贝构造
	cout<<n.value;
}

