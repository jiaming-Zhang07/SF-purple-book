//引用就是绰号，int &b = y;的意思是：从现在起，b 就是 y 的另一个名字。它们共享同一个内存地址。
//引用一旦初始化，就不能再去引用别人了，已经绑定了。
//一般不会这样做： reference to reference:int&x=m;int&y=x;
//no pointers to references int&*p//illegal
//reference to pointer is ok:int*&p;//离p最近的这个符号决定了p的类型
//没有reference的数组，因为reference不是一个实体
#include<iostream>
using namespace std;
int& g(int&x) { //参数是引用，返回一个引用
	x++;
	return x;
}
int x;
int& h() {
	int q;
//	return q;error,q is local
	return x;//ok,x lives outside this scope,is a reference.

}
int*up(int*x) {
	return x;
}
int main() {
	int y = 0;
	g(y);
	cout << y << endl;
	h() = 2; //h()返回的就是x的引用
	cout << x << endl;
	*up(&y)=7;//ok,up返回的是指针
	cout<<y<<endl;
	int&a=x;
	int&b=y;
	b=a;//赋值
	cout<<y<<endl;//这两个是一样的
	cout<<b<<endl;//
}
