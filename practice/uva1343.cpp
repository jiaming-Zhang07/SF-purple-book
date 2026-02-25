#include<bits/stdc++.h>
using namespace std;
int maxn;
deque<int>q1, q2, q3, q4;
int num;
vector<char>ans;
int h() {
	int ans = 8;
	for (int k = 1; k <= 3; k++) {
		int cnt = 0;
		for (int i = 2; i <= 4; i++)
			if (q3[i] != k)
				cnt++;
		if (q1[3] != k)
			cnt++;
		if (q2[3] != k)
			cnt++;
		for (int i = 2; i <= 4; i++)
			if (q4[i] != k)
				cnt++;
		ans = min(cnt, ans);
	}
	return ans;
}
bool dfs(int d) {
	if (q1[2] == q1[3] && q1[3] == q1[4] && q4[2] == q4[3] && q4[3] == q4[4] && q2[2] == q2[3] && q2[3] == q2[4] && q3[2] == q3[3] && q3[3] == q3[4]) {
		num = q3[3];
		return true;
	}
	if (d + h() > maxn)
		return false;
	q3[2] = q1[3];
	q4[2] = q1[5];
	q1.push_back(q1.front());
	q1.pop_front();
	ans.push_back('A');
	if (dfs(d + 1))
		return true;
	q3[2] = q1[1];
	q4[2] = q1[3];
	ans.pop_back();
	q1.push_front(q1.back());
	q1.pop_back();
	q3[4] = q2[3];
	q4[4] = q2[5];
	q2.push_back(q2.front());
	q2.pop_front();
	ans.push_back('B');
	if (dfs(d + 1))
		return true;
	q3[4] = q2[1];
	q4[4] = q2[3];
	ans.pop_back();
	q2.push_front(q2.back());
	q2.pop_back();
	q1[2] = q3[1];
	q2[2] = q3[3];
	q3.push_front(q3.back());
	q3.pop_back();
	ans.push_back('C');
	if (dfs(d + 1))
		return true;
	q1[2] = q3[3];
	q2[2] = q3[5];
	ans.pop_back();
	q3.push_back(q3.front());
	q3.pop_front();
	q1[4] = q4[1];
	q2[4] = q4[3];
	q4.push_front(q4.back());
	q4.pop_back();
	ans.push_back('D');
	if (dfs(d + 1))
		return true;
	q1[4] = q4[3];
	q2[4] = q4[5];
	ans.pop_back();
	q4.push_back(q4.front());
	q4.pop_front();
	q2.push_front(q2.back());
	q2.pop_back();
	q3[4] = q2[2];
	q4[4] = q2[4];
	ans.push_back('E');
	if (dfs(d + 1))
		return true;
	ans.pop_back();
	q2.push_back(q2.front());
	q2.pop_front();
	q3[4] = q2[2];
	q4[4] = q2[4];
	q1.push_front(q1.back());
	q1.pop_back();
	q3[2] = q1[2];
	q4[2] = q1[4];
	ans.push_back('F');
	if (dfs(d + 1))
		return true;
	ans.pop_back();
	q1.push_back(q1.front());
	q1.pop_front();
	q3[2] = q1[2];
	q4[2] = q1[4];
	q4.push_back(q4.front());
	q4.pop_front();
	q1[4] = q4[2];
	q2[4] = q4[4];
	ans.push_back('G');
	if (dfs(d + 1))
		return true;
	ans.pop_back();
	q4.push_front(q4.back());
	q4.pop_back();
	q1[4] = q4[2];
	q2[4] = q4[4];
	q3.push_back(q3.front());
	q3.pop_front();
	q1[2] = q3[2];
	q2[2] = q3[4];
	ans.push_back('H');
	if (dfs(d + 1))
		return true;
	ans.pop_back();
	q3.push_front(q3.back());
	q3.pop_back();
	q1[2] = q3[2];
	q2[2] = q3[4];
	return false;
}
int main() {
	int t;
	while (cin >> t && t) {
		ans.clear();
		q1.clear();
		q2.clear();
		q3.clear();
		q4.clear();
		int t1, t2;
		scanf("%d", &t2);
		q1.push_back(t);
		q2.push_back(t2);
		scanf("%d%d", &t1, &t2);
		q1.push_back(t1);
		q2.push_back(t2);
		for (int i = 0; i < 7; i++) {
			int t;
			scanf("%d", &t);
			q3.push_back(t);
			if (i == 2)
				q1.push_back(t);
			if (i == 4)
				q2.push_back(t);
		}
		scanf("%d%d", &t1, &t2);
		q1.push_back(t1);
		q2.push_back(t2);
		for (int i = 0; i < 7; i++) {
			int t;
			scanf("%d", &t);
			q4.push_back(t);
			if (i == 2)
				q1.push_back(t);
			if (i == 4)
				q2.push_back(t);
		}
		for (int i = 0; i < 2; i++) {
			int t1, t2;
			scanf("%d%d", &t1, &t2);
			q1.push_back(t1);
			q2.push_back(t2);
		}
		if (q1[2] == q1[3] && q1[3] == q1[4] && q4[2] == q4[3] && q4[3] == q4[4] && q2[2] == q2[3] && q2[3] == q2[4] && q3[2] == q3[3] && q3[3] == q3[4]) {
			num = q3[3];
			printf("No moves needed");
		} else
			for (maxn = 1; maxn <= 200; maxn++)
				if (dfs(0)) {
					for (int i = 0; i < (int)ans.size(); i++)
						printf("%c", ans[i]);
					break;
				}
		printf("\n%d\n", num);
	}
}
