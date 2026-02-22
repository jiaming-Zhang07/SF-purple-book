#include<iostream>
using namespace std;
//枚举（Enum） 其实就是一个**“给数字起外号”**的工具
int main() {
	enum Status{Stop, Running};//编译器在后台偷偷做了一件事：它给这些名字分配了数字，默认从 0 开始递增。
	Status state = Running;
	if (state == Running) {} 
	if (state == Stop) {}
	enum Direct{UP=10,DOwn=20};//也可以手动指定数字
	//用法：
	enum Dir{Up,Down,Left,Right};
	int dx[]={-1,1,0,0};
	int dy[]={0,0,-1,1};
	Dir myDir=Right;
	int x0=0,y0=0;//初始坐标
	int next_x=x0+dx[myDir];//myDir=3
	int next_y=y0+dy[myDir];
	cout<<"向右走后的坐标："<<next_x<<","<<next_y<<endl;
}
//好处：名字总比数字好记
