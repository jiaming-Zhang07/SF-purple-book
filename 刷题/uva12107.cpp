#include<bits/stdc++.h>
using namespace std;
char ch[20], ch2[20];
int cnt, maxn;
bool equa(char*s) {
	int a = 0, b = 0, c = 0, t = 0;
	while (s[t] != ' ')
		t++;
	for (int i = 0; i < t; i++) {
		a = a * 10 + s[i] - '0';
	}
	for (t = t + 1; s[t] != ' '; t++) {
		b = b * 10 + s[t] - '0';
	}
	for (int i = t + 1; s[i] != '\n' && s[i] != '\r'; i++ )
		c = c * 10 + s[i] - '0';
	if (a * b == c)
		return true;
	return false;
}
void dfs(int t) {
	while (ch[t] != '*' && ch[t] != '\0')
		t++;
	if (ch[t] == '\0') {
		if (equa(ch2))
			cnt++;
		return ;
	}
	for (int i = (((t == 0 || ch[t - 1] == ' ') && ch[t + 1]!=' '&&ch[t+1]!='\n'&&ch[t+1]!='\r') ? 1 : 0); i < 10; i++) {
		ch2[t] = '0' + i;
		dfs(t + 1);
		if(cnt>1)return;
	}
}
bool dfs2(int n, int t) {
	if (n == maxn) {
		memcpy(ch2, ch, sizeof(ch));
		cnt = 0;
		dfs(0);
		if (cnt == 1)
			return true;
		return false;
	}
	for (int i = t; i < (int)strlen(ch); i--) {
		if (ch[i] == ' ' )
			continue;
		if(ch[i]=='\n'||ch[i]=='\r')break;
		if ((int)strlen(ch)-i-1 < maxn - n)
			break;
		if (ch[i] != '*') {
			char c2 = ch[i];
			ch[i] = '*';
			if (dfs2(n + 1, i + 1))
				return true;
			ch[i] = c2;
		}
		for (int j = (((t == 0 || ch[t - 1] == ' ') && ch[t + 1]!=' '&&ch[t+1]!='\n'&&ch[t+1]!='\r') ? 1 : 0); j < 10; j++) {
			if (ch[i] == '0' + j)
				continue;
			char cc = ch[i];
			ch[i] = '0' + j;
			if (dfs2(n + 1, i +1))
				return true;
			ch[i] = cc;
		}
	}
	return false;
}
int main() {
	int kase = 0;
	while (fgets(ch, 20, stdin) && ch[0] != '0') {
		printf("Case %d: ", ++kase);
		cnt = 0;
		memcpy(ch2, ch, sizeof(ch));
		dfs(0);
		if (cnt != 1) {
			for ( maxn = 1;; maxn++)
				if (dfs2(0, strlen(ch) - 1))
					break;
		}
		for (int i = 0; i < (int)strlen(ch); i++)
			printf("%c", ch[i]);
	}
}
