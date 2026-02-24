#include<bits/stdc++.h>
using namespace std;
using ll = long long;
set<ll>sta;
ll squ[9] = {0, 2, 4, 9, 11, 13, 18, 20, 22};
void dfs(ll num, ll cur) {
	
	sta.insert(cur);
	if (num == 6)
		return;
	ll cur2 = cur;
	for (int i = 0; i < 9; i++) {
		for (int j = 1; j < 4; j += 2)
			cur |= 1LL << squ[i] + j;
		cur |=1LL<< squ[i] + 9;
		for (int j = 1; j < 4; j++)
			cur &= ~(1LL << squ[i] + j + 9);
		cur |= 1LL << squ[i] + 4 + 9;
		cur |=1LL<< squ[i] + 18;
		for (int j = 1; j < 4; j += 2)
			cur |= 1LL << squ[i] + j + 18;
		cur &= ~(1LL << squ[i] + 20);
		cur |= 1LL << squ[i] + 4 + 18;
		dfs(num+1, cur);
		cur = cur2;
	}
}
int main() {
	dfs(0, 0);
	int kase = 0;
	char ch[20];
	while (fgets(ch, 20, stdin)&&ch[0]!='0') {
		printf("Case %d: ", ++kase);
		ll cur = 0;
		for (int j = 0; j < 9; j++)
			if (ch[j] != ' ')
				cur |= 1LL << j;
		for (int i = 1; i <= 4; i++) {
			fgets(ch, 20, stdin);
			for (int j = 0; j < 9; j++)
				if (ch[j] != ' ')
					cur |= 1LL << i * 9 + j;
		}
		if (sta.count(cur))
			printf("Yes\n");
		else
			printf("No\n");
	}
}
