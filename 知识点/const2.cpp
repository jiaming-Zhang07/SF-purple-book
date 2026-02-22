#include<iostream>
using namespace std;
class A {
	int i;//若这里改成const int i;则必须有初始化。
  public:
	A(): i(0) {}
	void f() {
		cout << "f()" << endl;
	}
	void f()const{cout<<"f()const"<<endl;}
	//上面这两个是重载函数，一个的参数是A*this，另一个是const A*this.
};
int main(){
	const A a;//这样时A中必须有成员变量的初始化（否则会报错），因为后面无法再赋值，
	//若定义一个非const对象，则无需初始化
	
	a.f();//会调用第二个
	
}
