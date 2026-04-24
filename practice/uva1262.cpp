#include <bits/stdc++.h>
using namespace std;
using ll = long long;
char a[6][6], b[6][6];
vector<vector<char>> col(6, vector<char>(6));
int cnt[5];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < 6; i++)
      cin >> a[i];
    for (int i = 0; i < 6; i++)
      cin >> b[i];
    for (int j = 0; j < 5; j++) {
      col[j].resize(6);
      for (int i = 0; i < 6; i++)
        col[j][i] = a[i][j];
      sort(col[j].begin(), col[j].end());
      col[j].erase(unique(col[j].begin(), col[j].end()), col[j].end());
      for (int i = 0; i < col[j].size();) {
        bool ok = false;
        for (int k = 0; k < 6; k++)
          if (b[k][j] == col[j][i]) {
            ok = true;
            break;
          }
        if (!ok) {
          col[j].erase(col[j].begin() + i);
        } else
          i++;
      }
    }
    for (int i = 0; i < 5; i++) {
      cnt[i] = 1;
      for (int j = i + 1; j < 5; j++)
        cnt[i] *= col[j].size();
    }
    if (col[0].size() * cnt[0] < n)
      cout << "NO\n";
    else {
      for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 6; i++)
          if (cnt[j] >= n) {
            cout << col[j][i];
            break;
          } else
            n -= cnt[j];
      }
      cout << "\n";
    }
  }
  return 0;
}