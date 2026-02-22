//运算符重载包括各种算术运算符的重载和new,delete的重载等等，限制：不能自己造一个符号重载，2，运算符的重载必须建立在一个类或枚举类型的基础上3，必须保持该符号原有操作数的个数4，保持原来运算符的优先级
//运算符的重载通过函数实现，函数名格式：operator+符号
//这个函数可以是成员函数如：Complex operator+(const Complex& other) const {...}// 只需要一个参数，因为左操作数是 this 指针指向的对象
//也可以是全局函数（free function）要提供两个参数
//返回值可以是任意类型，常见情况如下：
//返回同类对象（最常见）：便于进行链式法则：a+b+c;返回布尔值：用于逻辑判断；返回引用&（赋值与流操作）便于连续赋值（operator=返回自身引用*this，a=b=c)或连续输出（operator<<:返回ostream&,cout<<a<<b;)
#include<iostream>
using namespace std;
class integer {
  public:
	integer(int n = 0): i(n) {}
	const integer operator+(const integer&n)const {//第一个const:返回值是const,即只能做右值，不能出现a+b=6;第二个：传入的参数不能被改变值（符合加号逻辑）加法对加号两边的东西无影响；第三个：该成员函数不会对this->i进行修改，用于在定义成员函数时保护成员变量不被修改（这种在函数括号后面直接加 const 的语法，是成员函数特有的）如果在外面定义时有它，则声明时也要加。
		return integer(i + n.i);
	}
	const integer operator-()const {//"-"既是一元的，也是二元的，既可以重载为一元的也可以重载为二元的，系统在你调用它时会自主做出判断
		return integer(-i);
	}
	//这两个构成函数重载
    const integer operator-(const integer&n)const {
		return integer(i - n.i);
	}
	friend const integer operator*(const integer&m, const integer&n); //friend便于外面定义这种全局的符号重载函数时可以访问到成员变量i
	void print() {
		cout << i << endl;
	}
  private:
	int i;
};

const integer operator*(const integer&m, const integer&n) {//全局的*重载函数，要有两个参数,友元函数不是成员函数，定义时不能加类名::,成员函数在外部定义时必须加类名::
	{
		return integer(m.i*n.i);
	}
}

int main() {
	integer x(2), y(3), z;
	z=3*x;//可以
	z=3*3;//可以，先算3*3；再用构造函数变成integer对象，再赋给z,和重载的*没关系了
	z.print();
	z = x*y; //operator*(x,y);
	z = x - y;
	z.print();
	z = -x; //z.operator=(x.operator-())
	z.print();
	//x+y;===>x.operator+(y);
	z = x + y; //运算符左边的叫作receiver,它的类型决定了用哪种运算符
	z = x + 3; //可以，编译器会将3通过第一个构造函数构造一个integer对象再与x相加,如果这个构造函数需要传的参数是double型，则这个式子也合法，因为3默认是整型，需要先隐式转化为double型再转化为integer对象，现在的c++是允许这样的
	z = x + 4.1; //合法4.1->4
	z.print();
	//z=3+y;//不行,编译器先扫描到3,所以后面的+是整型的operator+，y必须要有一个函数将自己转化为整型，但它没有这种函数，所以会报错。
}
