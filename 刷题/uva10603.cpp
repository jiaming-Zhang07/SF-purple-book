#include<bits/stdc++.h>
using namespace std;
int ans[250];
struct state {
	int a[3],  sum;
};
void update(state st) {
	for (int i = 0; i < 3; i++)
		if (st.sum < ans[st.a[i]] || ans[st.a[i]] == -1)
			ans[st.a[i]] = st.sum;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {memset(ans,-1,sizeof(ans));
		int a[3], d;
		map<pair<int,int>,int>s;
		scanf("%d%d%d%d", &a[0], &a[1], &a[2], &d);
		queue<state>q;
		q.push(state{{0, 0, a[2]},0});
		s[{0,0}]=0;
		while (!q.empty()) {
			state st = q.front();
			q.pop();
			update(st);
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					if (i != j && st.a[i] && st.a[j] < a[j]) {
						state st2=st;
						if (st.a[i] < a[j] - st.a[j]) {
							st2.a[i] = 0;
							st2.a[j] = st.a[j] + st.a[i];
							st2.sum = st.sum + st.a[i];
						} else {
							st2.a[i] = st.a[i] - (a[j] - st.a[j]);
							st2.a[j] = a[j];
							st2.sum = st.sum + a[j] - st.a[j];
						}
						if (!s.count({st2.a[0],st2.a[1]})||(s.count({st2.a[0],st2.a[1]})&&st2.sum<s[{st2.a[0],st2.a[1]}])) {
							s[{st2.a[0],st2.a[1]}]=st2.sum;
							q.push(st2);
						}
					}
		}while(d>=0){if(ans[d]>=0){printf("%d %d\n",ans[d],d);break;}d--;}
	}
}
