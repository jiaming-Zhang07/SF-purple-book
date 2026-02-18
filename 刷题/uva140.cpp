//要点：把出现的字母按照0——n-1映射为数字，再定义一个数组由这些数字再映射回字母，便于后续输出字母，
//接下来枚举0-n-1的全排列，通过一个中间数组将每次的排列与上面的映射数字联系起来，即以这种方式枚举目标字符的全排列，找出目标数据即可。
#include<bits/stdc++.h>
using namespace std;
int id[256], letter[10];
int main() {
	char input[100];
	while (scanf("%s", input) == 1&&input[0]!='#') {
		int n = 0;
		for (int ch = 'A'; ch <= 'Z'; ch++)
			if (strchr(input, ch)!=NULL) {
				id[ch] = n++;
				letter[id[ch]] = ch;
			}
		int p = 0, q = 0, len = strlen(input);
		vector<int>u, v;
		for (;;) {
			while (p < len && input[p] != ':')
				p++;
			if (p == len)
				break;
			while (q < len && input[q] != ';')
				q++;
			for (int i = p + 1; i < q; i++) {
				u.push_back(id[input[p - 1]]);
				v.push_back(id[input[i]]);
			}
			p++;
			q++;
		}
		int P[10];
		for (int i = 0; i < n; i++)
			P[i] = i;
		int ans=10,best[10];
		do {
			int pos[10];
			for (int i = 0; i < n; i++)
				pos[P[i]] = i;
			int width=0;
			for (int i = 0; i < (int)u.size(); i++) {
				width = max(abs(pos[u[i]] - pos[v[i]]), width);
			}
			if (width < ans) {
				ans = width;
				memcpy(best, P, sizeof(P));
			}
		}while(next_permutation(P,P+n));
		for(int i=0;i<n;i++)printf("%c ",letter[best[i]]);printf("-> %d\n",ans);
		
		
		
	}
}
