//const定义的也是变量，也有作用域等性质，但系统会保证它不能被修改。
//const必须要初始化，确定下的const变量可以直接被当常数使用。
#include <iostream>
using namespace std;
int main() {
	char*q="abc";//如果用char q[]="abc",则没有任何问题，重新拷贝了一份“abc'给数组的新开辟的内存区。
	cout<<q;
	*q='j';//运行后可以打印，但打印完后异常退出，返回值非0；
	int*ip;
	const int*cip;
	int i;
	ip = &i;
	cip=&i;//不能写*cip=..但可以i=..
	const int ci=3;
	cip=&ci;//ok
	ip=&ci;//error:这样就破坏了ci的const性质了
	const int size = 12;
	int a[size];//OK
	cout << sizeof(a);
	int x;
	cin >> x;
	const int siz = x; //合法
	int b[siz];
	cout << sizeof(b); //在大多数比赛中可以（g++编译，提供扩展功能变量长度数组）可以正常运行。但不推荐，可能爆栈。这是局部数组，你不知道输入会有多大。
//Pointers and const
	char*const q = "abc"; //q(地址） is a const//发现一个新知识点：[警告] ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]字符串字面量（比如 "abc"）
	//它住在“只读区”： 字符串常量被存放在程序的只读数据段，一般编译器会阻止用指针指向它，避免你后面想通过指针修改这个只读数据。
	*q = 'c'; //合法,*q not a const
	q++;//error
	const char*p = "abcd"; //*p is const表示不能通过指针p对其进行修改
	*p = 'b'; //error
}


