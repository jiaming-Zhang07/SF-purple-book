#include<iostream>
using namespace std;
class Y {
  public:
	~Y();//析构函数destructor,特点：1，对象结束时被调用2，不能有参数3，不能有返回值
};
Y::~Y() {
	cout << "inside the destructor" << endl;
}
int main() {
	cout << "the start of main" << endl;
	{//对象的生存周期
		Y t;
		cout << "t will end" << endl;
	}//结束前一瞬间调用
	cout << "t end";
}
