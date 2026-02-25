#include<bits/stdc++.h>
using namespace std;
struct state {
	int cnt, r, c;
	array<array<int, 3>, 3>a;
};
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
int main() {set<array<array<int, 3>, 3>>se;
	state s;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			cin >> s.a[i][j];
			if (s.a[i][j] == 0) {
				s.r = i;
				s.c = j;
			}
		}se.insert(s.a);
	queue<state>q;
	q.push(s);
	array<array<int, 3>, 3>ans;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> ans[i][j];
try	{
		while (!q.empty()) {
			state st = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
				if (st.r + dr[i] > 2 || st.r + dr[i] < 0 || st.c + dc[i] > 2 || st.c + dc[i] < 0)
					continue;
			else {array<array<int, 3>, 3>temp=st.a;
				swap(temp[st.r + dr[i]][st.c + dc[i]], temp[st.r][st.c]);
				if(se.count(temp))continue;
				se.insert(temp);
				if(temp==ans){printf("%d",st.cnt+1);throw 1;}
				q.push(state{st.cnt + 1, st.r + dr[i], st.c + dc[i], temp});
			}
		}printf("-1");
	}catch(int e){}
	
}
