#include <bits/stdc++.h>
using namespace std;
struct dot {
  int x, y, z;
} d[20005];
using ll = long long;
int dx[] = {1, 1, 0, -1, -1, 0};
int dy[] = {-1, 0, 1, 1, 0, -1};
int dz[] = {0, -1, -1, 0, 1, 1};
int cur = 2, k = 1;
void move(int dir, int k) {
  for (int i = 0; i < k; i++) {
    d[cur] = {d[cur - 1].x + dx[dir], d[cur - 1].y + dy[dir], d[cur - 1].z + dz[dir]};
    cur++;
  }
}
int main() {
  int a, b;
  d[1] = {0, 0, 0};
  while (cur <= 10001) {
    move(0, 1);
    move(1, k - 1);
    for (int i = 2; i <= 5; i++)
      move(i, k);
    move(0, k);
    k++;
  }
  while (cin >> a >> b && a) {
    printf("The distance between cells %d and %d is %d.\n", a, b, max({abs(d[a].x - d[b].x), abs(d[a].y - d[b].y), abs(d[a].z - d[b].z)}));
  }
  return 0;
}
