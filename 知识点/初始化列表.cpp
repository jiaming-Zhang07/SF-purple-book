struct A {
	int p;
  public:
	A(): p(0) {}
};//:p(0)结构就是初始化列表，0便代表p的初值。
//初始化列表 (Initialization List) 是构造函数的一种特有机制，用于在构造函数主体执行之前，直接对类成员进行初始化。
class Point {
	const float x, y;
	Point(float xa = 0.0, float ya = 0.0): y(ya), x(xa) {}
};
//在 C++11 及更高版本中，你完全可以直接在定义数组时给它初始值。
struct Node {
	int arr[3] = {0, 0, 0}; // ✅ 完全合法（C++11 以后）

	Node() {
		// 构造函数体
		// 此时如果不写初始化列表，arr 已经自动是 {0, 0, 0} 了
	}
};
struct Node {
	int arr[3];
	// 根据传入的 a, b, c 来初始化数组，这时只能写在列表里
	Node(int a, int b, int c) : arr{a, b, c} {}
};
//在现代竞赛中（C++11/14/17/20）：现在的 Codeforces、ICPC、CCPC 默认都支持 C++17 或 C++20，所以直接在定义处写 int arr[3] = {0}; 是非常推荐的做法，这样可以有效防止忘记初始化导致的随机值 Bug。
//优先级：初始化列表 > 类内默认值。
struct Node {
	int x = 0;   // 类内默认值
	int y = 5;   // 类内默认值

	Node() {}                   // 结果：x=0, y=5 (使用了类内默认值)
	Node(int _x) : x(_x) {}     // 结果：x=_x, y=5 (x被初始化列表覆盖，y用默认值)
};
//默认参数：
struct Point {
	int x, y;
	// 这里的 y = 0 就是默认参数
  public:
	Point(int _x, int _y = 0) : x(_x), y(_y) {}
};

// 使用：
Point p1(10, 20); // x=10, y=20
Point p2(5);      // x=5,  y=0 (y 使用了默认参数)
//成员变量不初始化是随机值
//静态成员变量是0；
