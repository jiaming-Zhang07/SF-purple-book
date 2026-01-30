#include<iostream>
using namespace std;
class Point {
  public:
	void ini(int x, int y) {
		this->x = x;//this->x为类中成员,右边x为传进来的参数。
		this->y = y;
	}
  private:
	int x;
	int y;
};
class X {
	int i;
  public:
	X();//constructor:构造函数，特点：1，函数名与类名相同2，没有任何返回值。3，创建对象时自动调用。
};
//也可传参数：
class W {
  public:
	W(int a);
};
W::W(int a) {
	cout << a << endl;
}
X::X() {
	cout << 1;
}
int main() {
	//Point a;
	//X b;//发生b.X()
	X b;
	//W b(22);
	cout << "b created" << endl;
	//a.ini(1, 2);
}
