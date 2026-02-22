/*在 C++ 中，前向声明（Forward Declaration） 是一种“先打招呼，再做自我介绍”的机制。

简单来说，它是告诉编译器：“有一个名字叫 X 的类（或结构体/函数）确实存在，但我现在还不打算告诉你它的具体细节，你先记住这个名字。”

1. 为什么需要它？（编译器的“死脑筋”）
C++ 编译器通常是从上到下单遍扫描代码的。如果它在第 10 行看到你用到了 Class B，但 Class B 的定义在第 20 行，编译器就会发脾气：“我不认识 B 是什么！”

最棘手的情况是循环依赖：

类 A 的成员需要用到类 B。

类 B 的成员也需要用到类 A。

这时候，无论你把谁放在前面，编译器都会报错。前向声明就是用来打破这个死循环的。*/
#include<iostream>
using namespace std;
struct X;//前向声明
struct Y {
	void f(X*);
};
struct X {//definition
private:int i;//在不写访问限定符时struct中默认是public，class默认是private，这是struct和class的唯一本质区别
public:
	//友元函数的定义也可以在类内完成，但它不是成员函数，因此不会有this,不能直接写i(成员变量)，必须是a.i;
	void initialize();
	friend void g(X*,int);//global friend
	friend void Y::f(X*);//struct member friend
	friend struct Z;
	friend void h();
};
void X::initialize(){i=0;}
void g(X*x,int i){x->i=i;}
void Y::f(X*x){x->i=1;}
struct Z {
private:
	int j;
public:
	// 核心：Z 的成员函数可以直接通过 X 的对象、指针或引用访问私有成员 i
	void accessX(X& x_obj) {//注意，i 是 X 的一个实例变量（非静态成员），所以必须通过一个具体的 X 对象来访问它。
		x_obj.i = 100; 
	}
	
	void showX(X* x_ptr) {
		cout << x_ptr->i << endl; 
	}
};

