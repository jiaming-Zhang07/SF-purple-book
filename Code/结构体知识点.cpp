//结构体初始化：
//#include<cstdio>
//struct X {
//	int i;
//	float f;
//};
//int main() {
//	X x1 = {1, 1.2};
//	X x2[3]={{1,1.2},{2,2.2}};//也可初始化结构体数组,最后一组初始化0
//	printf("%d %f\n", x1.i, x1.f);
//	printf("%d %f", x2[2].i, x2[2].f);
//}
//c++中结构体和类是相似的，只有细微差别，因此也可包含函数
#include<iostream>
#include<vector>
using namespace std;
struct Point {
	int x, y, m ;
	Point(int _x = 0, int _y = 0): x(_x), y(_y) {}//使用初始化列表
	void print() {
		cout << "(" << x << "," << y << ")";
	}
};

int main() {
	Point pt[] = {Point(1, 2), Point(3, 4)};//可以不初始化m
	for (int i = 0; i < 2; i++) {
		pt[i].print();
	}
	vector<Point> v;//竞赛中常用方法
	v.push_back(Point(10, 20));//创建了一个结构体变量丢进去
}
//注意：没有参数的构造函数叫做default constructor,
//对于有参数的构造函数，初始化结构体时必须一一对应
//Point pt[2] = {Point(1, 2), Point(3, 4)};即后面数量和数组长度相等
