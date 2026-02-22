#include<cstdio>
int main() {
	int*p = 0;//空指针，地址为0的区域被系统严格保留，不允许被读写，即空指针
	if (p == NULL)printf("1");//
}
//NULL的定义：
/*#define NULL 0
// 或者在某些环境下定义为
#define NULL ((void *)0)*/
