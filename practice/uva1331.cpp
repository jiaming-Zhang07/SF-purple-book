#include <bits/stdc++.h>
using namespace std;
vector<double> x(55), y(55);
double d[55][55];
const double eps = 1e-10, INF = 1e15;
int m;
int dcmp(double x) {
  if (abs(x) < eps)
    return 0;
  return x < 0 ? -1 : 1;
}
double cross(int i, int k, int j) {
  return (x[k] - x[i]) * (y[j] - y[i]) - (y[k] - y[i]) * (x[j] - x[i]);
}
double dot(int i, int k, int j) {
  return (x[k] - x[i]) * (x[j] - x[i]) + (y[k] - y[i]) * (y[j] - y[i]);
}
bool onsegment(int k, int i, int j) {
  return dcmp(cross(k, i, j)) == 0 && dcmp(dot(k, i, j)) <= 0;
}
bool intersect(int k, int k2, int i, int j) {
  return dcmp(cross(k, k2, i)) * dcmp(cross(k, k2, j)) < 0 && dcmp(cross(i, j, k)) * dcmp(cross(i, j, k2)) < 0;
}
bool inside(double x1, double y1) {
  x.push_back(x1);
  y.push_back(y1);
  int k = x.size() - 1;
  int wn = 0;
  for (int i = 0; i < m; i++) {
    int j = (i + 1) % m;
    if (onsegment(k, i, j))
      return false;
    int d1 = y[i] - y[k], d2 = y[j] - y[k];
    if (dcmp(cross(i, j, k)) < 0 && d1 >= 0 && d2 < 0)
      wn++;
    if (dcmp(cross(i, j, k)) > 0 && d1 < 0 && d2 >= 0)
      wn--;
  }
  if (wn == 0)
    return false;
  else
    return true;
}
bool isdiag(int i, int j) {
  for (int k = 0; k < m; k++)
    if (k != i && k != j && onsegment(k, i, j))
      return false;
  for (int k = 0; k < m; k++) {
    int k2 = (k + 1) % m;
    if (intersect(k, k2, i, j))
      return false;
  }
  if (!inside((x[i] + x[j]) / 2, (y[i] + y[j]) / 2))
    return false;
  return true;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> m;
    for (int i = 0; i < m; i++)
      cin >> x[i] >> y[i];
    for (int i = m - 2; i >= 0; i--)
      for (int j = i + 1; j < m; j++) {
        if (i == j - 1) {
          d[i][j] = 0;
          continue;
        }
        if (!(i == 0 && j == m - 1) && !isdiag(i, j)) {
          d[i][j] = INF;
          continue;
        }
        d[i][j] = INF;
        for (int k = i + 1; k < j; k++)
          d[i][j] = min(d[i][j], max({d[i][k], d[k][j], abs(cross(i, k, j)) / 2}));
      }
    printf("%.1f\n", d[0][m - 1]);
  }
  return 0;
}