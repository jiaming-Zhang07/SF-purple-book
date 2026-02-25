#include<bits/stdc++.h>
using namespace std;
struct cell {
	int x, y;
	bool operator<(const cell&other)const {
		return tie(x, y) < tie(other.x, other.y);
	}
};
int ans[11][11][11];
using graph = set<cell>;
set<graph>poly[11];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
graph normalize(graph&g) {
	int minx = g.begin()->x, miny = g.begin()->y;
	for (auto x : g) {
		minx = min(x.x, minx);
		miny = min(x.y, miny);
	}
	graph ng;
	for (auto x : g) {
		ng.insert( cell{x.x - minx, x.y - miny});
	}
	return ng;
}
graph flip(graph x) {
	graph nx;
	for (auto c : x) {
		nx.insert(cell{c.x, -c.y});
	}
	nx = normalize(nx);
	return nx;
}
graph rotat(graph g) {
	graph ng;
	for (auto p : g)
		ng.insert(cell{p.y, -p.x});
	ng = normalize(ng);
	return ng;
}
void check(set<graph>&s, graph x) {
	graph nx = x;
	for (int i = 0; i < 4; i++) {
		if (s.count(nx))
			return;
		nx = rotat(nx);
	}
	nx = flip(nx);
	for (int i = 0; i < 4; i++) {
		if (s.count(nx))
			return;
		nx = rotat(nx);
	}
	s.insert(x);
}
void ge() {
	graph t;
	t.insert(cell{0, 0});
	poly[1].insert(t);
	for (int n = 2; n <= 10; n++) {
		for (auto x : poly[n - 1]) {
			for (auto dot : x) {
				for (int i = 0; i < 4; i++) {
					graph ng = x;
					int nx = dot.x + dx[i], ny = dot.y + dy[i];
					if (x.count(cell{nx, ny} ) == 0) {
						ng.insert(cell{nx, ny});
						check(poly[n], normalize(ng));
					}
				}
			}
		}
	}
	for (int n = 1; n <= 10; n++)
		for (int w = 1; w <= 10; w++)
			for (int h = 1; h <= 10; h++) {
				for (auto x : poly[n]) {
					int maxx = x.begin()->x, maxy = x.begin()->y;
					for (auto c : x) {
						maxx = max(maxx, c.x);
						maxy = max(maxy, c.y);
					}if(max(maxx,maxy)<max(w,h)&&min(maxx,maxy)<min(w,h))ans[n][w][h]++;
				}
			}
}
int main() {
	ge();
	int n, w, h;
	while (scanf("%d%d%d", &n, &w, &h) == 3) {
		printf("%d\n", ans[n][w][h]);
	}
}
