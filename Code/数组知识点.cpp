#include<cstdio>
int main() {
	int a[] = {1, 2, 3};    
	printf("%d", (int)sizeof(a) / (int)sizeof(*a));//数组大小3
}
