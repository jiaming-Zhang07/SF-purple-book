//Dynamic memory allocation
//new 和 delete:new int,new Point(类）会调用构造函数,new int [10]...delete p;delete[] p;
//返回值是地址
#include<iostream>
using namespace std;
class A {
  private:
	int i;
  public:
	A() {
		i = 0;
		cout << "have created" << endl;
	}~A() {
		cout << i << endl;
	}
	void set(int i) {
		this->i = i;
	}
};
int main() {
	A*p = new A[10]; //构造函数被调用10次
	for (int i = 0; i < 10; i++)p[i].set(i);
	//delete p;只会清除第一个，只有第一个的析构函数被调用，会有警告，上传后也会RE
	delete[] p;//告诉系统要清除的是一个数组，而不只是一个元素，析构函数都被调用
}

