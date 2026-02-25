#include<bits/stdc++.h>
using namespace std;
set<int,greater<int>> s;
int n;
int h() {
	int t = *s.begin();
	int cnt = 0;
	while (t < n) {
		t *= 2;
		cnt++;
	}
	return cnt;
}
bool dfs(int d, int maxd, int m) {
	if (m == n)
		{cout<<d<<endl;
		return true;
	}
	if (h() > maxd - d||d==maxd)
		return false;
	for (auto x : s) {
		int have=0;if(s.count(m+x))have=1;
		else s.insert(m + x);
		if (dfs(d + 1, maxd, m + x))
			return true;
		if(!have)
		s.erase(m + x);
		if(m-x<=0)continue;
		 have=0;
		if(s.count(m-x))have=1;else s.insert(m - x);
		if (dfs(d + 1, maxd, m - x))
			return true;
		if(!have)
		s.erase(m - x);
	}return false;
}
int main() {
	while (cin >> n && n) {
		
		for (int maxd = 0;; maxd++)
			{s.clear();s.insert(1);
			if (dfs(0, maxd,1)) break;
		}
	}
}
