/*goto:跳转语句，不推荐使用，会造成逻辑混乱，难以调试
语法：配合标签使用,不能跳过任何初始化*/
#include<cstdio>
int main() {
	goto jump;
	printf("1");//被跳过
jump:return 0;
}
/*唯一推荐场景：跳出多层循环；
也可以把多层循环变成一个函数直接return*/
