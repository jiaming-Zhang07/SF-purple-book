#include<bits/stdc++.h>
using namespace std;
char ch[20];
int  maxn, len_ch;
int getlen(int n) {
	if (n == 0)
		return 1;
	int len = 0;
	while (n > 0) {
		n /= 10;
		len++;
	}
	return len;
}
bool match(int a, int pos, int len) {
	for (int i = len - 1; i >= 0; i--) {
		if (ch[pos + i] != '*' && a % 10 + '0' != ch[pos + i])
			return false;
		a /= 10;
	}
	return true;
}
bool is_good() {
	int t = 0, cnt = 0;
	while (ch[t] != ' ')
		t++;
	int lena = t;
	t++;
	while (ch[t] != ' ')
		t++;
	int lenb = t - lena - 1;
	int lenc = 1;
	while (ch[t + lenc] != '\n' && ch[t + lenc] != '\r')
		lenc++;
	lenc--;
	int mina = lena == 1 ? 1 : 10, maxa = lena == 1 ? 9 : 99;
	int minb = lenb == 1 ? 1 : 10, maxb = lenb == 1 ? 9 : 99;
	int minc = lenc == 1 ? 1 : (lenc == 2 ? 10 : (lenc == 3 ? 100 : 1000)), maxc = lenc == 1 ? 9 : (lenc == 2 ? 99 : (lenc == 3 ? 999 : 9999));
	for (int a = mina; a <= maxa; a++)
		if ( match(a, 0, lena))
			for (int b = minb; b <= maxb ; b++)
				if ( match(b, lena + 1, lenb)) {
					int c = a*b;
					if ( c >= minc && c <= maxc && match(c, lena + lenb + 2, lenc)) {
						cnt++;
						if (cnt > 1)
							return false;
					}
				}
	if (cnt == 1)
		return true;
	return false;
}
char ch2[] = {'*', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool dfs2(int n, int t) {
	if (n == maxn) {
		if (is_good())
			return true;
		return false;
	}
	int i = t;
	while (ch[i] == ' ' )
		i++;
	if (ch[i] == '\n' || ch[i] == '\r')
		return false;
	if (len_ch - i - 1 < maxn - n)
		return false;
	for (int j = 0; j < 11; j++) {
		if (j == 1 && ((i == 0 || ch[i - 1] == ' ') && ch[i + 1] != ' ' && ch[i + 1] != '\n' && ch[i + 1] != '\r'))
			continue;
		char cc = ch[i];
		int next_n = ch[i] == ch2[j] ? n : n + 1;
		ch[i] = ch2[j];
		if (dfs2(next_n, i + 1))
			return true;
		ch[i] = cc;
	}
	return false;
}
int main() {
	int kase = 0;
	while (fgets(ch, 20, stdin) && ch[0] != '0') {
		printf("Case %d: ", ++kase);
		len_ch = strlen(ch);
		if (!is_good()) {
			for ( maxn = 1;; maxn++)
				if (dfs2(0, 0))
					break;
		}
		for (int i = 0; i < (int)strlen(ch); i++)
			printf("%c", ch[i]);
	}
}
