#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main() {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		LL maxv = 0;
		int s, s1, v1, s2, v2;
		scanf("%d%d%d%d%d", &s, &s1, &v1, &s2, &v2);
		if (s1 < s2) {
			swap(s1, s2);
			swap(v1, v2);
		}
		if (s / s1 < 60000)
			for (LL i = 0; s1*i <= s; i++) {
				maxv = max(v1*i + (s - s1*i) / s2*v2, maxv);
			} else {
			for (LL i = 0; i < s2; i++)
				maxv = max(v1*i + (s - s1*i) / s2*v2, maxv);
			for (LL i = 0; i < s1; i++)
				maxv = max(v2*i + (s - s2*i) / s1*v1, maxv);
		}
		printf("Case #%d: %lld\n", ++kase, maxv);
	}
}
