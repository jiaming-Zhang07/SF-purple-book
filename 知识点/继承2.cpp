#include<string>
#include <iostream>
using namespace std;
class Employee {
  public:
	Employee(const string&name, const string&ssn);
	//string&的返回值是string的引用，其实就是string，&是为了避免复制的巨大开销，直接返回原件
	/*std::ostream 是什么？ 它是所有输出流的基类。std::cout（标准输出）是它的一个对象，std::ofstream（文件输出）也是它的子类
	为什么要加引用 &？ 在 C++ 中，流对象是不允许拷贝的。如果你不加 &，编译器会尝试复制一个 cout 传进函数，这会导致编译报错。通过引用传递，函数直接操作你传进来的那个流对象。
	有什么好处？ 这让你的函数非常灵活：

	如果你想打印到屏幕，调用：obj.print(cout);

	如果你想打印到文件，调用：obj.print(fout);

	在有些比赛需要文件输入输出（如 NOIP/CSP），这种写法能让你无缝切换。*/
	const string& get_name()const;//const 是一个非常关键的“约束”，我们称之为常成员函数,它的意思是：“我保证这个函数只读，绝对不会修改类里的任何属性（成员变量）。”
	void print(std::ostream& out)const;
protected:string m_name;
	string m_ssn;
};
Employee:Employee(const string& name,const string&ssn):m_name(name),m_ssn(ssn){}//Employee 的构造函数的定义
//当你定义了一个“常量对象”时，编译器为了安全，只允许你调用带 const 标记的函数。
/*const Employee boss("Alice", "123");
boss.print(cout); // ✅ 合法：print 是 const，编译器放心
// boss.some_modify_func(); // ❌ 报错：不能对 const 对象调用非 const 函数*/
