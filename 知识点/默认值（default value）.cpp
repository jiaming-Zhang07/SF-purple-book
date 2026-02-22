#include<iostream>
using namespace std;
void f(int i,int j=1);//可以在函数原型声明中设置默认值
void f(int i,int j=22){cout<<i<<" "<<j<<endl;}//也可以在定义中设置默认值，但不能同时设置默认值，建议永远只在函数声明（Prototype）里写默认参数。
int main(){f(2);}//现在这个程序会报错[错误] default argument given for parameter 2 of 'void f(int, int)'，设置了两遍默认值，编译器不知道听谁的
